// This memory keeps the instructions
#include "InstructionMemory.hpp"
#include <string>

// Construtor;
InstructionMemory::InstructionMemory (){
	iMemory.resize (32, vector<bool> (18, false));
	table["ADD"] = "000";
	table["SUB"] = "001";
	table["AND"] = "010";
	table["OR"] = "011";
	table["LWI"] = "100";
	table["BNE"] = "101";
	table["J"] = "110";
	table["JR"] = "111";

	table["M0"] = "00000";
	table["M1"] = "00001";
	table["M2"] = "00010";
	table["M3"] = "00011";
	table["M4"] = "00100";
	table["M5"] = "00101";
	table["M6"] = "00110";
	table["M7"] = "00111";
	table["M8"] = "01000";
	table["M9"] = "01001";
	table["M10"] = "01010";
	table["M11"] = "01011";
	table["M12"] = "01100";
	table["M13"] = "01101";
	table["M14"] = "01110";
	table["M15"] = "01111";
	table["M16"] = "10000";
	table["M17"] = "10001";
	table["M18"] = "10010";
	table["M19"] = "10011";
	table["M20"] = "10100";
	table["M21"] = "10101";
	table["M22"] = "10110";
	table["M23"] = "10111";
	table["M24"] = "11000";
	table["M25"] = "11001";
	table["M26"] = "11010";
	table["M27"] = "11011";
	table["M28"] = "11100";
	table["M29"] = "11101";
	table["M30"] = "11110";
	table["M31"] = "11111";

	string aux;
}

// Destrutor;
InstructionMemory::~InstructionMemory (){
	iMemory.clear();
	table.clear();
}

void InstructionMemory::imprime (){
	for (int i = 0; i < iMemory.size(); i++){
		for (int j = 0; j < iMemory[i].size(); j++){
			cout << iMemory[i][j] << ' ';
		}
		cout << endl;
	}
	cout << endl;
}

// 
void InstructionMemory::init (ifstream &input){

	if (!input.is_open ()){
		cout << "Oh crap!\n";
	}

	string dest, reg1, reg2, op, binary;
	string label;
	bitset<5> bits;

	while (true){
		input >> op;

		if (!input) break;

		binary.clear();
		bits.reset();

		if (op == "ADD" || op == "SUB" || op == "AND" || op == "OR"){
			input >> dest >> reg1 >> reg2;
			binary += table[op] + table[reg1] + table[reg2] + dest;
		}
		else  if (op == "LWI"){
			input >> reg1 >> label;
			// bits = label;
			cout << label << endl;
			// cout << bits << ' ' << label << endl;
			binary += table[op] + table[reg1] + "00000";
		}
		else if (op == "BNE"){
			input >> reg1 >> reg2 >> label;
		}
		else if (op == "J"){
			input >> label;
		}
		else {
			// JR;
			input >> dest;
		}
	}

}