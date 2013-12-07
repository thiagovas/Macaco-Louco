#ifndef DataMemory_hpp
#define DataMemory_hpp

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
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
		bool MemRead1, MemRead2, MemWrite1, MemWrite2;
	public:
		DataMemory();
		~DataMemory();

		// Imprime toda a memória de instruções;
		void update_signal (bool MemRead1, bool MemRead2, bool MemWrite1, bool MemWrite2);
		void Print(fstream&);
		void Init(ifstream&);
		void SetValue(string, vector<bool>);
		void SetValue(int, vector<bool>);
		void SetValue(vector<bool>, vector<bool>);
		void SetValue2(vector<bool>, vector<bool>);
		void Clear();
		vector<bool> GetValue(string);
		vector<bool> GetValue(int);
		vector<bool> GetValue(vector<bool>);
};

int fromVectorToInt(vector<bool>);

#endif
