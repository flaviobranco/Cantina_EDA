#include <iostream>
#include "Refei��o.h"
#include "Mesa.h"
using namespace std;

int main() {
	//refeicao* refeicao; // criar refei��o
	//alterar_refeicao(refeicao);
	int tam = rand()%30+20;
	int n_mesa = 0;//n�mero de mesas
	int rnd=random_mesa();
	int tam_ant=0;
	mesa *mesa = new struct mesa[rnd];//criar a vari�vel struct mesa com o nome "mesa", determinei um limite m�ximo para o debugging do issue #9 no github
	while (tam != 0) {
		if(tam <= 1) {
			inserir_mesas(mesa, n_mesa, 0);
			n_mesa -= 1;
			tam = tam_ant;
		}
		else {
			n_mesa += 1;
			inserir_mesas(mesa, n_mesa, rnd);
			tam_ant = tam;
			tam = tam - rnd;
			rnd = random_mesa();
		}
	}
	mostrar_mesas(mesa, n_mesa);
	return 0;
}

