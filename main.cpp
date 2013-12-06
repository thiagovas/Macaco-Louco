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

	fData.open(argv[1]);
	fInstructions.open(argv[2]);
	fOutput.open(argv[3], std::fstream::out);
	
	im.Init(fInstructions);
	dm.Init(fData);
	
	
	
	/* Finalizando tudo. Fechando streams e limpando tudo. */
	fData.close();
	fInstructions.close();
	fOutput.close();

	return 0;
}

