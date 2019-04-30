#pragma once
#include <string>
using namespace std;
struct refeicao {
	string entrada;
	string  prato;
	float preço;
};

void alterar_refeicao(refeicao* refeicao);
void mostrar_refeicao(refeicao* refeicao);