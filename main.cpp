#include <iostream>
#include <utility>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <cmath>
#include <cstdlib>
#include <cstdio>
#include <cctype>
#include <string>
#include <deque>
<<<<<<< HEAD
#include "InstructionMemory.hpp"

=======
#include <fstream>
>>>>>>> ce3b11b36d7d6039e1594f81b8986e1631356bb9
using namespace std;

int main(int argc, char *argv[])
{
<<<<<<< HEAD

	InstructionMemory m;
	ifstream input (argv[1]);

	m.init (input);

=======
	ios::sync_with_stdio(false);
	if(argc != 4)
	{
		cout << "Siga o padrao: ./<exec> <arquivo com instrucoes> <arquivo com dados> <arquivo de saida>" << endl;
		return 1;
	}
	
	fstream output, inputInstructions, inputData;
	
	
>>>>>>> ce3b11b36d7d6039e1594f81b8986e1631356bb9
	return 0;
}
