#ifndef _InstructionReg_hpp
#define _InstructionReg_hpp


#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <map>
#include <algorithm>
#include <utility>
#include <functional>
#include <iomanip>
#include <string>
#include <sstream>
using namespace std;


/* Classe registrador
*	Ela possui uma matriz com sete linhas, ou seja, uma linha para cada registrador que existe em nosso datapath.
	[0] = PC
	[1] = 
*/
class InstReg
{
	private:
		vector<bool> reg;
		int size; //Numero de bits que um registrador guarda
	public:
		Register();
		~Register();
		void SetValue(string, vector<bool>);
		vector<bool> GetValue(string);
};

#endif
