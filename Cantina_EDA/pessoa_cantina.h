#ifndef PESSOA_CANTINA_H
#define PESSOA_CANTINA_H
#include <string>
#include <iostream>
using namespace std;

struct pessoa_cantina {
	string pnome;
	string unome;
	string curso;
	long numero;
	float plafond;
	int n_grup;
	int ciclos;
	bool staff_ou_grupo;
	pessoa_cantina* seguinte;
};

pessoa_cantina* cria_grupo();

#endif