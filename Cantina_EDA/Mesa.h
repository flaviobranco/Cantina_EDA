#pragma once
#include "aluno_staff.h"
struct mesa {
	pessoa pessoa;
	int capacidade;
	int ocupacao;
	int numero;
	int ciclo;
	int quantidade;
	int cantina;
	// lista das pessoas
};

struct f_espera {
	pessoa pessoa;
	int quantidade;
};
//mesa
void q_mesa(mesa* mesa, int q_ms);
void cantina(mesa* mesa, int cant);
void cap_mesa(mesa* mesa, int i, int cap);
void ciclo_mesa(mesa* mesa, int i, int ciclo);
void enumerar_mesa(mesa* mesa, int i, int pos);
void por_pessoa_mesa(mesa* mesa, int posicao, pessoa pessoa);
void ver_pessoa_mesa(mesa* mesa, int posicao);
int random_mesa();
int n_quant_mesas(mesa* ms);
int cap_mesa(mesa* mesa, int i);
int ciclo_mesa(mesa* mesa, int i);
int n_mesa(mesa* mesa, int i);
int n_can(mesa* mesa);
void por_pessoa_mesa(mesa* mesa, int posicao,pessoa pessoa);
void mostrar_mesas(mesa* mesa);
//fila
void inserir_tam_fila(f_espera* f_esp, int tam_fila);
int tm_fila(f_espera* f_esp);
void adicionar_fila_espera(f_espera* f_esp, int pos_fila, pessoa* pes,int pos_aluno);
void retirar_fila_espera(f_espera* f_esp);
void mostrar_fila_espera(f_espera* f_esp);
void alterar_plafond(f_espera* fesp);