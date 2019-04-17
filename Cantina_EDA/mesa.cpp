#include "Mesa.h"
#include <iostream>
using namespace std;

void inserir_mesas(mesa* mesa, int tamanho, int max_mesa) {
	int i = tamanho;
	int rdm;
	while (i > 0) {
		rdm = rand() % 3 + 2;
		++max_mesa;
		if (rdm > i) { //se a capacidade aleat�ria for superior ao n�mero de alunos que resta
			mesa[max_mesa].capacidade = i;
			i = 0;
		}
		else {
			mesa[max_mesa].capacidade = rdm;
			i -= rdm;
		}
	}
	cout << "N�mero de mesas = " << max_mesa << endl;
}

void mostrar_mesas(mesa* mesa, int max_mesa) {
	for (int i = 1; i <= max_mesa; i++) {
		cout << "Mesa n� " << i<<endl;
		cout << "Capacidade" << mesa[i].capacidade << endl;
	}
}