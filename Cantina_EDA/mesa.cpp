#include "Mesa.h"
#include"pessoa_cantina.h"
#include <iostream>
using namespace std;
/*
//fila
void gerar_fila(f_espera &f_esp){ //fase de inicialização
	f_esp.inicio = NULL;
	por_pessoa(f_esp);
}

void por_pessoa(f_espera &f_esp) {
	pessoa aux1 = new struct pessoa();
	gerar_pessoa(aux);
	aux1.seguinte = NULL;
	f_esp.inicio = aux1;
}


//mesa

void gerar_cantina(cantina &ms) {
	ms.inicio = NULL;
	gerar_mesa(ms);
}

void gerar_mesa(cantina &ms)
//de fila para a mesa*/

mesa* cria_mesas() {
	int n_mesas = 10;//alterar para rand
	mesa* primeira_mesa = NULL;
	for (int i = 1; i <= n_mesas; i++) {
		//mesa
		mesa* nova = new mesa;
		int capacidade = rand() % 3 + 2;
		nova->capacidade = capacidade;
		nova->n_vagas = capacidade;
		nova->ocupantes = NULL;
		nova->n_mesa = i;
		if (primeira_mesa == NULL) {
			primeira_mesa = nova;
			nova->seguinte = NULL;
		}
		else {
			nova->seguinte = primeira_mesa;
			primeira_mesa = nova;
		}
	}
	return primeira_mesa;
}

pessoa_cantina* coloca_pessoa_mesa(mesa* mesas, pessoa_cantina* fila) {
	pessoa_cantina* aux1 = fila;
	int n_grupo = aux1->n_grup;
	while (aux1->seguinte != NULL&&aux1->seguinte->n_grup==n_grupo) {
		aux1 = aux1->seguinte;
	}
	pessoa_cantina* aux2 = fila;
	fila = aux1->seguinte;
	aux1->seguinte = NULL;
	mesas->ocupantes = aux2;

	return fila;
}