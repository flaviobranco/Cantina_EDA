#pragma once
#include <string>
using namespace std;

struct refeicao {
	string entrada;
	string  prato;
	float pre�o;
};

void alterar_refeicao (struct refeicao* ref);
void mostrar_refeicao (struct refeicao* ref);