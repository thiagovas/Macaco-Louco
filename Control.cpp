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
		case 0: /*FETCH*/return;
		case 1: /*BUSCA REGISTRADORES*/return;
		
		/*PARA ONDE VOU? OPcode RESPONDERÁ*/
		case 2: /*EXECUÇÃO*/return;
		case 3: /*CONCLUSÃO DE TIPO R*/return;
		case 4: /*TÉRMINO DO LOAD IMMEDIATE*/return;
		case 5: /*VERIFICA BRANCH*/return;
		case 6: /*CONCLUSÃO JUMP*/return;
		case 7: /*CONCLUSÃO JUMPR*/return;
		case default: cout << "Nao Conseguimos definir o Estado!\n "; return;


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

}

void Control::branch(){

}

void Control::conclui_jump(){

}

void Control::conclui_jumpr(){

}
