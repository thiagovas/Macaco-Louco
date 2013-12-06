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
		ir.SetValue( im.get_instruction( regs.GetValue(string) ) );

		/*INICIALIZA AS ALUs  E FAZ SUAS OPERAÇÕES*/
		alu1.set_values(ir.get_rs(),ir.get_rt());
		// alu2.set_values(ir.get_rs(),ir.get_rt());
		alu1.do_operation();
		// alu2.do_operation();


		muxpcsource.SetInput(alu1.result_value(),ir.get_immed5(),);
		regs.SetValue("PC",)



	}
	
	
	
	/* Finalizando tudo. Fechando streams e limpando tudo. */
	fData.close();
	fInstructions.close();
	fOutput.close();

	return 0;
}

