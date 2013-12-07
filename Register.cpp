#include "Register.hpp"

Register::Register()
{
	this->size = 16; //Numero de bits que um registrador guarda
	this->controlSign = true; // O sinal padrão é true pq esta classe é utilizada para todos os registradores incluindo o PC.
	reg.resize(7, vector<bool>(size, false));
	table["PC"] = 0;
	table["A"] = 1;
	table["B"] = 2;
	table["C"] = 3;
	table["D"] = 4;
	table["ALUout1"] = 5;
	table["ALUout2"] = 6;
}

Register::~Register()
{
	reg.clear();
}

void Register::SetValue(string index, vector<bool> value)
{

	std::stringstream message;
	message << "Registradores guardam no máximo " << this->size << " bits.\n";
	
	if(!this->controlSign && index == "PC"){
		cout << "Dentro da Funcao\n";
		return;
	}

	if(value.size() > this->size) cout << message.str();
	if(table.find(index) == table.end()) cout << "Endereço inválido de registrador2.\n";	
	
	int tam;
	tam = this->size;
	vector<bool> data = value;
	if(value.size() != tam)
	{
		for(int i = value.size(); i < tam; i++)
			data.push_back(false);	
	}
	reg[table[index]] = data;
}

vector<bool> Register::GetValue(string index)
{	
	return reg[table[index]];
}

void Register::UpdateSign(bool sign)
{
	this->controlSign = sign;
}

void Register::print(string index){
	for(int i  = reg[table[index]].size()-1  ; i >= 0 ; i-- ){
		cout << reg[table[index]][i]; 
	}
	cout << endl;
}