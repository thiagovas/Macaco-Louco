/*
	Author: Guilherme Vieira Leobas
	Version: 1.0b
*/


#ifndef InstructionMemory_hpp
#define InstructionMemory_hpp

#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <sstream>
#include <fstream>
#include <bitset>

using namespace std;

class InstructionMemory {
	/* VARIAVEIS:
	*  vector<vector<bool> > iMemory = Memória de Instruções;
	*  map<string, string> table = Mapeia todas as combinações de instruções para string;
	*  bool MemINSTRead = Sinal enviado pelo controle para permissão de leitura;
	*  size_t inst_size = Quantidade de instruções na memória;
	*/

private:
	vector<vector<bool> > iMemory;
	map<string, string> table;
	bool MemINSTRead;
	size_t inst_size;
public:
	InstructionMemory ();
	~InstructionMemory ();

	void imprime ();
	
	/*
	* Função: Seta o sinal do controle de leitura para "TRUE" ou "FALSE";
	* Parâmetro(s): Nenhum;
	* Return: Nenhum;
	* Observações: As I said, o controle que se vire com esses sinais.
	*/
	void update_signal (bool signal);
	
	/*
	* Função: Retorna uma instrução da memória;
	* Parâmetro(s): Inteiro informando a posição;
	* Return: vector<bool> com 18 posições contendo a instrução;
	* Observações: Se a posição for invalida ou se a posição a ser lida for maior que 32, um Warning é lançado na tela.
	*/
	vector<bool> get_instruction (int PC);
	
	/*
	* Função: Retorna o opcode formatado em uma string;
	* Parâmetros(s): Posição da memória de instruções;
	* Return: Uma string contendo o opcode;
	* Observações: O sinal de leitura enviado pelo controle deve está setado como TRUE!
	*/
	string get_opcode_formatted (int PC);

	/*
	* Função: Retorna os bits delimitados por[lower, upper] da posição indicada por "pos";
	* Parâmetros(s): Três inteiros indicando respectivamente o limite inferior, limite superior e a posição a ser lida;
	* Return: Um vector<bool> contendo os bits;
	* Observações: Nenhum;
	*/
	vector<bool> get_bits (int lower, int upper, int PC);

	/*
	* Função: Retorna a instrução formatada.
	* Parâmetros(s): A posição da memória de dados;
	* Return: Um vector<vector<bool>> contendo a instrução formatada;
	* Observações: Nenhum;
	*/
	vector<vector<bool> > get_instruction_formatted (int PC);
	
	/*
	* Função: Retorna o opode da instrução;
	* Parâmetro(s): Posição (inteiro). Lembrando que a memória anda de 18 em 18 bits.
	* Return: Vector<bool> contendo os três bits do opcode (saída está especificada no README.md);
	* Observações: Se a posição lida não for uma posição valida, o programa lança um warning!
	*/
	vector<bool> get_opcode (int PC);
	
	/* 
	* Função: Inicializa a memória de instruções;
	* Parâmetro(s): Arquivo de entrada.
	* Return: Nenhum;
	* Observações: Mantém na variavel "inst_size" a quantidade de instruções lidas
		* Se "inst_size" > 32, código lança um Warning e para de ler do arquivo;
	*/
	void Init (ifstream &input);

	/*
	* Função: F
	* Parâmetro(s): 
	* Return: 
	* Observações: 
	*/
	bool come_back_cracken (int PC);
};

/*
* Função: Converte um inteiro para uma string contendo a conversão do inteiro para sua respectiva
		  representação em binario;
* Parâmetro(s): Um inteiro que será convertido e o tamanho em base 10;
* Return: Uma string com a representação do inteiro em binario.
* Observações: O bit mais significativo é o ultimo caractere;
*/
string int_to_bitstring (int label, int size);

/*
* Função: Inverte uma string;
* Parâmetro(s): A string;
* Return: A string invertida (dahh!);
* Observações: Nenhum;
*/
string invert (string s);

#endif