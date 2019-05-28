#ifndef MESA_H
#define MESA_H
#include "pessoa_cantina.h"

struct mesa {
	int n_mesas;
	int n_mesa;
	int capacidade;
	int n_vagas;
	pessoa_cantina* ocupantes;
	mesa* seguinte;
};

mesa* cria_mesas();
pessoa_cantina* coloca_pessoa_mesa(mesa* mesas, pessoa_cantina* fila);
#endif