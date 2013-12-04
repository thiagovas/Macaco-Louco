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
	vector<vector<bool>	> Memory;

public:
	DataMemory ();
	~DataMemory ();

	// Imprime toda a mémória de instruções;
	void imprime ();

	// Recebe um arquivo e inicializa todas as 32 posições da memória de dados com o bínario.
	void init (ifstream in);
	
};

#endif