#include "Adder.hpp"

Adder::Adder()
{}

Adder::~Adder()
{}


vector<bool> Adder::SumOne(vector<bool> input)
{
	Alu ula;
	vector<bool> b(16, false);
	b[0] = true;
	ula.setvalues(input, b);
	ula.sum();
	return ula.result_value();
}
