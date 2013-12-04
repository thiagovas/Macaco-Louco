#include "DataMemory.hpp"

// Construtor;
DataMemory::DataMemory(){
	Memory.resize (32, vector<bool> (16, false));
}

// Destrutor;
DataMemory::~DataMemory (){
	Memory.clear();
}

// Imprime;
void DataMemory::imprime (){

	for (int i = 0; i < Memory.size(); i++){
		for (int j = 0; j < Memory[i].size(); j++){
			cout << Memory[i][j] << ' ';
		}
		cout << endl;
	}
	cout << endl;
}

void DataMemory::init (ifstream Data){

	// Checa se o arquivo está aberto;
	if (!Data.is_open()){
		cout << "Sometimes shits happens\n";
		return;
	}

	/* To-Do
	 * Checar se a linha do arquivo é código assembly ou binario;
		 * Se é binario, apenas copie para a memória
		 * Senão traduza o código assembly para o bínario e cópie;
	 * PRECISO DE OUTRAS BIBLIOTECAS PRONTAS PARA FAZER ISSO!
	*/
}