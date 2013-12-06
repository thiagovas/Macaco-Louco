// This memory keeps the instructions

/*
	Author: Guilherme Vieira Leobas
	Version: 1.0b
*/

#include "InstructionMemory.hpp"
#include <string>

/*
* Função: Constructor da classe;
* Parâmetro(s): Nenhum;
* Return: Nenhum;
* Observações: Nenhum;
*/
InstructionMemory::InstructionMemory (){
	iMemory.resize (32, vector<bool> (18, false));
	table["ADD"] = "000";
	table["SUB"] = "001";
	table["AND"] = "010";
	table["OR"] = "011";
	table["LWI"] = "100";
	table["BNE"] = "101";
	table["J"] = "110";
	table["JR"] = "111";

	table["M0"] = "00000";
	table["M1"] = "00001";
	table["M2"] = "00010";
	table["M3"] = "00011";
	table["M4"] = "00100";
	table["M5"] = "00101";
	table["M6"] = "00110";
	table["M7"] = "00111";
	table["M8"] = "01000";
	table["M9"] = "01001";
	table["M10"] = "01010";
	table["M11"] = "01011";
	table["M12"] = "01100";
	table["M13"] = "01101";
	table["M14"] = "01110";
	table["M15"] = "01111";
	table["M16"] = "10000";
	table["M17"] = "10001";
	table["M18"] = "10010";
	table["M19"] = "10011";
	table["M20"] = "10100";
	table["M21"] = "10101";
	table["M22"] = "10110";
	table["M23"] = "10111";
	table["M24"] = "11000";
	table["M25"] = "11001";
	table["M26"] = "11010";
	table["M27"] = "11011";
	table["M28"] = "11100";
	table["M29"] = "11101";
	table["M30"] = "11110";
	table["M31"] = "11111";

	MemINSTRead = false;
	inst_size = 0;
}

/*
* Função: Destructor da classe InstructionMemory;
* Parâmetro(s): Nenhum;
* Return: Nenhum; 
* Observações: Nenhum;
*/
InstructionMemory::~InstructionMemory (){
	iMemory.clear();
	table.clear();
}

/*
* Função: Imprime o conteúdo da memória.
* Parâmetro(s): Nenhum;
* Return: Nenhum;
* Observações: Apenas para debugar;
*/
void InstructionMemory::imprime (){
	for (int i = 0; i < iMemory.size(); i++){
		for (int j = iMemory[i].size()-1; j >=0; j--){
			cout << iMemory[i][j];
			if (j == 5 || j == 10 || j == 15) cout << ' ';
		}
		cout << endl;
	}
	cout << endl;
}

/*
* Função: Seta o sinal do controle de leitura para "TRUE";
* Parâmetro(s): Nenhum;
* Return: Nenhum;
* Observações: As I said, o controle que se vire com esses sinais.
*/
void InstructionMemory::set_signal (){
	MemINSTRead = true;
}

/*
* Função: Reseta o sinal do controle para ler uma instrução;
* Parâmetro(s): Nenhum;
* Return: Nenhum;
* Observações: Nenhum. O controle que se vira com esse monte de sinal.
*/
void InstructionMemory::reset_signal (){
	MemINSTRead = false;
}

/*
* Função: Retorna uma instrução da memória;
* Parâmetro(s): Inteiro informando a posição;
* Return: vector<bool> com 18 posições contendo a instrução;
* Observações: Se a posição for invalida ou se a posição a ser lida for maior que 32, um Warning é lançado na tela.
*/
vector<bool> InstructionMemory::get_instruction (int pos){

	if (pos % 18 != 0) cout << "I'm sorry Dave, I'm afraid I can't do that\n";
	if (pos % 18 > inst_size) cout << "Are you stupid?\n";

	return iMemory[pos/18];
}

/*
* Função: Retorna o opode da instrução;
* Parâmetro(s): Posição (inteiro). Lembrando que a memória anda de 18 em 18 bits.
* Return: Vector<bool> contendo os três bits do opcode (saída está especificada no README.md);
* Observações: Se a posição lida não for uma posição valida, o programa lança um warning!
*/

vector<bool> InstructionMemory::get_opcode (int pos){

	if (pos % 18 != 0) cout << "I already told you Dave, I can't do that!!!\n";
	if (pos % 18 > inst_size) cout << "I give up!\n";

	vector<bool> opcode (3, false);

	for (int i=15; i<18; i++){
		if (iMemory[pos/18][i]) opcode[i-15] = true;
		else opcode[i-15] = false;
	}

	return opcode;
}

/* 
* Função: Inicializa a memória de instruções;
* Parâmetro(s): Arquivo de entrada.
* Return: Nenhum;
* Observações: Mantém na variavel "inst_size" a quantidade de instruções lidas
	* Se "inst_size" > 32, código lança um Warning e para de ler do arquivo;
*/
void InstructionMemory::init (ifstream &input){

	if (!input.is_open ()){
		cout << "Oh crap!\n";
	}

	string dest, reg1, reg2, op, binary;
	int label, line;

	line = 0;

	while (true){
		input >> op;

		if (!input) break;

		binary.clear();

		if (op == "ADD" || op == "SUB" || op == "AND" || op == "OR"){
			input >> dest >> reg1 >> reg2;
			binary += invert(table[dest]) + invert(table[reg2]) + invert(table[reg1]) + invert(table[op]);
		}
		else  if (op == "LWI"){
			input >> reg1 >> label;
			binary += invert(int_to_bitstring (label, 10)) + invert(table[reg1]) + invert(table[op]);
		}
		else if (op == "BNE"){
			input >> reg1 >> reg2 >> label;
			binary += invert(int_to_bitstring (label, 10)) + invert(table[reg2]) + invert(table[reg1]) + invert(table[op]);
		}
		else if (op == "J"){
			input >> label;
			binary += invert(int_to_bitstring (label, 10)) + "00000" + invert(table[op]);
		}
		else {
			// JR;
			input >> dest;
			binary += invert(table[dest]) + "000000000" + invert(table[op]);
		}

		for (int i = 0; i < 18; i++){
			if (binary[i] == '0') iMemory[line][i] = 0;
			else iMemory[line][i] = 1;
		}

		line++;
		inst_size++;

		if (inst_size > 32){
			cout << "Por algum motivo obscuro a memoria esta cheia, ajuste esse caso de teste!\n";
			return;
		}
	}

}

/*
* Função: Converte um inteiro para uma string contendo a conversão do inteiro para sua respectiva
		  representação em binario;
* Parâmetro(s): Um inteiro que será convertido e o tamanho em base 10;
* Return: Uma string com a representação do inteiro em binario.
* Observações: O bit mais significativo é o ultimo caractere;
*/
string int_to_bitstring (int label, int size){
	
	int x = 1 << size-1;
	string binary;

	while (x){
		if (label&x) binary += '1';
		else binary += '0';
		x = x >> 1;
	}

	return binary;
}

/*
* Função: Inverte uma string;
* Parâmetro(s): A string;
* Return: A string invertida (dahh!);
* Observações: Nenhum;
*/
string invert (string s){
	string result;

	for (int i=s.size()-1; i>=0; i--){
		result += s[i];
	}

	return result;
}