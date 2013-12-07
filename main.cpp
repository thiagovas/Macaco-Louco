#include <iostream>
#include <utility>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <cmath>
#include <cstdlib>
#include <cstdio>
#include <cctype>
#include <string>
#include <deque>
#include "InstructionMemory.hpp"
#include "DataMemory.hpp"
#include "Control.hpp"
#include "ALU.hpp"
#include "Register.hpp"
#include "InstructionReg.hpp"
#include "Mux.hpp"
#include <fstream>
using namespace std;

int main(int argc, char *argv[])
{
	ios::sync_with_stdio(false);
	if(argc != 4)
	{
		cout << "Siga o padrão: ./<exec> <Arquivo com dados> <Arquivo com instruções> <Arquivo de saida>" << endl;
		return 1;
	}
	
	ifstream fData, fInstructions;
	fstream fOutput;
	InstructionMemory im;
	DataMemory dm;
	Register regs;
	Control controle;
	Alu alu1,alu2;
	InstReg ir;
	Mux muxpcsource,muxmemdest,muxaddrescontrol,muxalusrca,muxalusrcb;
	vector<bool> cte (16,false);
	cte[1] = true;
	cte[4] = true;

	fData.open(argv[1]);
	fInstructions.open(argv[2]);
	fOutput.open(argv[3], std::fstream::out);
	
	im.Init(fInstructions);
	dm.Init(fData);

	controle.SetStage(0);
	while(true){
		controle.do_your_job();
		controle.go_my_children_i_free_you(alu1,alu2,im,dm,regs,ir,muxpcsource,muxmemdest,muxaddrescontrol,muxalusrca,muxalusrcb);

		/*PEGA INSTRUÇÃO NA MEMÓRIA E PASSADO PARA O REGISTRADOR DE INSTRUÇÕES*/
		ir.SetValue( im.get_instruction( regs.GetValue("PC") ) );


		regs.SetInput( "A",dm.GetValue(ir.get_rs()) );
		regs.SetInput( "B",dm.GetValue(ir.get_rt()) );
		regs.SetInput( "C",dm.GetValue(/*ir.get_rs()+1*/) );
		regs.SetInput( "D",dm.GetValue(/*ir.get_rt())+1*/ );

		/*COLOCA INPUTS PARA O MUX ALUSrcA*/
		muxalusrca.SetInput( regs.GetValue("PC") , regs.GetValue("A") );
		
		/*COLOCA INPUTS PARA O MUX ALUSrcB*/
		muxalusrcb.SetInput( regs.GetValue("B") , cte );


		/*INICIALIZA AS ALUs  E FAZ SUAS OPERAÇÕES*/
		alu1.set_values(muxalusrca.GetOutput(),muxalusrcb.GetOutput());
		// alu2.set_values(ir.get_rs(),ir.get_rt());
		alu1.do_operation();
		// alu2.do_operation();

		/*PASSA VALOR AO REGISTRADOR ALUOUT1*/
		regs.SetInput( "ALUout1", alu1.result_value() );

		/*PASSA VALOR AO REGISTRADOR ALUOUT2*/
		regs.SetInput( "ALUout2", alu2.result_value() );

		/*INCLUI INCLUDES PARA O MEMDest (REPARE QUE O CTE NUNCA PODERÁ SER USADO)*/
		muxmemdest.SetInput(ir.get_rs(),ir.get_rt(),ir.get_rd(),cte);
		/*INCLUI INPUTS PARA O AddressControl*/
		muxaddrescontrol.SetInput();
		im.SetValue(muxmemdest.GetOutput(), muxaddrescontrol.GetOutput() );


		/*INCLUI AS ENTRADAS AO PCSource E USA SEU OUTPUT PARA SETAR O PC*/
		muxpcsource.SetInput(alu1.result_value(),ir.get_immed5(),ir.get_immed15(),regs.GetValue("A"));
		regs.SetValue("PC",muxpcsource.GetOutput());



	}
	
	
	
	/* Finalizando tudo. Fechando streams e limpando tudo. */
	fData.close();
	fInstructions.close();
	fOutput.close();

	return 0;
}

