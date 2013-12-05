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
	ALUop = false;
	ALUSrcB = false;
	ALUSrcA = false;
	Cicle = 0;

	for(int i = 0 ; i < 5 . i++){
		OPcode.push_back(false);
	}

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
	ALUop = false;
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


void fetch(){

}

void busca_reg(){

}

void executa(){

}

void conclui_r(){

}

void conclui_loadi(){

}

void branch(){

}

void conclui_jump(){

}

void void conclui_jumpr(){

}
