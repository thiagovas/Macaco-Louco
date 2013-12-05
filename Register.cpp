#include "Register.hpp"

Register::Register()
{
	this->size = 16; //Numero de bits que um registrador guarda
	reg.resize(7, vector<bool>(size, false));
	table["000"] = 0;
	table["001"] = 1;
	table["010"] = 2;
	table["011"] = 3; 
	table["100"] = 4;
	table["101"] = 5;
	table["110"] = 6;
	table["111"] = 7;
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

