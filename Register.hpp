#ifndef _Register_hpp
#define _Register_hpp


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
	PC = 0;
	A" = 1;
	B" = 2;
	C" = 3; 
	D" = 4;
	ALUout1" = 5;
	ALUout2" = 6;

*/
class Register
{
	private:
		vector<vector<bool> > reg;
		map<string, int> table;
		int size; //Numero de bits que um registrador guarda
		bool controlSign;
	public:
		Register();
		~Register();
		void SetValue(string, vector<bool>);
		vector<bool> GetValue(string);
		void UpdateSign(bool); // Seta o sinal do controle que permite a escrita no registrador
		void print(string);
};

#endif
