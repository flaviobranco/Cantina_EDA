#include <iostream>
#include "Refeição.h"
#include "Mesa.h"
using namespace std;

int main() {
	int tam = rand() % 30 + 20;
	int n_mesa = 0;
	int rnd=random();
	mesa* mesa = new struct mesa;
	while (tam != 0) {
		n_mesa += 1;
		rnd = random();
		if (tam - rnd < 0) {
			inserir_mesas(mesa,n_mesa,tam);
			tam = 0;
		}
		else {
			inserir_mesas(mesa, n_mesa, rnd);
			tam = tam - rnd;
		}
	}
	return 0;
}