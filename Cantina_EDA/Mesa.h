#pragma once
#include "aluno_staff.h"
struct mesa {
	int capacidade;

};

void inserir_mesas(mesa * mesa, int tamanho, int max_mesa);
void mostrar_mesas(mesa* mesa, int max_mesa);