#include "Mesa.h"
#include"aluno_staff.h"
#include <iostream>
using namespace std;
//mesa
void cap_mesa(mesa* mesa, int i, int cap) {
	mesa[i].capacidade = cap;
}
void ciclo_mesa(mesa* mesa, int i, int ciclo) {
	mesa[i].ciclo = ciclo;
}
void enumerar_mesa(mesa* mesa, int i,int pos) {
	mesa[i].numero = pos;
}
void por_pessoa_mesa(mesa* mesa, int posicao, pessoa pessoa) {
	mesa[posicao].pessoa = pessoa;
}
void ver_pessoa_mesa(mesa* mesa, int posicao) {
	pessoa pes = mesa[posicao].pessoa;
	if (pes.aluno_ou_staff == "Estudante") {
		cout << pes.nome << ", " << pes.aluno_ou_staff << ", " << pes.curso << ", " << pes.numero << ", " << pes.plafond << endl;
	}
	else {
		cout << pes.nome << ", " << pes.aluno_ou_staff << ", " << pes.numero << ", " << pes.plafond << endl;
	}
}
void mostrar_mesas(mesa* mesa, int tam) {
	cout << "Nº de Mesas: " << tam << endl;
	for (int i = 1; i <= tam; i++) {
		if (mesa[i].numero != NULL) {
			cout << "Mesa nº " << i;
		}
		if (mesa[i].capacidade != NULL) {
			cout <<" (Capacidade: "<<mesa[i].capacidade << " alunos): " << endl;
		}
		cout << "\t";
		ver_pessoa_mesa(mesa, i);
	}
}

int random_mesa() {
	return rand() % 5 + 2;
}
//fila
void inserir_tam_fila(f_espera* f_esp, int tam_fila) {//
	f_esp[1].quantidade = tam_fila;
}
int tm_fila(f_espera* f_esp) {
	return f_esp[1].quantidade;
}
void adicionar_fila_espera(f_espera* f_esp, int posicao, pessoa pes) {//
	f_esp[posicao].pessoa = pes;
}

void retirar_fila_espera(f_espera* f_esp,int tam_fila) {
	for (int i = 2; i <= tam_fila; i++) {
		f_esp[i - 1].pessoa = f_esp[i].pessoa;
	}
	f_esp[1].quantidade -= 1;
}

void mover_especial(f_espera* f_esp, int tam_fila) {

}
void mostrar_fila_espera(f_espera* f_esp, int tam_fila) {
	for (int i = 1; i <= tam_fila; i++) {
		pessoa pes = f_esp[i].pessoa;
		if (pes.aluno_ou_staff == "Estudante") {
			cout << pes.nome << ", " << pes.aluno_ou_staff << ", " << pes.curso << ", " << pes.numero << ", " << pes.plafond << endl;
		}
		else {
			cout << pes.nome << ", " << pes.aluno_ou_staff << ", " << pes.numero << ", " << pes.plafond << endl;
		}
	}
}