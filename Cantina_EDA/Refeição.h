#pragma once

using namespace std;
struct refeicao {
	string entrada;
	string  prato;
	float pre�o;
	int ciclo;
};

void alterar_refeicao (refeicao* ref);
void mostrar_refeicao (refeicao* ref);