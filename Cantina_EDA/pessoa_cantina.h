#ifndef PESSOA_CANTINA_H
#define PESSOA_CANTINA_H
#include <string>
#include <iostream>
#include"Refeição.h"
using namespace std;

struct pessoa_cantina {
	string pnome;
	string unome;
	string curso;
	long numero;
	double plafond;
	int n_grup;
	int ciclos;
	bool staff_ou_grupo;
	bool especial;
	pessoa_cantina* seguinte;
};

pessoa_cantina* cria_grupo();
//pessoa_cantina* remover_low_plafond(pessoa_cantina* fila, listaref refeicao);

#endif