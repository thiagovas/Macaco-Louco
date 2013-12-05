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

using namespace std;


class Control{
private:
	bool PCWriteCond,PCWrite,MemINSTRead,MemINSTWrite;
	bool IRWrite,MemRead1,MemRead2,MemWrite1,MemWrite2;
	bool PCSource,MemDest,AddresControl,ALUop,ALUSrcB,ALUSrcA;
	int Cicle;
	vector<bool> OPcode;

public:
	Control();
	~Control();

	void setcicle(int);
	void do_your_job();

	/*FETCH*/
	void fetch();
	/*BUSCA REGISTRADORES*/
	void busca_reg();
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
	void void conclui_jumpr();


};



#endif
