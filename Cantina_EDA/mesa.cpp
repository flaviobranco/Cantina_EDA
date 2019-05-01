#include "Mesa.h"
#include"aluno_staff.h"
#include <iostream>
using namespace std;
//mesa
void q_mesa(mesa* mesa,int q_ms) {
	mesa[1].quantidade = q_ms;
}
void cantina(mesa* mesa, int cant) {
	mesa[1].cantina = cant;
}
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

pessoa por_pessoa_mesa(mesa* mesa, int posicao) {
	return mesa[posicao].pessoa;
} 

int n_mesa(mesa* mesa, int i) {
	return mesa[i].numero;
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
void mostrar_mesas(mesa* ms) {
	int tam = n_quant_mesas(ms);
	cout << "Nº de Mesas: " << tam << endl;
	for (int i = 1; i <= tam; i++) {
		if (ms[i].numero != 0) {
			cout << "Mesa nº " << n_mesa(ms, i);
			cout << " (Capacidade: " << cap_mesa(ms, i) << " alunos): " << endl;
		}
		cout << "\t";
		ver_pessoa_mesa(ms, i);
	}
}

int random_mesa() {
	return rand() % 3 + 2;
}
int n_quant_mesas(mesa* ms) {
	return ms[1].quantidade;
}
int cap_mesa(mesa* mesa, int i) {
	return mesa[i].capacidade;
}
int ciclo_mesa(mesa* mesa, int i) {
	return mesa[i].ciclo;
}

int n_can(mesa *mesa) {
	return mesa[1].cantina;
}

//fila
void inserir_tam_fila(f_espera* f_esp, int tam_fila) {//
	f_esp[1].quantidade = tam_fila;
}
int tm_fila(f_espera* f_esp) {
	return f_esp[1].quantidade;
}
void adicionar_fila_espera(f_espera* f_esp, int pos_fila, pessoa* pes,int pos_aluno) {//
	f_esp[pos_fila].pessoa = pes[pos_aluno];
}

void retirar_fila_espera(f_espera* f_esp) {
	int tam_fila = tm_fila(f_esp);
	for (int i = 2; i <= tam_fila; i++) {
		f_esp[i - 1].pessoa = f_esp[i].pessoa;
	}
	f_esp[1].quantidade -= 1;
}

void mover_especial(f_espera* f_esp, int tam_fila) {

}
void mostrar_fila_espera(f_espera* f_esp) {
	int tam_fila = tm_fila(f_esp);
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

void alterar_plafond(f_espera* fesp) {
	int tam_file = tm_fila(fesp);
	int aluno;
	float preco;
	cout << "insere o n_aluno" << endl;
	cin >> aluno;
	for (int i = 1; i <= tam_file; i++) {
		pessoa pes = fesp[i].pessoa;
		if (pes.numero == aluno) {
			cout << "insere o preco" <<endl ;
			cin >> preco;
			pes.plafond += preco;
		}
	}

}