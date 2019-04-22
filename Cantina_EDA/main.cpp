#include <iostream>
#include "Refeição.h"
#include "Mesa.h"
using namespace std;

int main() {
	//refeicao* refeicao; // criar refeição
	//alterar_refeicao(refeicao);
	int tam = 41;
	int n_mesa = 0;//número de mesas
	int rnd=random_mesa();
	int tam_ant;
	mesa *mesa = new struct mesa[rnd];//criar a variável struct mesa com o nome "mesa", determinei um limite máximo para o debugging do issue #9 no github
	while (tam != 0) {
		n_mesa += 1;
		if (tam - rnd < 0) {
			n_mesa -= 1;
			inserir_mesas(mesa, n_mesa, 0);
			tam = tam + tam_ant;
		}
		else {
			inserir_mesas(mesa, n_mesa, rnd);
			tam = tam - rnd;
			tam = tam_ant;
		}
		rnd = random_mesa();
	}
	mostrar_mesas(mesa, n_mesa);
	return 0;
}

