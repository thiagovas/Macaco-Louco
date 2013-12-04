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

class DataMemory {
	private:
		vector<vector<bool> > dMemory;

	public:
		DataMemory();
		~DataMemory();

		// Imprime toda a memória de instruções;
		void Print();
		void Push_back(vector<bool>);
		void Clear();
};

#endif
