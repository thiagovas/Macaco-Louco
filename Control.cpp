// Made By: Marcelo
// Revised by: ? 
// NOT READY YET

// Control Logic
void Control::Control(){
	PCWriteCond = false;
	PCWrite = false;
	MemINSTRead = false;
	MemINSTWrite = false;
	IRWrite = false;
	MemRead1 = false;
	MemRead2 = false;
	MemWrite1 = false;
	MemWrite2 = false;
	PCSource = false;
	MemDest = false;
	AddresControl = false;
	ALUOp = false;
	ALUSrcB = false;
	ALUSrcA = false;
	Cicle = 0;

	OPcode.resize(3,false);

	return;
}

void Control::~Control(){
	PCWriteCond = false;
	PCWrite = false;
	MemINSTRead = false;
	MemINSTWrite = false;
	IRWrite = false;
	MemRead1 = false;
	MemRead2 = false;
	MemWrite1 = false;
	MemWrite2 = false;
	PCSource = false;
	MemDest = false;
	AddresControl = false;
	ALUOp = false;
	ALUSrcB = false;
	ALUSrcA = false;
	Cicle = 0;

	OPcode.clear();
}

void Control::setcicle(int n_cicle){
	Cicle = n_cicle;
	do_your_job();
}

void do_your_job(){

	/*ESCOLHE QUAIS REGISTRADORES*/
	switch(Cicle){
		case 0: 	/*FETCH*/						fetch(); Stage = next_stage(OPcode,Stage); return;
		case 1: 	/*BUSCA REGISTRADORES*/			busca_reg(); Stage = next_stage(OPcode,Stage); return;
		
		/*PARA ONDE VOU? OPcode RESPONDERÁ*/
		case 2: 	/*EXECUÇÃO*/					executa(); Stage = next_stage(OPcode,Stage); return;
		case 3: 	/*CONCLUSÃO DE TIPO R*/			conclui_r(); Stage = next_stage(OPcode,Stage); return;
		case 4: 	/*TÉRMINO DO LOAD IMMEDIATE*/	conclui_loadi(); Stage = next_stage(OPcode,Stage); return;
		case 5: 	/*VERIFICA BRANCH*/				branch(); Stage = next_stage(OPcode,Stage); return;
		case 6: 	/*CONCLUSÃO JUMP*/				conclui_jump(); Stage = next_stage(OPcode,Stage); return;
		case 7: 	/*CONCLUSÃO JUMPR*/				conclui_jumpr(); Stage = next_stage(OPcode,Stage); return;
		case default: cout << "Nao Conseguimos definir o Estado!\n "; Stage = 0;  return;


	}

	return;
}


void Control::fetch(){
	MemINSTRead = true;
	IRWrite = true;
	ALUSrcA = false;
	ALUSrcB = true;
	ALUOp = make_pair(false,false);
	PCSource = make_pair(false,false);
	PCWrite = true;
	
	return;
}

void Control::busca_reg(vector<bool> instruction){
	MemRead1 = true;
	MemRead2 = true;

	/*DEFINE OPcode*/
	for(int i = 13 ; i < 16; i++){
		OPcode[i-13] = instruction[i];
	}

	return;
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

	return;

}

void Control::conclui_r(){
	AddressControl = make_pair(false,true);
	MemWrite1 = true;
	MemWrite2 = true;
	MemDst = make_pair(true,true);

	return;
}

void Control::conclui_loadi(){
	MemWrite1 = true;
	MemWrite2 = false;
	MemDst = make_pair(false,false);
	Address Control = make_pair(true,true);

	return;
}

void Control::branch(){
	ALUSrcA = true;
	ALUSrcB = false;
	ALUOp = make_pair(false,true);
	PCSource = make_pair(true,false);
	PCWriteCond = true;

	return;
}

void Control::conclui_jump(){
	PCSource = make_pair(true,false);
	PCWrite = true;

	return;
}

void Control::conclui_jumpr(){
	ALUSrcA = true;
	PCSource = make_pair(true,true);
	PCWrite = true;

	return;
}

int next_stage(OPcode,Stage){
	if(Stage == 0){
		return 1;
	}else if(Stage == 1){
		/*TIPO R*/
		if(!OPcode[2]){
			return 2;
		
		/*LWI*/
		}else if(OPcode[1] == false && OPcode[0] == false){
			return 4;
		
		/*BNE*/
		}else if(OPcode[1] == false && OPcode[0] == true){
			return 5;

		/*J*/
		}else if(OPcode[1] == true && OPcode[0] == false){
			return 6;
		
		/*JR*/
		}else{
			return 7;
		}
	
	/*CONCLUSÃO TIPO R*/
	}else if(Stage == 2){
		return 3;
	
	/*TÉRMINO DE INSTRUÇÃO*/
	}else{
		return 0;
	}
}