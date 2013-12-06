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

	fData.open(argv[1]);
	fInstructions.open(argv[2]);
	fOutput.open(argv[3], std::fstream::out);
	
	im.Init(fInstructions);
	dm.Init(fData);

	controle.SetStage(0);
	while(true){
		controle.do_your_job();
		controle.go_my_children_i_free_you(alu1,alu2,im,dm);

		if(controle.GetStage == 0){

		}else if(controle.GetStage == 1){

		}else if(controle.GetStage == 2){

		}else if(controle.GetStage == 3){

		}else if(controle.GetStage == 4){

		}else if(controle.GetStage == 5){

		}else if(controle.GetStage == 6){

		}else if(controle.GetStage == 7){

		}
	}
	
	
	
	/* Finalizando tudo. Fechando streams e limpando tudo. */
	fData.close();
	fInstructions.close();
	fOutput.close();

	return 0;
}

