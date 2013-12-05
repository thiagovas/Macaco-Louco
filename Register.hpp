#ifndef _Register_hpp
#define _Register_hpp


#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <map>
#include <algorithm>
#include <utility>
#include <functional>
#include <iomanip>
#include <string>
#include <sstream>
using namespace std;

class Register
{
	private:
		vector<vector<bool> > reg;
		map<string, int> table;
		int size; //Numero de bits que um registrador guarda
	public:
		Register();
		~Register();
		void SetValue(string, vector<bool>);
};

#endif
