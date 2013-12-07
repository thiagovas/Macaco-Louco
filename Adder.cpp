#include "Adder.hpp"

Adder::Adder()
{}

Adder::~Adder()
{}


vector<bool> Adder::SumOne(vector<bool> input)
{
// cout << "Vai ADDER: ";

	Alu ula;
	vector<bool> b(16, false);
	b[0] = true;
	ula.setvalues(input, b);

	input.resize (16);

	for (int i=5; i<input.size(); i++){
		input[i] = false;
	}

	ula.sum();

	input = ula.result_value();
	
	while (input.size() > 5){
		input.pop_back();
	}

	return input;
}
