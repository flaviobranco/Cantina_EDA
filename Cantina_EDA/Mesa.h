#pragma once
#include "aluno_staff.h"
struct f_espera {
	pessoa f_pes;
	f_espera* anterior;
}; f_espera* apTopo;

struct cantina {
	int cant;
	struct mesa {
		int capacidade;
		struct m_pes {
			pessoa m_pes;
			m_pes* seguinte;
		}; m_pes* inicio;
		mesa* seguinte;
	}; mesa* inicio;
};

//fila 
void nova_pessoa_fila(f_espera f_esp)
//mesa

//da fila para a mesa
bool excesso(cantina cant, f_espera f_pes);
