#include "Mesa.h"
#include"aluno_staff.h"
#include <iostream>
using namespace std;

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
//de fila para a mesa