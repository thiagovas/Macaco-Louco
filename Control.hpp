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
#include <utitlity>
#include "ALU.hpp"
#include "DataMemory.hpp"
#include "InstructionMemory.hpp"
#include "Register.hpp"

using namespace std;


class Control{
private:
	bool PCWriteCond,PCWrite,MemINSTRead,MemINSTWrite;
	bool IRWrite,MemRead1,MemRead2,MemWrite1,MemWrite2;
	bool MemDest,ALUSrcB,ALUSrcA;
	pair<bool,bool> ALUop,AddresControl,PCSource;
	int Stage;
	vector<bool> OPcode;

public:
	Control();
	~Control();

	void setcicle(int);

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

	int next_stage(OPcode,Ciclo);

	void Control::go_my_children_i_libert_you(Alu &, Alu &, Alu &, InstructionMemory & , DataMemory & );

};



#endif
