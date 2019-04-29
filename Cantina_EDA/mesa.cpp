#include "Mesa.h"
#include"aluno_staff.h"
#include <iostream>
using namespace std;

void inserir_mesas(mesa* mesa, int posicao,int tamanho) {
	mesa[posicao].capacidade = tamanho;
}

void mostrar_mesas(mesa* mesa, int posicao) {
	cout << "Nº de Mesas: " << posicao << endl;
	for (int i = 1; i <= posicao; i++) {
		cout << "Mesa nº " << i << endl;
		cout << mesa[i].capacidade << " alunos" << endl;

	}
}

int random_mesa() {
	return rand() % 5 + 2;
}

void adicionar_fila_espera(f_espera* espera, int posicao, pessoa*pessoa) {//
	
}