
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
bool p_vazia(pessoa& pes) {
	if (pes == NULL) {
		return true;
	}
	else {
		return false;
	}
}
/*void nova_pessoa(pessoa& pes) {
	pes = 0;
}*/


void aluno_ou_staff(pessoa &pes) {
	pessoa aux = new pessoa;
	if ((rand()% 100+1) <50) {
		aux->aluno_ou_staff= "Estudante";
	}
	else {
		aux->aluno_ou_staff = "Staff";
	}
	pes = aux;
}

bool aluno(pessoa& pes) {
	pessoa aux = pes;
	if (aux->aluno_ou_staff == "Estudante") {
		return true;
	}
	else {
		return false;
	}
}

void gerar_id(pessoa& pes) {
	if (aluno(pes)) {
		pessoa::grupo* aux = new pessoa::grupo();
		aux->n_grupo = rand() % 401 + 300;
		pes = aux;
	}
	else
	{
		pessoa::departamento* aux = new pessoa::departamento();
		aux->n_departamento = rand() % 401 + 300;
		pes = aux;
	}
}
bool e_especial(pessoa& pes) {
	pessoa::grupo* aux = pes;
	return aux->especial;
}

void gerar_elemen(pessoa& pes) {
	if (aluno(pes)) {
		pessoa::grupo* aux = new pessoa::grupo();
		if (e_especial(pes)) {
			aux->n_elementos = 1;
		}
		else {
			aux->n_elementos = rand()%8+2;
		}
	}
	else {
		pessoa::departamento* aux = new pessoa::departamento();
		aux->n_elementos= rand() % 8 + 2;
	}
	pes=aux;
}

int num_elementos(pessoa* pes) {
	if (aluno(pes)) {
		pessoa::grupo* aux = pes;
		return aux->n_elementos;
	}
	else {
		pessoa::departamento* aux = pes;
		return aux->n_elementos;
	}
}
//grupo
void especial(pessoa& pes) {
	pessoa::grupo* aux = new pessoa::grupo();
	if ((rand()%100+1)>5){
		aux->especial = false;
	}
	else {
		aux->especial = true;
	}
	pes= aux;
}

bool e_especial(pessoa& pes) {
	pessoa::grupo* aux = pes;
	return aux->especial;
}

void criar_nome(pessoa &pes) {
	if (aluno(pes)) {
		pessoa::grupo::aluno* aux = new struct pessoa::grupo::aluno();
		pessoa::grupo* aux2 = pes;
		string pn = random_line("primeiro_nome.txt");
		string un = random_line("ultimo_nome.txt");
		aux->nome = pn + " " + un;
		aux->seguinte = aux2->inicio;
		aux2->inicio = aux;
	}
	else {
		pessoa::departamento::staff* aux = new struct pessoa::departamento::staff();
		pessoa::departamento* aux2 = pes;
		string pn = random_line("primeiro_nome.txt");
		string un = random_line("ultimo_nome.txt");
		aux->nome = pn + " " + un;
		aux->seguinte = aux2->inicio;
		aux2->inicio = aux;
	}
}

void criar_numero(pessoa& pes) {
	if (aluno(pes)) {
		pessoa::grupo::aluno* aux = new struct pessoa::grupo::aluno();
		pessoa::grupo* aux2 = pes;
		aux->numero = rand() % 89000 + 10000;
		aux->seguinte = aux2->inicio;
		aux2->inicio = aux;
	}
	else {
		pessoa::departamento::staff* aux = new struct pessoa::departamento::staff();
		pessoa::departamento aux2 = pes;
		string pn = random_line("primeiro_nome.txt");
		string un = random_line("ultimo_nome.txt");
		aux->numero = rand() % 8900 + 1000;
		aux->seguinte = aux2->inicio;
		aux2->inicio = aux;
	}
}

