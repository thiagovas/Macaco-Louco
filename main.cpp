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
	Register reg;
	Control controle;
<<<<<<< HEAD
<<<<<<< HEAD
	Alu alu1,alu2;
=======
    int instructionPos = 0;
>>>>>>> ef1c3201b3970924e2529b0e0e0cabdb475919bf
=======
    int instructionPos = 0;
	Alu alu1,alu2;
>>>>>>> b12dcc8638724e3e2a4fef39105ff837c4f5c52a

	fData.open(argv[1]);
	fInstructions.open(argv[2]);
	fOutput.open(argv[3], std::fstream::out);
	
	im.Init(fInstructions);
	dm.Init(fData);
	
	while(instructionPos < im.GetNumInstructions())
	{
		
	}

	/* Finalizando tudo. Fechando streams e limpando tudo. */
	fData.close();
	fInstructions.close();
	fOutput.close();

	return 0;
}

