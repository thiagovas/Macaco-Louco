#ifndef InstructionMemory_hpp
#define InstructionMemory_hpp

#include <iostream>
#include <vector>
#include <string>
#include <fstream>

using namespace std;

class InstructionMemory {

private:
	vector<vector<bool> > iMemory;
public:
	InstructionMemory ();
	~InstructionMemory ();

	void init (fstream input);
};

#endif