#ifndef InstructionMemory_hpp
#define InstructionMemory_hpp

#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <sstream>
#include <fstream>
#include <bitset>

using namespace std;

class InstructionMemory {

private:
	vector<vector<bool> > iMemory;
	map<string, string> table;
public:
	InstructionMemory ();
	~InstructionMemory ();

	void init (ifstream &input);
	vector<bool> get_instruction (int pos);
	vector<bool> get_opcode (int pos);
	void imprime ();
};

string int_to_bitstring (int label, int size);
string invert (string s);

#endif