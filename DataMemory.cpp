#include "DataMemory.hpp"

// Construtor;
DataMemory::DataMemory(){
	dMemory.resize (32, vector<bool> (16, false));
}

// Destrutor;
DataMemory::~DataMemory (){
	dMemory.clear();
}

// Imprime;
void DataMemory::imprime (){

	for (int i = 0; i < dMemory.size(); i++){
		for (int j = 0; j < dMemory[i].size(); j++){
			cout << dMemory[i][j] << ' ';
		}
		cout << endl;
	}
	cout << endl;
}