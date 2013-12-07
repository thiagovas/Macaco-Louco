/*Made By: Marcelo*/
/*Revisao By : ?*/
/*Versão 1.0*/
// Arithmetic and Logic Unit
#include "ALU.hpp"
#include <cmath>

// ALUop :	ADD  - 	000(0)
// 			SUB  - 	001(1)
// 			AND  -	010(2)
// 			OR   - 	011(3)


/*INICIALIZA VALORES*/
void Alu::setvalues(vector<bool> input_a, vector<bool> input_b, bool first_bit, bool second_bit){
	a = input_a;
	b = input_b;
	zero = false;
	overflow = false;

	/*ALOCA O RESULTADO PRA SER 0*/
	result.resize(16,false);
}

// ATUALIZA ALUOP
void Alu::ALUop_update(bool first_bit, bool second_bit){
	/*CONVERTE OS DOIS BITS DE BOOL PARA UMA CODIFICAÇÃO EM INTEIRO*/
	// 0 = SOMA ; 1 = SUB ; 2 = AND ; 3 = OR;
	if(first_bit == 0){
		if(second_bit == 0){
			this->ALUop = 0;
		}else{
			this->ALUop = 1;
		}
	}else{
		if(second_bit == 0){
			this->ALUop = 2;
		}else{
			this->ALUop = 3;
		}
	}
}

/*ESCOLHE QUAL OPERAÇÃO FAZER DEPENDENDO DO ALUop*/
void Alu::do_operation(){
	switch (this->ALUop){
		case 0: sum(); return;
		
		/*VERIFICA FLAG ZERO PARA O BRANCH*/
		case 1: this->zero = sub(); return;
		case 2: alu_and(); return;
		cas 3: alu_or(); return;
		default: cout << "O ALUop passado nao esta correto!!\nFuncao: Alu::do_operation\n";
	}
}

void Alu::sum(){
	bool carryin = false;

	/*CÓPIA SEGURANÇA PARA OVERFLOW*/
	vector<bool> zeros = result;

	for(int i = 0 ; i < 16 ; i++){
		
		/*CASO O CARRYIN NÃO ESTIVER SETADO TEMOS UMA SIMPLES XOR*/
		if(!carryin){
			result[i] = a[i] ^ b[i];

			/*VERIFICA O CARRYOUT*/
			if( (a[i] == true && b[i] == true) ){
				carryin = true;
			}else{
				carryin = false;
			}

		}else{

			/*SE O CARRYIN ESTIVER SETADO DEVEMOS SOMÁ-LO TBM*/
			result[i] = a[i] ^ b[i] ^ true;

			/*VERIFICA CARRYOUT*/
			if(a[i] == true || b[i] == true){
				carryin = true;
			}else{
				carryin = false;
			}
		}

	}

	/*VERIFICA OVERFLOW*/
	if(carryin){
		overflow = true;
		result = zeros;
	}
}

bool Alu::sub(){
	bool resultis0 = true;
	
	/*COPIA PARA NAO SUJAR O A*/
	vector<bool>copy;

	copy = a;

	/*VERSÃO BETA 1.0 SEM SUPORTE À NEGATIVOS*/
	if( result_is_negative() ){
		cout << "Resultado Impossivel\n(RS - RT < 0)\n";
		return false;
	}

	/*LISTEI OS 4 CASOS POSSÍVEIS*/
	for(int i = 0 ; i < 16 ; i++){
		if(a[i] == true && b[i] == true){
			result[i] = false;
		}else if(a[i] == true && b[i] == false){
			result[i] = true;

		}else if(a[i] == false && b[i] == false){
			result[i] = false;
		
		}else{
			
			/*"TIRA UM DO PRÓXIMO"*/
			int j = i+1;
			while(!a[j]){
				a[j] = true;
				result[j] = true;
				j++;
			}

			a[j]=false;
			result[j] = false;
		}

		if(result[i]) resultis0 = false;
	}

	/*RETORNA VALOR ORIGINAL DE A*/
	a = copy;

	return resultis0;
}

void Alu::alu_and(){

	/*AND BIT A BIT*/
	for(int i = 0 ; i < 16 ; i++){
		result[i] = a[i] & b[i];
	}

	return;
}

void Alu::alu_or(){

	/*OR BIT A BIT*/
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

bool Alu::result_is_negative(){
	int a_int=0,b_int=0;

	/*PASSA BINÁRIO PARA INTEIRO*/
	for(int i = 0 ; i < 16 ; i++){
		if(a[i])
			a_int += pow(2,i);
	}

	/*SAME*/
	for(int i = 0 ; i < 16 ; i++){
		if(b[i])
			b_int += pow(2,i);
	}

	/*RETORNA SE A<B*/
	return (a_int < b_int) ;
}
