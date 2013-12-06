#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <deque>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <stack>
#include <queue>
#include <cmath>
#include <fstream>
#include <functional>
#include <iomanip>
#include <sstream>

using namespace std;

string convert (int a){
	stringstream ss;
	ss << a;
	return ss.str();
}

string int_to_bitstring (int label, int size){
	
	int x = 1 << size-1;
	string binary;

	while (x){
		if (label&x) binary += '1';
		else binary += '0';
		x = x >> 1;
	}

	return binary;
}

string invert (string s){
	string result;

	for (int i=s.size()-1; i>=0; i--){
		result += s[i];
	}

	return result;
}

void write_data (ofstream &data){
	int a = rand()%65536;
	// cout << a << endl;
	data << invert (int_to_bitstring (a, 16)) << endl;
}

void r_type (ofstream &inst){
	inst << "M" << convert (rand()%32) << ' ' << "M" << convert(rand()%32) << ' ' << "M" << convert(rand()%32) << endl;
}

void lwi_type (ofstream &inst){
	inst << "M" << convert (rand()%32) << ' ' << rand()%1024 << endl;
}

void bne_type (ofstream &inst){
	inst << "M" << convert (rand()%32) << ' ' << "M" << convert (rand()%32) << ' ' << rand()%32 << endl;
}

void j_type (ofstream &inst){
	int a = rand()%32;
	inst << 18*a << endl;
}

void jr_type (ofstream &inst){
	inst << "M" << convert (rand()%32) << endl;
}

void convert_to_funct (ofstream &inst, string instruction, map<string, int> table){
	if (table[instruction] == 1){
		r_type (inst);
	}
	else if (table[instruction] == 2){
		lwi_type (inst);
	}
	else if (table[instruction] == 3){
		bne_type (inst);
	}
	else if (table[instruction] == 4){
		j_type (inst);
	}
	else {
		jr_type (inst);
	}
}

int main (int argc, char *argv[]){

	ios::sync_with_stdio(false);
	
	// Primeiro parametro: Quantidade de instruções [0..32]
	// Segundo parametro: Quantidade de elementos na memória de dados;

	int quant_inst = atoi (argv[1]);
	int quant_dados = atoi (argv[2]);
	int random_number;

	srand(time(NULL));

	string instruction;

	map<string, int> table;

	table["ADD"] = 1;
	table["SUB"] = 1;
	table["AND"] = 1;
	table["OR"] = 1;
	table["LWI"] = 2;
	table["BNE"] = 3;
	table["J"] = 4;
	table["JR"] = 5;

	map<int, string> type_inst;

	type_inst[0] = "ADD";
	type_inst[1] = "SUB";
	type_inst[2] = "AND";
	type_inst[3] = "OR";
	type_inst[4] = "LWI";
	type_inst[5] = "BNE";
	type_inst[6] = "J";
	type_inst[7] = "JR";

	ofstream inst ("inst");
	ofstream data ("data");

	for (int i=0; i<quant_inst; i++){
		instruction = type_inst[rand()%8];
		inst << instruction << ' ';
		convert_to_funct (inst, instruction, table);
	}

	for (int i=0; i<quant_dados; i++){
		write_data (data);
	}

	return 0;
}