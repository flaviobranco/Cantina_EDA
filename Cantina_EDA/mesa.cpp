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
	bool expirado=false;
	while (aux_m != NULL)
	{
		if (aux_m->ocupantes != NULL) {
			while (aux_m->ocupantes != NULL) {
				if (aux_m->ocupantes->ciclos == 0) {
					aux_m->n_vagas++;
					bool expirado = true;
				}
				aux_m->ocupantes = aux_m->ocupantes->seguinte;
			}
		}
		if (aux_m->n_vagas >0 ) {//se houver vagas
			if (aux_m->ocupantes != NULL) { //se a mesa conter pessoas, senão curso_mesa==NULL
				while (aux_m->ocupantes->staff_ou_grupo && aux_m->ocupantes->seguinte != NULL) {//ver se há alunos,para evitar mesas com alunos de cursos diferentes
					aux_m->ocupantes = aux_m->ocupantes->seguinte;
				}
				if (aux_m->ocupantes != NULL&&!aux_m->ocupantes->staff_ou_grupo) { //se houver 
					curso_mesa = aux_m->ocupantes->curso;// registar os cursos
				}
				aux_m = mesas;
			}
			if (aux1 != NULL) {
				aux1 = fila;
				if (aux1->curso == curso_mesa || curso_mesa == "" || aux1->staff_ou_grupo) { //o primeiro é aluno ou staff? , se é aluno, só entra se tiverem o mesmo curso ou se o curso_mesa ou curso_fila for string vazia
					aux_m->n_vagas -= 1;//tirar o primeiro
					while (aux1->seguinte != NULL &&( (aux1->seguinte->curso == aux1->curso) || aux1->seguinte->staff_ou_grupo) && aux_m->n_vagas >0) {// verifica: fila vazia ou não E( se o aluno da fila é do mesmo curso do primeiro OU se é staff) E vagas ocupadas 
						aux_m->n_vagas -= 1;//tirar os seguintes
						aux1 = aux1->seguinte;
					}
					pessoa_cantina* aux2 = fila;
					if(aux1==NULL){
						fila = NULL;
					}
					else if (aux1->seguinte == NULL) {
						fila = aux1;
						//aux1 = NULL;// tirar pessoas da fila
					}
					else {
						fila = aux1->seguinte;
						aux1->seguinte = NULL;
					}
					if (aux_m->ocupantes == NULL) {
						aux_m->ocupantes = aux2;
					}
					else {
						while (aux_m->ocupantes != NULL) {
							if (aux_m->ocupantes->ciclos == 0) {
								pessoa_cantina* aux_mciclo = aux_m->ocupantes;
								while (aux_mciclo->ciclos == 0 && aux_mciclo != NULL) {
									aux_mciclo = aux_mciclo->seguinte;
								}
								if (aux_mciclo == NULL) {
									aux_m->ocupantes = NULL;
								}
								else {
									aux_m->ocupantes = aux_mciclo;
								}
							}
							aux_m->ocupantes = aux_m->ocupantes->seguinte;
						}
						aux_m->ocupantes = aux2;
					}
				}
			}
		}
		aux_m = aux_m->seguinte;
	}
	return fila;
}