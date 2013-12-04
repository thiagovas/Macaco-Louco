#include "DataMemory.hpp"

// Construtor;
DataMemory::DataMemory(){
	Memory.resize (32, vector<bool> (16, false));
}

// Destrutor;
DataMemory::~DataMemory (){
	Memory.clear();
}
