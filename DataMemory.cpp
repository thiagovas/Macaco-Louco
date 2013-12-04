#include "DataMemory.hpp"

// Construtor;
DataMemory::DataMemory()
{
	//dMemory.resize (32, vector<bool> (16, false));
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

void DataMemory::Push_back(vector<bool> input)
{
	if(input.size() > 16) throw "A memória de dados guarda somente 16 bits por célula.";
	if(dMemory.size() > 32) throw "A memória de dados possui somente 32 posições.";
	
	vector<bool> data = input;
	if(input.size() != 16) // Complementando o vector com 0's ate data ter 16 bits.
	{
		for(int i = input.size(); i < 16; i++)
			data.push_back(false);
	}
	dMemory.push_back(data);
}
