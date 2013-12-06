// Made By: Marcelo
// Revised by: ?
// NOT READY YET

#include "Control.hpp"

// Control Logic
Control::Control(){
	PCWriteCond = false;
	PCWrite = false;
	MemINSTRead = false;
	MemINSTWrite = false;
	IRWrite = false;
	MemRead1 = false;
	MemRead2 = false;
	MemWrite1 = false;
	MemWrite2 = false;
	PCSource = make_pair(false,false);
	MemDest = make_pair(false,false);
	AddressControl = make_pair(false,false);
	ALUOp = make_pair(false,false);
	ALUSrcB = false;
	ALUSrcA = false;
	Stage = 0;

	OPcode.resize(3,false);

}

Control::~Control(){
	Stage = 0;
	OPcode.clear();
}

void Control::setstage(int n_Stage){
	Stage = n_Stage;
	do_your_job();
}

void Control::do_your_job(){
	vector<bool> magic;

	/*ESCOLHE QUAIS REGISTRADORES*/
	switch(this->Stage){
		case 0: 	/*FETCH*/						fetch(); break;
		case 1: 	/*BUSCA REGISTRADORES*/			busca_reg(magic); break;
		
		/*PARA ONDE VOU? OPcode RESPONDERÁ*/
		case 2: 	/*EXECUÇÃO*/					executa(); break;
		case 3: 	/*CONCLUSÃO DE TIPO R*/			conclui_r(); break;
		case 4: 	/*TÉRMINO DO LOAD IMMEDIATE*/	conclui_loadi(); break;
		case 5: 	/*VERIFICA BRANCH*/				branch(); break;
		case 6: 	/*CONCLUSÃO JUMP*/				conclui_jump(); break;
		case 7: 	/*CONCLUSÃO JUMPR*/				conclui_jumpr(); break;
		default: cout << "Nao Conseguimos definir o Estado!\n "; Stage = 0;  return;
	}
	next_stage();
}


void Control::fetch(){
	MemINSTRead = true;
	IRWrite = true;
	ALUSrcA = false;
	ALUSrcB = true;
	ALUOp = make_pair(false,false);
	PCSource = make_pair(false,false);
	PCWrite = true;
}

void Control::busca_reg(vector<bool> instruction){
	MemRead1 = true;
	MemRead2 = true;

	/*Control::DEFINE OPcode*/
	for(int i = 13 ; i < 16; i++){
		OPcode[i-13] = instruction[i];
	}
}

void Control::executa(){
	/*ADD*/
	if( OPcode[0] == false && OPcode[1] == false && OPcode[2] == false ){
		ALUSrcA = true;
		ALUSrcB = false;
		ALUOp = make_pair(false,false);
	
	/*SUB*/
	}else if( OPcode[0] == false && OPcode[1] == false && OPcode[2] == true ){
		ALUSrcA = true;
		ALUSrcB = false;
		ALUOp = make_pair(false,true);

	/*AND*/
	}else if( OPcode[0] == false && OPcode[1] == true && OPcode[2] == false ){
		ALUSrcA = true;
		ALUSrcB = false;
		ALUOp = make_pair(false,false);

	/*OR*/
	}else{
		ALUSrcA = true;
		ALUSrcB = false;
		ALUOp = make_pair(true,true);

	}
}

void Control::conclui_r(){
	AddressControl = make_pair(false,true);
	MemWrite1 = true;
	MemWrite2 = true;
	MemDest = make_pair(true,true);
}

void Control::conclui_loadi(){
	MemWrite1 = true;
	MemWrite2 = false;
	MemDest = make_pair(false,false);
	AddressControl = make_pair(true,true);
}

void Control::branch(){
	ALUSrcA = true;
	ALUSrcB = false;
	ALUOp = make_pair(false,true);
	PCSource = make_pair(true,false);
	PCWriteCond = true;
}

void Control::conclui_jump(){
	PCSource = make_pair(true,false);
	PCWrite = true;
}

void Control::conclui_jumpr(){
	ALUSrcA = true;
	PCSource = make_pair(true,true);
	PCWrite = true;
}

void Control::next_stage(){
	if(Stage == 0){
		this->Stage = 1;
	}else if(Stage == 1){
		/*TIPO R*/
		if(!OPcode[2]){
			this->Stage = 2;
		
		/*LWI*/
		}else if(OPcode[1] == false && OPcode[0] == false){
			this->Stage = 4;
		
		/*BNE*/
		}else if(OPcode[1] == false && OPcode[0] == true){
			this->Stage = 5;

		/*J*/
		}else if(OPcode[1] == true && OPcode[0] == false){
			this->Stage = 6;
		
		/*JR*/
		}else{
			this->Stage = 7;
		}
	
	/*CONCLUSÃO TIPO R*/
	}else if(Stage == 2){
		this->Stage = 3;
	
	/*TÉRMINO DE INSTRUÇÃO*/
	}else{
		this->Stage = 0;
	}
}

void Control::go_my_child_i_free_you(Alu &alu1, Alu &alu2, InstructionMemory &ir , DataMemory &dm ){
	alu1.ALUop_update(ALUOp.second,ALUOp.first);
	alu2.ALUop_update(ALUOp.second,ALUOp.first);
}
