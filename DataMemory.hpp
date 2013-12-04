#ifndef DataMemory_hpp
#define DataMemory_hpp

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <utility>
#include <functional>
#include <iomanip>
#include <string>
#include <cstring>
#include <vector>
#include <fstream>

using namespace std;

string Assembly_to_binary (string &s);

class DataMemory {
private:
	vector<vector<bool>	> dMemory;

public:
	DataMemory ();
	~DataMemory ();

	// Imprime toda a mémória de instruções;
	void imprime ();
	
};

#endif