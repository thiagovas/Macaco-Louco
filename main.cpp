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
#include "Adder.hpp"
#include <fstream>
using namespace std;


int main(int argc, char *argv[])
{
	// ios::sync_with_stdio(false);
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
	Adder ad;

	cte[0] = true;

	fData.open(argv[1]);
	fInstructions.open(argv[2]);
	fOutput.open(argv[3], std::fstream::out);
	
	im.Init(fInstructions);
	dm.Init(fData);

	controle.SetStage(0);

	int inst_num = 0;
dm.Print(fOutput);
	while(inst_num < 3){
		controle.do_your_job();
		controle.go_my_children_i_free_you(alu1,alu2,im,dm,regs,ir,muxpcsource,muxmemdest,muxaddrescontrol,muxalusrca,muxalusrcb);
controle.print();
		/*PEGA INSTRUÇÃO NA MEMÓRIA E PASSADO PARA O REGISTRADOR DE INSTRUÇÕES*/
		ir.SetValue( im.get_instruction( regs.GetValue("PC") ) );

// regs.print("A");
// regs.print("B");
// regs.print("C");
// regs.print("D");
		regs.SetValue( "A",dm.GetValue(ir.get_rs()) );
		regs.SetValue( "B",dm.GetValue(ir.get_rt()) );
		regs.SetValue( "C",dm.GetValue( ad.SumOne( ir.get_rs() ) ) );
cout << "PAssou\n";
		regs.SetValue( "D",dm.GetValue( ad.SumOne( ir.get_rt() ) ) );
// regs.print("PC");
// regs.print("A");
// regs.print("B");
// regs.print("C");
// regs.print("D");

		/*COLOCA INPUTS PARA O MUX ALUSrcA*/
		muxalusrca.SetInput( regs.GetValue("PC") , regs.GetValue("A") );
// muxalusrca.print();
		
		/*COLOCA INPUTS PARA O MUX ALUSrcB*/
		muxalusrcb.SetInput( regs.GetValue("B") , cte );
// muxalusrcb.print();

		/*INICIALIZA AS ALUs  E FAZ SUAS OPERAÇÕES*/
		alu1.setvalues(muxalusrca.GetOutput(),muxalusrcb.GetOutput());
		alu2.setvalues(regs.GetValue("C"),regs.GetValue("D"));
		alu1.do_operation();
alu1.print();
		alu2.do_operation();
alu2.print();
		/*PASSA VALOR AO REGISTRADOR ALUOUT1*/
		regs.SetValue( "ALUout1", alu1.result_value() );

		/*PASSA VALOR AO REGISTRADOR ALUOUT2*/
		regs.SetValue( "ALUout2", alu2.result_value() );

		/*INCLUI INCLUDES PARA O MEMDest (REPARE QUE O CTE NUNCA PODERÁ SER USADO)*/
		muxmemdest.SetInput(ir.get_rs(),ir.get_rt(),ir.get_rd(),cte);
		/*INCLUI INPUTS PARA O AddressControl*/
		muxaddrescontrol.SetInput( ir.get_immed5() , regs.GetValue("ALUout1") , ir.get_immed10() , cte );

// cout << "MEMdest : ";		
// muxmemdest.print();
// muxaddrescontrol.print();
		/*GUARDA NA RESPECTIVA POSIÇÃO O DADO ESPECIFICADO*/
		dm.SetValue(muxmemdest.GetOutput(), muxaddrescontrol.GetOutput() );
		dm.SetValue2( ad.SumOne(ir.get_rd() ) , regs.GetValue("ALUout2") );


		/*INCLUI AS ENTRADAS AO PCSource E USA SEU OUTPUT PARA SETAR O PC*/
		muxpcsource.SetInput(alu1.result_value(),ir.get_immed5(),ir.get_immed15(),regs.GetValue("A"));
		regs.SetValue("PC",muxpcsource.GetOutput());
cout << "Novo pc: ";
regs.print("PC");
		/*PASSA PARA O PRÓXIMO ESTÁGIO*/
		controle.next_stage();
		
		inst_num++;
		
	}
	
	dm.Print(fOutput);
	
	/* Finalizando tudo. Fechando streams e limpando tudo. */
	fData.close();
	fInstructions.close();
	fOutput.close();

	return 0;
}


