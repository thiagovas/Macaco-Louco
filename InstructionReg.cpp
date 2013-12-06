#include "InstReg.hpp"

InstReg::InstReg(){

}

InstReg::~InstReg(){

}

void InstReg::SetValue(vector<bool> value){
	if(!IRWrite) throw "Wadafuck Nigga! U Canot do dat!";

	reg = value;	
}

vector<bool> InstReg::get_opcode(){
	return get_bits(15,17);
}

vector<bool> InstReg::get_rs(){
	return get_bits(10,14);
}

vector<bool> InstReg::get_rs(){
	return get_bits(10,14);
}

vector<bool> InstReg::get_rt(){
	return get_bits(5,9);
}

vector<bool> InstReg::get_rd(){
	return get_bits(0,4);
}

vector<bool> InstReg::get_immed5(){
	return get_bits(0,4);
}

vector<bool> InstReg::get_immed10(){
	return get_bits(0,9);
}

vector<bool> InstReg::get_bits (int lower, int upper){
	if (lower < 0 || upper > 17) throw "Limites errados!\n";

	vector<bool> bits (upper-lower+1, false);

	for (int i = lower; i <= upper; i++){
		if (reg[i]) bits[i-lower] = true;
	}

	return bits;
}

