#pragma once
struct mesa {
	int capacidade;
	int numero;
	int ocupacao;
	// lista das pessoas
};
void inserir_mesas(mesa * mesa, int posicao,int tamanho);
int random_mesa();
void mostrar_mesas(mesa* mesa,int posicao);
