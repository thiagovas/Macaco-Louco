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
	bool MemINSTRead;
public:
	InstructionMemory ();
	~InstructionMemory ();

	void imprime ();
	void set_signal (bool signal);
	void reset_signal ();
	vector<bool> get_instruction (int pos);
	vector<bool> get_opcode (int pos);
	void init (ifstream &input);
};

string int_to_bitstring (int label, int size);
string invert (string s);

#endif