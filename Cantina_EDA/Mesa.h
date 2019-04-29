#pragma once
#include "aluno_staff.h"
struct mesa {
	pessoa pessoa;
	int capacidade;
	int numero;
	int ocupacao;
	// lista das pessoas
};

struct f_espera {
	pessoa pessoa;
	int posicao;
};
void inserir_mesas(mesa * mesa, int posicao,int tamanho);
int random_mesa();
void mostrar_mesas(mesa* mesa,int posicao);
void adicionar_fila_espera(f_espera* espera, int posicao, pessoa* pessoa);