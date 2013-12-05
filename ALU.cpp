// Arithmetic and Logic Unit
#include "ALU.hpp"

// ALUop :	ADD  - 	000(0)
// 			SUB  - 	001(1)
// 			AND  -	010(2)
// 			OR   - 	011(3)


void Alu::setvalues(vector<bool> input_a,vector<bool> input_b,bool first_bit,bool second_bit){
	a = input_a;
	b = input_b;
	zero = false;

	result.resize(16,false);

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
	bool carryin = false;

	for(int i = 0 ; i < 16 ; i++){
cout << i << " " << (a[i] == true && b[i] == true) << " " << ( (result[i] == (a[i] ^ b[i] ^ true) && (b[i] = true || a[i] == true)) )<< endl;
		
		if(!carryin){
			result[i] = a[i] ^ b[i];
		
		}else{
			result[i] = a[i] ^ b[i] ^ true;

			carryin = false;
		}

		if( (a[i] == true && b[i] == true) || ( (result[i] == (a[i] ^ b[i] ^ true) && (b[i] = true || a[i] == true)) ) ){
cout << "Entrou\n" ;
			carryin = true;
		}

	}

	return;
}

bool Alu::sub(){
	bool resultis0 = true;

	for(int i = 0 ; i < 16 ; i++){
		if(a[i] == true && b[i] == true){
			result[i] == false;
		
		}else if(a[i] == true && b[i] == false){
			result[i] = true;

		}else if(a[i] == false && b[i] == false){
			result[i] = false;
		
		}else{

			int j = i+1;
			while(!a[j]){
				j++;
			}

			a[j] = false;
			result[j] = false;

		}
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

void Alu::print(){
	
	cout << "RS: ";
	for(int i = 16 ; i >= 0 ; i--){
		cout << a[i];
	}
	cout << endl;

	cout << "RT: ";
	for(int i = 16 ; i >= 0 ; i--){
		cout << b[i];
	}
	cout << endl;

	cout << "RD: ";
	for(int i = 16 ; i >= 0 ; i--){
		cout << result[i];
	}
	cout << endl << "Zero: " << zero << endl << "ALUop: " << ALUop << endl << endl;

	return;
}