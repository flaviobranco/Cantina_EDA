
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
	if (pes.inicio == NULL) {
		return true;
	}
	else {
		return false;
	}
}
void nova_pessoa(pessoa& pes) {
	pes.inicio = NULL;
}


void aluno_ou_staff(pessoa &pes) {
	pessoa::check* aux = new pessoa::check();
	if ((rand()% 100+1) <50) {
		aux->aluno_ou_staff= "Estudante";
	}
	else {
		aux->aluno_ou_staff = "Staff";
	}
	pes.inicio = aux;
}

bool aluno(pessoa& pes) {
	pessoa::check* aux = pes.inicio;
	if (aux == "Estudante") {
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
	}
	else
	{
		pessoa::departamento* aux = new pessoa::departamento();
		aux->n_grupo = rand() % 401 + 300;
	}
	pes.inicio = aux;
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
	pes.inicio->aux;
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
	pes.inicio = aux;
}

bool e_especial(pessoa& pes) {
	pessoa::grupo* aux = pes.inicio;
	return aux->especial;
}

void criar_nome(pessoa &pessoa) {
		string pn= random_line("primeiro_nome.txt");
		string un= random_line("ultimo_nome.txt");
		
}
//aluno


void geraraluno(pessoa& pes) {
	void 
}
void gerar_pessoa(pessoa& pes) {
	aluno_ou_staff(pes);
	if (aluno(pes)) {
		especial(pes);
	}
	else {

	}
}