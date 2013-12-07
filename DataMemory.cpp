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
void DataMemory::Print(fstream &file)
{
	for (int i = 0; i < dMemory.size(); i++){
		for (int j = dMemory[i].size()-1; j >= 0; j--){
			file << dMemory[i][j];
		}
		file << endl;
	}
	file << endl;
}

void DataMemory::Clear()
{
	dMemory.clear();
}

void DataMemory::Init(ifstream &stream)
{
	if(!stream.is_open())
		cout << "A stream do arquivo com dados não está aberta.\n";
	
	string input;
	int i = 0;
	vector<bool> data;
	while(true)
	{
		stream >> input;
		// getline(stream, input);
		if(not stream) break;

		// i++;
		if(input.size() == 0) continue;
		
		/* Convertendo a string do arquivo de dados para um vector de bools. */
		data.clear();
		for(int cont = input.size(); cont >= 0; cont--)
		{
			if(input[cont] == '0')
				data.push_back(false);
			else if(input[cont] == '1')
				data.push_back(true);
			else{
				cout << "Dados inválidos no arquivo com dados.\n";
				cout << input[cont] << ' ';
			}
		}

		dMemory[i++] = data;
	}
}

void DataMemory::SetValue(string index, vector<bool> input)
{
	if(input.size() > 16) cout << "A memória de dados guarda somente 16 bits por célula.\n";
	if(index.size() != 5) cout << "Endereço inválido de memória de dados.\n";	

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
	if(index < 0 || index > 31) cout << "Endereço inválido de memória de dados.\n";
	if(input.size() > 16) cout << "A memória de dados guarda somente 16 bits por célula.\n";

	vector<bool> data = input;
	if(input.size() != 16) // Complementando o vector com 0's ate date ter 16 bits.
	{
		for(int i = input.size(); i < 16; i++)
			data.push_back(false);
	}
cout << "Index " << index << "\nData  : "  ;
for(int i = data.size()-1 ; i >= 0 ; i--){
	cout << data[i];
}
cout << endl;
	dMemory[index] = data;
}

void DataMemory::SetValue(vector<bool> index, vector<bool> input)
{
cout << "Recebido : ";
for(int i = index.size()-1; i >=0 ; i--){
	cout << index[i];
}
cout << endl;
	if(MemWrite1)
		SetValue(fromVectorToInt(index), input);
}

void DataMemory::SetValue2(vector<bool> index, vector<bool> input)
{
	if(MemWrite2)
		SetValue(fromVectorToInt(index), input);
}

// Função que retorna o valor de uma posição do data memory
vector<bool> DataMemory::GetValue(string index)
{
	if(index.size() != 5) cout << "Endereço inválido de memória de dados.\n";
	
	return dMemory[table[index]];
}

vector<bool> DataMemory::GetValue(int index)
{
	if(index < 0 || index > 31) cout << "Endereço inválido de memória de dados.\n";
	
	return dMemory[index];
}

vector<bool> DataMemory::GetValue(vector<bool> index)
{
	if(MemRead1 && MemRead2)
		return GetValue(fromVectorToInt(index));
}

int fromVectorToInt(vector<bool> input)
{
	int result = 0;
	for(int i = input.size()-1; i >= 0; i--)
		if(input[i])
			result += pow(2, i);
	return result;
}
