#include "DataMemory.hpp"

// Construtor;
DataMemory::DataMemory()
{
	dMemory.resize (32, vector<bool> (16, false));
	table["00000"] = 0;
	table["00001"] = 1;
	table["00010"] = 2;
	table["00011"] = 3;
	table["00100"] = 4;
	table["00101"] = 5;
	table["00110"] = 6;
	table["00111"] = 7;
	table["01000"] = 8;
	table["01001"] = 9;
	table["01010"] = 10;
	table["01011"] = 11;
	table["01100"] = 12;
	table["01101"] = 13;
	table["01110"] = 14;
	table["01111"] = 15;
	table["10000"] = 16;
	table["10001"] = 17;
	table["10010"] = 18;
	table["10011"] = 19;
	table["10100"] = 20;
	table["10101"] = 21;
	table["10110"] = 22;
	table["10111"] = 23;
	table["11000"] = 24;
	table["11001"] = 25;
	table["11010"] = 26;
	table["11011"] = 27;
	table["11100"] = 28;
	table["11101"] = 29;
	table["11110"] = 30;
	table["11111"] = 31;
}

// Destrutor;
DataMemory::~DataMemory ()
{
	Clear();
	this->MemRead1 = false;
	this->MemRead2 = false;
	this->MemWrite1 = false;
	this->MemWrite2 = false;
}

void DataMemory::update_signal (bool MemRead1, bool MemRead2, bool MemWrite1, bool MemWrite2)
{
	this->MemRead1 = MemRead1;
	this->MemRead2 = MemRead2;
	this->MemWrite1 = MemWrite1;
	this->MemWrite2 = MemWrite2;
}

// Imprime;
void DataMemory::Print()
{
	for (int i = 0; i < dMemory.size(); i++){
		for (int j = 0; j < dMemory[i].size(); j++){
			cout << dMemory[i][j] << ' ';
		}
		cout << endl;
	}
	cout << endl;
}

void DataMemory::Clear()
{
	dMemory.clear();
}

void DataMemory::Init(ifstream &stream)
{
	if(!stream.is_open())
		throw "A stream do arquivo com dados não está aberta.";
	
	string input;
	int i = -1;
	vector<bool> data;
	while(true)
	{
		stream >> input;

		if(!stream) break;

		i++;
		if(input.size() == 0) continue;
		
		/* Convertendo a string do arquivo de dados para um vector de bools. */
		data.clear();
		for(int cont = 0; i < input.size(); i++)
		{
			if(input[cont] == 0)
				data.push_back(false);
			else if(input[cont] == 1)
				data.push_back(true);
			else
				throw "Dados inválidos no arquivo com dados.";
		}
	}
}

void DataMemory::SetValue(string index, vector<bool> input)
{
	if(input.size() > 16) throw "A memória de dados guarda somente 16 bits por célula.";
	if(index.size() != 5) throw "Endereço inválido de memória de dados.";	

	vector<bool> data = input;
	if(input.size() != 16) // Complementando o vector com 0's ate data ter 16 bits.
	{
		for(int i = input.size(); i < 16; i++)
			data.push_back(false);
	}
	dMemory[table[index]] = data;
}

void DataMemory::SetValue(int index, vector<bool> input)
{
	if(index < 0 || index > 31) throw "Endereço inválido de memória de dados.";
	if(input.size() > 16) throw "A memória de dados guarda somente 16 bits por célula.";

	vector<bool> data = input;
	if(input.size() != 16) // Complementando o vector com 0's ate date ter 16 bits.
	{
		for(int i = input.size(); i < 16; i++)
			data.push_back(false);
	}
	dMemory[index] = data;
}

// Função que retorna o valor de uma posição do data memory
vector<bool> DataMemory::GetValue(string index)
{
	if(index.size() != 5) throw "Endereço inválido de memória de dados.";
	
	return dMemory[table[index]];
}

vector<bool> DataMemory::GetValue(int index)
{
	if(index < 0 || index > 31) throw "Endereço inválido de memória de dados.";
	
	return dMemory[index];
}
