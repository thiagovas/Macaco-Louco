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
		bool IRWrite;
	public:
		InstReg();
		~InstReg();

		/*
		* Função: Método que seta o valor do registrador de instrução
		* Parâmetro(s): Novo valor de instruction register
		* Return: Nenhum
		* Observações: O sinal IRWrite, que vem do controle, deve estar setado como true.
		*/
		void SetValue(vector<bool> value);
	
		/*
		* Função: Retorna o valor do opcode da instrução atual
		* Parâmetro(s): Nenhum
		* Return: Valor do opcode da instrução atual.
		* Observações: Nenhum
		*/
		vector<bool> get_opcode();
		
		/*
		* Função: Retorna o valor de rs da instrução atual.
		* Parâmetro(s): Nenhum
		* Return: O valor de rs da instrução atual.
		* Observações: Nenhum
		*/
		vector<bool> get_rs();
					
		/*
		* Função: Retorna o valor de rt da instrução atual.
		* Parâmetro(s): Nenhum
		* Return: O valor de rt da instrução atual.
		* Observações: Nenhum
		*/
		vector<bool> get_rt();
		
		/*
		* Função: Retorna o valor de rd da instrução atual.
		* Parâmetro(s): Nenhum
		* Return: O valor de rd da instrução atual.
		* Observações: Nenhum
		*/
		vector<bool> get_rd();
		
		/*
		* Função: Retorna o valor do imediato de uma instrução do tipo I
		* Parâmetro(s): Nenhum
		* Return: O imediato de uma instrução do tipo I
		* Observações: Nenhum
		*/
		vector<bool> get_immed5();
		
		/*
		* Função: Retorna o valor do imediato de uma instrução do tipo J
		* Parâmetro(s): Nenhum
		* Return: O imediato de ums instrução do tipo J
		* Observações: Nenhum
		*/
		vector<bool> get_immed10();
<<<<<<< HEAD
		
		/*
		* Função: Retorna os bits que estão no intervalo [lower, upper]
		* Parâmetro(s): Limites do intervalo [lower, upper]
		* Return: Um vector de bools que representam a sequencia de bits que está no intervalo [lower, upper]
		* Observações: lower não pode ser negativo e upper não pode ser maior que 17.
		*/
		vector<bool> get_bits (int lower, int upper);
		
		/*
		* Função: Atualiza o sinal que recebe do controle;
		* Parâmetro(s): Sinal que vem do controle;
		* Return: Nenhum;
		* Observações: Nenhum.
		*/
		void update_sign(bool);
=======
		vector<bool> get_immed15();
		vector<bool> get_bits (int,int);
>>>>>>> feaabcea8d179e1df8b50f7a81e4b08a220c90f9
};

#endif
