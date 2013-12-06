// This memory keeps the instructions

/*
	Author: Guilherme Vieira Leobas
	Version: 1.0b
*/

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
		for (int j = iMemory[i].size()-1; j >=0; j--){
			cout << iMemory[i][j];
			if (j == 5 || j == 10 || j == 15) cout << ' ';
		}
		cout << endl;
	}
	cout << endl;
}

vector<bool> InstructionMemory::get_instruction (int pos){

	if (pos % 18 != 0) cout << "I'm sorry Dave, I'm afraid I can't do that\n";

	return iMemory[pos/18];
}

void InstructionMemory::init (ifstream &input){

	if (!input.is_open ()){
		cout << "Oh crap!\n";
	}

	string dest, reg1, reg2, op, binary;
	int label, line;

	line = 0;

	while (true){
		input >> op;

		if (!input) break;

		binary.clear();

		if (op == "ADD" || op == "SUB" || op == "AND" || op == "OR"){
			input >> dest >> reg1 >> reg2;
			binary += invert(table[dest]) + invert(table[reg2]) + invert(table[reg1]) + invert(table[op]);
		}
		else  if (op == "LWI"){
			input >> reg1 >> label;
			binary += invert(int_to_bitstring (label, 10)) + invert(table[reg1]) + invert(table[op]);
		}
		else if (op == "BNE"){
			input >> reg1 >> reg2 >> label;
			binary += invert(int_to_bitstring (label, 10)) + invert(table[reg2]) + invert(table[reg1]) + invert(table[op]);
		}
		else if (op == "J"){
			input >> label;
			binary += invert(int_to_bitstring (label, 10)) + "00000" + invert(table[op]);
		}
		else {
			// JR;
			input >> dest;
			binary += invert(table[dest]) + "000000000" + invert(table[op]);
		}

		for (int i = 0; i < 18; i++){
			if (binary[i] == '0') iMemory[line][i] = 0;
			else iMemory[line][i] = 1;
		}

		line++;
	}

}

string int_to_bitstring (int label, int size){
	
	int x = 1 << size-1;
	string binary;

	while (x){
		if (label&x) binary += '1';
		else binary += '0';
		x = x >> 1;
	}

	return binary;
}

string invert (string s){
	string result;

	for (int i=s.size()-1; i>=0; i--){
		result += s[i];
	}

	return result;
}