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
#include "InstructionMemory.hpp"

using namespace std;

int main(int argc, char *argv[])
{

	InstructionMemory m;
	ifstream input (argv[1]);

	m.init (input);

	return 0;
}
