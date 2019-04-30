#pragma once
#include "aluno_staff.h"
struct mesa {
	pessoa pessoa;
	int capacidade;
	int numero;
	int ciclo;
	// lista das pessoas
};

struct f_espera {
	pessoa pessoa;
	int quantidade;
};
//mesa
void cap_mesa(mesa* mesa, int i, int cap);
void ciclo_mesa(mesa* mesa, int i, int ciclo);
void enumerar_mesa(mesa* mesa, int i, int pos);
void por_pessoa_mesa(mesa* mesa, int posicao, pessoa pessoa);
void ver_pessoa_mesa(mesa* mesa, int posicao);
int random_mesa();
void mostrar_mesas(mesa* mesa,int posicao);
//fila
void inserir_tam_fila(f_espera* f_esp, int tam_fila);
int tm_fila(f_espera* f_esp);
void adicionar_fila_espera(f_espera* f_esp, int posicao, pessoa pes);
void retirar_fila_espera(f_espera* f_esp, int tam_fila);
void mostrar_fila_espera(f_espera* f_esp, int tam_fila)