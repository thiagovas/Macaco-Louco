// This memory keeps the instructions
#include "InstructionMemory.hpp"

// Construtor;
InstructionMemory::InstructionMemory (){
	iMemory.resize (32, vector<bool> (16, false));
}

// Destrutor;
InstructionMemory::~InstructionMemory (){
	iMemory.clear();
}

// 
void InstructionMemory::init (fstream input){

	if (!input.is_open ()){
		cout << "Oh crap!\n";
	}

	string assembly;

	while (true){
		// input.getline ()
	}
}