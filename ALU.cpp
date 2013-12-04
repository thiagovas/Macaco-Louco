// Arithmetic and Logic Unit
#include "ALU.hpp"

// ALUop :	ADD  - 	000(0)
// 			SUB  - 	001(1)
// 			AND  -	010(2)
// 			OR   - 	011(3)


void Alu::setvalues(vector<bool> input_a,vector<bool> input_b,bool first_bit,bool second_bit){
	a = input_a;
	b = input_b;

	if(first_bit == 0){
		if(second_bit == 0){
			ALUop = 0;
		}else{
			ALUop = 1;
		}
	}else{
		if(second_bit == 0){
			ALUop = 2;
		}else{
			ALUop = 3;
		}
	}

}


void Alu::do_operation(){
	switch (ALUop){
		case 0: sum(); return;
		
		case 1: if(sub() == 1)
					zero = true;
				else
					zero = false;
				return;

		case 2: alu_and(); return;
		case 3: alu_or(); return;
		default: cout << "O ALUop passado nao esta correto!!\nFuncao: Alu::do_operation\n";
	}

}

void Alu::sum(){
	for(int i = 0 ; i < 16 ; i++){
		result[i] = a[i] + b[i];
	}

	return;
}

bool Alu::sub(){
	bool resultis0 = true;

	for(int i = 0 ; i < 16 ; i++){
		result[i] = a[i] - b[i];
		if(result[i] != 0)
			resultis0 = false;
	}

	return resultis0;
}

void Alu::alu_and(){
	for(int i = 0 ; i < 16 ; i++){
		result[i] = a[i] & b[i];
	}

	return;
}

void Alu::alu_or(){
	for(int i = 0 ; i < 16 ; i++){
		result[i] = a[i] | b[i];
	}

	return;
}

vector<bool> Alu::result_value(){
	return result;
}

bool Alu::zero_value(){
	return zero;
}