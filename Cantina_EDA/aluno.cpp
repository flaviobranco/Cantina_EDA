
#include "aluno_staff.h"
#include <iostream>
#include <fstream>//carregar ficheiros
#include <string>
#include <time.h>
//#include<vector>

using namespace std;

std::string random_line(const char* path) //http://www.cplusplus.com/forum/general/114978/ -> from JLBorges, ler linhas aleatórias
{
	string selected;
	ifstream file(path);
	//
	string line;
	streamsize nlines = 0;
	while (getline(file, line))
	{
		++nlines;
		if (rand() % nlines == 0) selected = line;
	}
	//
	return selected;
}
//pessoa

bool p_vazia(pessoa *pes) {
	if (pes->aluno_ou_staff == NULL) {
		return true;
	}
	else {
		return false;
	}
}

void aluno_ou_staff(pessoa *pes) {
	if ((rand()% 100+1) <50) {
		pes->aluno_ou_staff= true;//aluno
	}
	else {
		pes->aluno_ou_staff = false;//staff
	}
}

bool aluno(pessoa *pes) {
	return pes->aluno_ou_staff;
}

void gerar_id(pessoa *pes) {
	if (aluno(pes)) {
		pes->grup->n_grupo = rand() % 401 + 100;
	}
	else
	{
		pes->depart->n_departamento = rand() % 401 + 100;
	}
}
void especial(pessoa *pes) {
	if (aluno(pes)) {
		pessoa::grupo * aux = pes->grup;
		if (rand() % 100 + 1 < 5) {
			aux->especial = true;
		}
		else {
			aux->especial = false;
		}
	}
}

bool e_especial(pessoa* pes) {
	return pes->grup->especial;
}

void gerar_elemen(pessoa *pes) {
	if (aluno(pes)) {
		pessoa::grupo* aux = pes->grup;
		if (e_especial(pes)) {
			aux->n_elementos = 1;
		}
		else {
			aux->n_elementos = rand()%8+2;
		}
	}
	else {
		pessoa::departamento* aux = pes->depart;
		aux->n_elementos= rand() % 8 + 2;
	}
}

int num_elementos(pessoa* pes) {
	if (aluno(pes)) {
		pessoa::grupo* aux = pes->grup;
		return aux->n_elementos;
	}
	else {
		pessoa::departamento* aux = pes->depart;
		return aux->n_elementos;
	}
}
//grupo



void criar_nome(pessoa *pes) {
	if (aluno(pes)) {
		pessoa::grupo::aluno* aux = new struct pessoa::grupo::aluno();
		string pn = random_line("pr.txt");
		string un = random_line("ul.txt");
		aux->nome = pn + " " + un;
		aux->seguinte = pes->grup->inicio;
		pes->grup->inicio= aux;
	}
	else {
		pessoa::departamento::staff* aux = new struct pessoa::departamento::staff();
		string pn = random_line("pr.txt");
		string un = random_line("ul.txt");
		aux->nome = pn + " " + un;
		aux->seguinte = pes->depart->inicio;
		pes->depart->inicio = aux;
	}
}

void criar_numero(pessoa* pes) {
	if (aluno(pes)) {
		pessoa::grupo::aluno* aux = new struct pessoa::grupo::aluno();
		aux->numero = rand() % 89000 + 10000;
		aux->seguinte = pes->grup->inicio;
		pes->grup->inicio = aux;
	}
	else {
		pessoa::departamento::staff* aux = new struct pessoa::departamento::staff();
		aux->numero = rand() % 8900 + 1000;
		aux->seguinte = pes->depart->inicio;
		pes->depart->inicio = aux;
	}
}

void criar_plafond(pessoa* pes) {
	if (aluno(pes)) {
		pessoa::grupo::aluno* aux = new struct pessoa::grupo::aluno();
		aux->plafond = (rand() % 1000 + 10) *0.1;
		aux->seguinte = pes->grup->inicio;
		pes->grup->inicio = aux;
	}
	else {
		pessoa::departamento::staff* aux = new struct pessoa::departamento::staff();
		aux->plafond = (rand() % 1000 + 10) *0.1;
		aux->seguinte = pes->depart->inicio;
		pes->depart->inicio = aux;
	}
}

void gerar_curso(pessoa* pes) {
	if (aluno(pes)) {
		pessoa::grupo* aux = pes->grup;
		string curso = random_line("cursos.txt");
		aux->curso = curso;
	}
}

void gerar_ciclos(pessoa *pes) {
	if (aluno(pes)) {
		pessoa::grupo* aux = pes->grup;
		aux->ciclos = rand() % 3 + 2;
	}
	else {
		pessoa::departamento* aux = pes->depart;
		aux->ciclos = rand() % 3 + 2;
	}
}

void gerar_pessoa(pessoa &pes) {
	pessoa* aux = NULL;
	aluno_ou_staff(aux);
	especial(aux);
	gerar_id(aux);
	gerar_elemen(aux);
	gerar_curso(aux);
	gerar_ciclos(aux);
	for (int i = 1; i <= num_elementos(aux); i++) {
		criar_nome(aux);
		criar_numero(aux);
		criar_plafond(aux);
	}
	pes.seguinte = aux;
}

//mostrar
string mostrar_nome(pessoa* pes) {
	if (aluno(pes)) {
		return pes->grup->inicio->nome;
	}
	else {
		return pes->depart->inicio->nome;
	}
}
string mostrar_al_ou_stf(pessoa * pes) {
	if (aluno(pes)) {
		return "Estudante";
		}
	else {
		return "Staff";
	}
}

string mostrar_curso(pessoa* pes) {
	return pes->grup->curso;
}

int mostrar_grupo(pessoa* pes) {
	return pes->grup->n_grupo;
}

int mostrar_departamento(pessoa* pes) {
	return pes->depart->n_departamento;
}

int mostrar_numero(pessoa* pes){
	if (aluno(pes)) {
		return pes->grup->inicio->numero;
	}
	else {
		return pes->depart->inicio->numero;
	}
}

int mostrar_ciclos(pessoa* pes) {
	if (aluno(pes)) {
		return pes->grup->ciclos;
	}
	else {
		return pes->depart->ciclos;
	}
}

float mostrar_plafond(pessoa* pes) {
	if (aluno(pes)) {

		return pes->grup->inicio->plafond;
	}
	else {
		return pes->depart->inicio->plafond;
	}
}


void mostrar_pessoa(pessoa &pes) {
	if (p_vazia(pes.seguinte)) {
		cout << "ERRO: Vazio" << endl;
	}
	else {
		pessoa* aux = pes.seguinte;
		if (aluno(aux)) {
			do{
				cout << mostrar_nome(aux) << ", " << mostrar_al_ou_stf(aux) << ", " << mostrar_curso(aux) << ", " << mostrar_grupo(aux) << ", " << mostrar_numero(aux) << ", Duração, " << mostrar_ciclos(aux) << ", " << mostrar_plafond(aux) << endl;
				aux->grup->inicio= aux->grup->inicio->seguinte;
			} while (aux->grup->inicio != NULL);
		}
		else {
			do{
				cout << mostrar_nome(aux) << ", " << mostrar_al_ou_stf(aux) << ", Departamento: " << mostrar_departamento(aux) << ", " << mostrar_numero(aux) << ", Duração, " << mostrar_ciclos(aux) << ", " << mostrar_plafond(aux) << endl;
				aux->depart->inicio = aux->depart->inicio->seguinte;
			} while (aux->depart->inicio != NULL);
		}
	}
}
