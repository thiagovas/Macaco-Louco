#include "Mux.hpp"

Mux::Mux()
{
	this->input.resize(4);
	this->controlSign = make_pair(false, false);
}

Mux::~Mux()
{
	this->input.clear();
}

void Mux::SetControlSign(pair<bool, bool> sign)
{
	this->controlSign = sign;
}

void Mux::SetControlSign(bool sign)
{
	if(sign)
		this->controlSign = make_pair(false, false);
	else
		this->controlSign = make_pair(false, true);
}

pair<bool, bool> Mux::GetControlSign()
{
	return this->controlSign;
}

void Mux::SetInput(vector<bool> first, vector<bool> second, vector<bool> third, vector<bool> fourth)
{
	this->input[0] = first;
	this->input[1] = second;
	this->input[2] = third;
	this->input[3] = fourth;
}

void Mux::SetInput(vector<bool> first, vector<bool> second)
{
	this->input[0] = first;
	this->input[1] = second;
	this->input[2] = this->input[3] = NULL;
}

vector<bool> Mux::GetOutput()
{
	if(!this->controlSign.first && !this->controlSign.second) // Mux vai retornar a posição 00
		return this->input[0];
	else if(!this->controlSign.first && this->controlSign.second) // Mux vai retornar a posição 01
		return this->input[1];
	else if(this->controlSign.first && !this->controlSign.second) //Mux vai retornar a posição 10
		return this->input[2];
	else return this->input[3];	//Mux vai retornar a posição 11
}
