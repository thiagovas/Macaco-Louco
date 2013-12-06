// Made By: Marcelo
// Revised by: ? 
// NOT READY YET

#ifndef _Control_hpp
#define _Control_hpp

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <utility>
#include <functional>
#include <iomanip>
#include <string>
#include <cstring>
#include <vector>
#include <utility>
#include "ALU.hpp"
#include "DataMemory.hpp"
#include "InstructionMemory.hpp"
#include "Register.hpp"

using namespace std;


class Control{
private:
	bool PCWriteCond,PCWrite,MemINSTRead,MemINSTWrite;
	bool IRWrite,MemRead1,MemRead2,MemWrite1,MemWrite2;
	bool ALUSrcB,ALUSrcA;
	pair<bool,bool> ALUOp,AddressControl,PCSource,MemDest;
	int Stage;
	vector<bool> OPcode;

public:
	Control();
	~Control();

	void setstage(int);

	/*EXECUTA O QUE PRECISAR DADO O CICLO*/
	void do_your_job();

	/*FETCH*/
	void fetch();
	/*BUSCA REGISTRADORES*/
	void busca_reg(vector<bool>);
	/*EXECUÇÃO*/
	void executa();
	/*CONCLUSÃO DE TIPO R*/
	void conclui_r();
	/*TÉRMINO DO LOAD IMMEDIATE*/
	void conclui_loadi();
	/*VERIFICA BRANCH*/
	void branch();
	/*CONCLUSÃO JUMP*/
	void conclui_jump();
	/*CONCLUSÃO JUMPR*/
	void conclui_jumpr();

	int next_stage(vector<bool>,int);

	void go_my_children_i_libert_you(Alu &, Alu &, InstructionMemory & , DataMemory & );

};



#endif
