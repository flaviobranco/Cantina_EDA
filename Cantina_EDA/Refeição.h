#pragma once
#include <string>
using namespace std;

struct refeicao {
	string entrada;
	string  prato;
	float pre�o;
	int ciclo;
};

void alterar_refeicao (struct refeicao* ref);
void mostrar_refeicao (struct refeicao* ref);