void criar_plafond(pessoa& pes) {
	if (aluno(pes)) {
		pessoa::grupo::aluno* aux = new struct pessoa::grupo::aluno();
		pessoa::grupo* aux2 = pes;
		aux->plafond = (rand() % 1000 + 1) * (0.1);
		aux->seguinte = aux2->inicio;
		aux2->inicio = aux;
	}
	else {
		pessoa::departamento::staff* aux = new struct pessoa::departamento::staff();
		pessoa::departamento* aux2 = pes;
		aux->plafond = (rand() % 1000 + 1) * (0.1);
		aux->seguinte = aux2->inicio;
		aux2->inicio = aux;
	}
}

void gerar_curso(pessoa& pes) {
	if (aluno(pes)) {
		pessoa::grupo* aux = new struct pessoa::grupo();
		pessoa* aux2 = pes;
		string cuso = random_line("cursos.txt");
		aux->curso = curso;
		aux2->inicio = aux;
	}
}

void gerar_ciclos(pessoa& pes) {
	if (aluno(pes)) {
		pessoa::grupo* aux = pes;
		aux->ciclos=rand()
	}
}

void gerar_pessoa(pessoa& pes) {
	aluno_ou_staff(pes);
	especial(pes);
	gerar_id(pes);
	gerar_elemen(pes);
	gerar_curso(pes);
	gerar_ciclos(pes);
	for (int i = 1; i <= num_elementos(pes); i++) {
		criar_nome(pes);
		criar_numero(pes);
		criar_plafond(pes);
	}
}

//mostrar
string mostrar_nome(pessoa& pes) {
	if (aluno(pes)) {
		pessoa::grupo::aluno* aux = pes;
		return aux->nome;
	}
	else {
		pessoa::departamento::staff* aux = pes;
		return aux->nome;
	}
}
string mostrar_al_ou_stf(pessoa & pes) {
		pessoa aux = pes;
		return aux.aluno_ou_staff;
}

string mostrar_curso(pessoa& pes) {
	pessoa::grupo* aux = pes;
	return aux->curso;
}

int mostrar_grupo(pessoa& pes) {
	pessoa::grupo* aux = pes;
	return aux->n_grupo;
}

int mostrar_departamento(pessoa& pes) {
	pessoa::departamento* aux = pes;
	return aux->n_departamento;
}

int mostrar_numero(pessoa &pes){
	if (aluno(pes)) {
		pessoa::grupo::aluno* aux = pes;
		return aux->numero;
	}
	else {
		pessoa::departamento::staff* aux = pes;
		return aux->numero;
	}
}

int mostrar_ciclos(pessoa& pes) {
	if (aluno(pes)) {
		pessoa::grupo* aux = pes;
		return aux->ciclos;
	}
	else {
		pessoa::departamento* aux = pes;
		return aux->ciclos;
	}
}

float mostrar_plafond(pessoa& pes) {
	if (aluno(pes)) {
		pessoa::grupo::aluno* aux = pes;
		return aux->plafond;
	}
	else {
		pessoa::departamento::staff* aux = pes;
		return aux->plafond;
	}
}


void mostrar_pessoa(pessoa& pes) {
	if (p_vazia(pes)) {
		cout << "ERRO: Vazio" << endl;
	}
	else {
		pessoa aux = pes;
		if (aluno(pes)) {
			pessoa::grupo::aluno* aux1 = aux;
			while (aux1 != NULL) {
				cout << mostrar_nome(aux) << ", " << mostrar_al_ou_stf(aux) << ", " << mostrar_curso(aux) << ", " << mostrar_grupo(aux) << ", " << mostrar_numero(aux) << ", Duração, " << mostrar_ciclos(aux) << ", " << mostrar_plafond(aux) << endl;
				aux1 = aux1->seguinte;
			}
		}
		else {
			pessoa::departamento::staff* aux1 = aux;
			while (aux1 != NULL) {
				cout << mostrar_nome(aux) << ", " << mostrar_al_ou_stf(aux) << ", Departamento: " << mostrar_departamento(aux) << ", " << mostrar_numero(aux) << ", Duração, " << mostrar_ciclos(aux) << ", " << mostrar_plafond(aux) << endl;
				aux1 = aux1->seguinte;
			}
		}
	}
}