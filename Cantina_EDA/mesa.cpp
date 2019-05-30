#include "Mesa.h"
#include"pessoa_cantina.h"
#include <iostream>
using namespace std;

mesa* cria_mesas() {
	int cap_cantina = rand() % 20 + 30;
	int n_mesas = 10;//alterar para rand
	mesa* primeira_mesa = NULL;
	for (int i = n_mesas; i >=1; i--) {
		//mesa
		mesa* nova = new mesa;
		int capacidade = rand() % 3 + 2;
		nova->capacidade = capacidade;
		nova->n_mesas = n_mesas;
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
	mesa* aux_m = mesas;
	pessoa_cantina* aux1 = fila;
	int n_grupo = aux1->n_grup;
	while (aux1->seguinte != NULL&&aux1->seguinte->n_grup==n_grupo) {
		aux1 = aux1->seguinte;
	}
	pessoa_cantina* aux2 = fila;
	fila = aux1->seguinte;
	aux1->seguinte = NULL;
	while (aux_m->ocupantes != NULL) {
		aux_m = aux_m->seguinte;
	}
	aux_m->ocupantes = aux2;
	

	return fila;
}