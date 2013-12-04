#ifndef InstructionMemory_hpp
#define InstructionMemory_hpp

#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <fstream>

using namespace std;

class InstructionMemory {

private:
	vector<vector<bool> > iMemory;
	map<string, string> table;
public:
	InstructionMemory ();
	~InstructionMemory ();

	void init (ifstream &input);
	void imprime ();
};

#endif