#include "Register.hpp"

Register::Register()
{
	this->size = 16; //Numero de bits que um registrador guarda
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
	
	if(index.size() != 3) throw "Endereço inválido de registrador.";
	if(value.size() > this->size) throw message.str();
	if(table.find(index) == table.end()) throw "Endereço inválido de registrador.";	
	
	vector<bool> data = value;
	if(value.size() != this->size)
	{
		for(int i = value.size(); i < this->size; i++)
			data.push_back(false);	
	}
	reg[table[index]] = data;
}

vector<bool> Register::GetValue(string index)
{
	if(index.size() != 3) throw "Endereço inválido de registrador.";
	
	return reg[table[index]];
}
