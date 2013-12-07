#include "InstructionReg.hpp"

InstReg::InstReg(){

}

InstReg::~InstReg(){
	reg.clear();
}

/*
* Função: Método que seta o valor do registrador de instrução
* Parâmetro(s): Novo valor de instruction register
* Return: Nenhum
* Observações: O sinal IRWrite, que vem do controle, deve estar setado como true.
*/
void InstReg::SetValue(vector<bool> value){
	if(!IRWrite) throw "Wadafuck Nigga! U Canot do dat!";

	reg = value;	
}

/*
* Função: Retorna o valor do opcode da instrução atual
* Parâmetro(s): Nenhum
* Return: Valor do opcode da instrução atual.
* Observações: Nenhum
*/
vector<bool> InstReg::get_opcode(){
	return get_bits(15,17);
}

/*
* Função: Retorna o valor de rs da instrução atual.
* Parâmetro(s): Nenhum
* Return: O valor de rs da instrução atual.
* Observações: Nenhum
*/
vector<bool> InstReg::get_rs(){
	return get_bits(10,14);
}

/*
* Função: Retorna o valor de rt da instrução atual.
* Parâmetro(s): Nenhum
* Return: O valor de rt da instrução atual.
* Observações: Nenhum
*/
vector<bool> InstReg::get_rt(){
	return get_bits(5,9);
}

/*
* Função: Retorna o valor de rd da instrução atual.
* Parâmetro(s): Nenhum
* Return: O valor de rd da instrução atual.
* Observações: Nenhum
*/
vector<bool> InstReg::get_rd(){
	return get_bits(0,4);
}

/*
* Função: Retorna o valor do imediato de uma instrução do tipo I
* Parâmetro(s): Nenhum
* Return: O imediato de uma instrução do tipo I
* Observações: Nenhum
*/
vector<bool> InstReg::get_immed5(){
	return get_bits(0,4);
}

/*
* Função: Retorna o valor do imediato de uma instrução do tipo J
* Parâmetro(s): Nenhum
* Return: O imediato de ums instrução do tipo J
* Observações: Nenhum
*/
vector<bool> InstReg::get_immed10(){
	return get_bits(0,9);
}

vector<bool> InstReg::get_immed15(){
	return get_bits(0,14);
}

/*
* Função: Retorna os bits que estão no intervalo [lower, upper]
* Parâmetro(s): Limites do intervalo [lower, upper]
* Return: Um vector de bools que representam a sequencia de bits que está no intervalo [lower, upper]
* Observações: lower não pode ser negativo e upper não pode ser maior que 17.
*/
vector<bool> InstReg::get_bits (int lower, int upper){
	if (lower < 0 || upper > 17) throw "Limites errados!\n";

	vector<bool> bits (upper-lower+1, false);

	for (int i = lower; i <= upper; i++){
		if (reg[i]) bits[i-lower] = true;
	}

	return bits;
}

/*
* Função: Atualiza o sinal que recebe do controle;
* Parâmetro(s): Sinal que vem do controle;
* Return: Nenhum;
* Observações: Nenhum.
*/
void InstReg::update_sign(bool may_i){
	IRWrite = may_i;
}
