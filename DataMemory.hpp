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

using namespace std;

class DataMemory {
private:
	vector<vector<bool> > Memory;

public:
	DataMemory ();
	~DataMemory ();
	void imprime ();
};

#endif