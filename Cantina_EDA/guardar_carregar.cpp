#include"Mesa.h"
#include "Refeição.h"
#include "aluno_staff.h"
#include <iostream>
#include <fstream>//carregar/guardar ficheiros
#include <string>
//guardar

void guardar_refeicao(refeicao* ref) {

}

void guardar_fila_espera(f_espera* f_esp) {

}
void guardar_cantina(cantina* cant) {

}

void guardar_ciclos(int ciclo) {

}

void guardar(refeicao ref, f_espera f_esp, cantina cant,int ciclo) {
	guardar_refeicao(ref);
	guardar_fila_espera(f_esp);
	guardar_cantina(cant);
	guardar_ciclos(ciclo);
}


//carregar
bool tem_conteudo() {

}
void carregar_refeicao(refeicao ref) {

}

void carregar_fila_espera(f_espera f_esp) {

}
void carregar_cantina(cantina cant) {

}

void carregar_ciclos(int ciclo) {

}

void carregar(refeicao ref, f_espera f_esp, cantina cant, int ciclo) {
	if (tem_conteudo()) {
		carregar_refeicao(ref);
		carregar_fila_espera(f_esp);
		carregar_cantina(cant);
		carregar_ciclos(ciclo);
	}
	else {
		cout << "ERRO:Ficheiros necessários não estão presentes ou acessiveis na pasta da cantina" << endl;
	}
}