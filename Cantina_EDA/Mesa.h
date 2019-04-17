#pragma once
#include "aluno_staff.h"
struct mesa {
	int capacidade;
};
void inserir_mesas(mesa * mesa, int posicao,int tamanho);
int random();
void mostrar_mesas(mesa* mesa);