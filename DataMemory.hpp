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
#include <map>
using namespace std;

class DataMemory {
	private:
		vector<vector<bool> > dMemory;
		map<string, int> table;
	public:
		DataMemory();
		~DataMemory();

		// Imprime toda a memória de instruções;
		void Print();
		void Init(ifstream&);
		void SetValue(string, vector<bool>);
		void SetValue(int, vector<bool>);
		void Clear();
		vector<bool> GetValue(string);
		vector<bool> GetValue(int);
};

#endif
