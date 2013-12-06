#ifndef _Mux_hpp
#define _Mux_hpp

#include <iostream>
#include <cstdlib>
#include <vector>
#include <map>
#include <algorithm>
#include <utility>
#include <functional>
#include <iomanip>
using namespace std;

class Mux{
	private:
		vector<vector<bool> > input;
		pair<bool, bool> controlSign;
	public:
		Mux();
		~Mux();
		// Seta o sinal do controle
		void SetControlSign(pair<bool, bool>);
		void SetControlSign(bool sign); //Mesma coisa do ser de cima, mas esse metodo serve para os muxes que tem somente dois inputs.
		// Retorna o sinal do controle que está no Mux
		pair<bool, bool> GetControlSign();
		// Seta o input do Mux
		void SetInput(vector<bool>, vector<bool>, vector<bool>, vector<bool>);
		void SetInput(vector<bool>, vector<bool>); //Mesma coisa do set de cima, mas esse metodo serve para os muxes que tem somente dois inputs
		// Retorna o output do Mux
		vector<bool> GetOutput();
};

#endif
