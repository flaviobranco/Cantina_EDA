#include <iostream>
#include "Refeição.h"
#include "Mesa.h"
using namespace std;

int main() {
	refeicao* refeicao;
	alterar_refeicao(refeicao);
	int tam = rand() % 30 + 20;
	int n_mesa = 0;//número de mesas
	int rnd=random_mesa();
	mesa *mesa = new struct mesa[rnd];//criar a variável struct mesa com o nome "mesa", determinei um limite máximo para o debugging do issue #9 no github
	while (tam != 0) {
		n_mesa += 1;
		if (tam - rnd < 0) {
			inserir_mesas(mesa,n_mesa,tam);
			tam = 0;
		}
		else {
			inserir_mesas(mesa, n_mesa, rnd);
			tam = tam - rnd;
		}
		rnd = random_mesa();
	}
	mostrar_mesas(mesa, n_mesa);
	return 0;
}

