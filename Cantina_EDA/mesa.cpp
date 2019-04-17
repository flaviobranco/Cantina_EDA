#include "Mesa.h"
#include <iostream>
using namespace std;

void inserir_mesas(mesa* mesa, int posicao,int tamanho) {
	mesa[posicao].capacidade = tamanho;
}

int random() {
	return rand() % 3 + 2;
}