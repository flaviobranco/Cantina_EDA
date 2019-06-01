#pragma once
#include <string>
using namespace std;

struct listaref {
	struct refeicao {
		string entrada;
		string prato;
		double preco;
		refeicao* anterior;
	}; refeicao* actual;
};

void novarefeicao(listaref& lista, string entrada, string prato, float preco);
void alterar_refeicao(struct listaref& lista);
void mostrar_refeicao(struct listaref& lista);