#ifndef _ALU_hpp
#define _ALU_hpp

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <utility>
#include <functional>
#include <iomanip>
#include <string>
#include <cstring>
#include <vector>

using namespace std;

// ALUop :	ADD  - 	000(0)
// 			SUB  - 	001(1)
// 			AND  -	010(2)
// 			OR   - 	011(3)


class Alu{

private:
int ALUop;
bool zero;
vector<bool> a;
vector<bool> b;
vector<bool> result;


public:
	
	// RECEBE VALORES DE A, B e OP
	void setvalues(vector<bool>,vector<bool>,bool,bool);

	// FAZ A OPERAÇÃO E RETORNA O RESULTADO
	void do_operation();

	// Soma bit a bit
	void sum();

	// Subtração bit a bit
	bool sub();

	// And bit a bit
	void alu_and();

	// Or bit a bit
	void alu_or();

	// RETORNA O RESULTADO
	vector<bool> result_value();

	// VERIFICA SE A 
	bool zero_value();

	//IMPRIME NUMERO
	void print();

};


/*
	class InstructionMemory {

	private:
		vector<vector<bool> > iMemory;
	public:
		InstructionMemory ();
		~InstructionMemory ();

		void init (fstream input);
	};

*/

#endif
