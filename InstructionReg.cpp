#include "InstReg.hpp"

InstReg::InstReg()
{
	size = 18; //Numero de bits que um registrador guarda
	reg.resize(18,false);

}

InstReg::~InstReg()
{
	reg.clear();
	size = 0;
}

void InstReg::SetValue(vector<bool> value)
{
	std::stringstream message;
	message << "Registradores guardam no máximo " << size << " bits.\n";
	
	if(index.size() != 3) throw "Endereço inválido de registrador.";
	if(value.size() > size) throw message.str();
	if(table.find(index) == table.end()) throw "Endereço inválido de registrador.";	
	
	vector<bool> data = value;
	if(value.size() != size)
	{
		for(int i = value.size(); i < size; i++)
			data.push_back(false);	
	}
	reg[table[index]] = data;
}

vector<bool> InstReg::GetValue(string index)
{
	if(index.size() != 3) throw "Endereço inválido de registrador.";
	
	return reg[table[index]];
}
