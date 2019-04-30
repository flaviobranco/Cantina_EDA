#pragma once

using namespace std;
struct refeicao {
	string entrada;
	string  prato;
	float preço;
	int ciclo;
};

void alterar_refeicao (refeicao* ref);
void mostrar_refeicao (refeicao* ref);