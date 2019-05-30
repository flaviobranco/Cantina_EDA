#include "Mesa.h"
#include"pessoa_cantina.h"
#include <iostream>
using namespace std;


mesa* cria_mesas() {
	int cap_cantina = rand() % 20 + 30;
	int n_mesas = 0;
	int *capacidade=new int [26];
	while (cap_cantina != 0) {
		n_mesas += 1;
		capacidade[n_mesas] = rand() % 3 + 2;
		cap_cantina -= capacidade[n_mesas];
		while (cap_cantina == 1 || cap_cantina < 0) {
			cap_cantina += capacidade[n_mesas];
			capacidade[n_mesas] = rand() % 3 + 2;
			cap_cantina -= capacidade[n_mesas];
		}
	}
	mesa* primeira_mesa = NULL;
	for (int i = 1; i <=n_mesas; i++) {
		//mesa
		mesa* nova = new mesa;
		nova->capacidade = capacidade[n_mesas-i+1];
		nova->n_mesas = n_mesas;
		nova->n_vagas = capacidade[n_mesas-i+1];
		nova->ocupantes = NULL;
		nova->n_mesa = n_mesas-i+1;
		if (primeira_mesa == NULL) {
			primeira_mesa = nova;
			nova->seguinte = NULL;
		}
		else {
			nova->seguinte = primeira_mesa;
			primeira_mesa = nova;
		}
	}
	return primeira_mesa;
}

pessoa_cantina* coloca_pessoa_mesa(mesa* mesas, pessoa_cantina* fila) {
	mesa* aux_m = mesas;
	pessoa_cantina* aux1 = fila;
	string curso_mesa = "";//"nulo" se não houver alunos na mesa
	string curso_fila = "";//"nulo" se não houver alunos nas primeiras pessoas
	while (aux_m != NULL)
	{
		if (aux_m->n_vagas >0) {//se houver vagas
			if (aux_m->ocupantes != NULL) { //se a mesa conter pessoas, senão curso_mesa==NULL
				mesa* aux_m2 = mesas;// auxiliar
				while (aux_m2->ocupantes->staff_ou_grupo && aux_m2->ocupantes != NULL) {//ver se há alunos,para evitar mesas com alunos de cursos diferentes
					aux_m2->ocupantes = aux_m2->ocupantes->seguinte;
				}
				if (aux_m2->ocupantes != NULL&&!aux_m2->ocupantes->staff_ou_grupo) { //se houver 
					curso_mesa = aux_m2->ocupantes->curso;// registar os cursos
				}
			}
			if (aux1 != NULL) {
				int quant_cap_max = 5; //capacidade mesa máxima=5
				pessoa_cantina* aux1_a = fila;// auxiliar
				while (aux1_a != NULL && aux1_a->staff_ou_grupo && aux1_a != NULL && quant_cap_max != 0) {//ver se há alunos,para evitar mesas com alunos de cursos diferentes
					aux1_a = aux1_a->seguinte;
					quant_cap_max -= 1;
				}
				if (aux1_a != NULL&&!aux1_a->staff_ou_grupo) { //se houver 
					curso_fila = aux1_a->curso;// registar os cursos
				}
				aux1 = fila;
				if (curso_fila == curso_mesa || curso_mesa == "" || curso_fila=="") { //o primeiro é aluno ou staff? , se é aluno, só entra se tiverem o mesmo curso ou se o curso_mesa ou curso_fila for string vazia
					aux_m->n_vagas -= 1;//tirar o primeiro
					while (aux1 != NULL && aux1->seguinte != NULL &&( (aux1->seguinte->curso == curso_fila) || aux1->seguinte->staff_ou_grupo) && aux_m->n_vagas >0) {// verifica: fila vazia ou não E( se o aluno da fila é do mesmo curso do primeiro ou se é staff) E vagas ocupadas 
						aux_m->n_vagas -= 1;//tirar os seguintes
						aux1 = aux1->seguinte;
					}
					pessoa_cantina* aux2 = fila;
					if (aux1->seguinte == NULL) {
						fila = aux1;
						aux1 = NULL;// tirar pessoas da fila
					}
					else {
						fila = aux1->seguinte;
						aux1->seguinte = NULL;
					}
					if (aux_m->ocupantes == NULL) {
						aux_m->ocupantes = aux2;
					}
					else {
						aux_m->ocupantes->seguinte = aux2;
						aux_m->ocupantes = aux_m->ocupantes->seguinte;
					}
				}
			}
		}
		aux_m = aux_m->seguinte;
	}
	return fila;
}