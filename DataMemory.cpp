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

vector<bool> DataMemory::GetValue(string index)
{
	if(index.size() != 5) throw "Endereço inválido de memória de dados.";
	
	return dmemory[table[index]];
}

