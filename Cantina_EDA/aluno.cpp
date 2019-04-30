#include "aluno_staff.h"
#include <iostream>
#include <fstream>//carregar ficheiros
#include <string>
#include <time.h>
//#include<vector>

using namespace std;

std::string random_line(const char* path) //http://www.cplusplus.com/forum/general/114978/ -> from JLBorges, ler linhas aleatórias
{
	std::string selected;
	std::ifstream file(path);
	//
	std::string line;
	std::streamsize nlines = 0;
	while (std::getline(file, line))
	{
		++nlines;
		if (std::rand() % nlines == 0) selected = line;
	}
	//
	return selected;
}


void criar_nome(pessoa*pessoa,int i) {
		string pn= random_line("primeiro_nome.txt");
		string un= random_line("ultimo_nome.txt");
		pessoa[i].nome = pn+" "+un;
		
}
void aluno_ou_staff(pessoa* pessoa, int i) {
	int al_st = rand() % 2 + 1;
	al_st = rand() % 2 + 1;
	if (al_st == 1) {
		pessoa[i].aluno_ou_staff = "Estudante";
	}
	else if (al_st == 2) {
		pessoa[i].aluno_ou_staff = "Staff";
	}
}

void mostrar_pessoa(pessoa* pessoa, int i) {
	if (pessoa[i].aluno_ou_staff == "Estudante") {
		cout << pessoa[i].nome << ", " << pessoa[i].aluno_ou_staff << ", " << pessoa[i].curso << ", " << pessoa[i].numero <<", " << pessoa[i].plafond<<", "<< pessoa[i].especial << endl;
	}
	else {
		cout << pessoa[i].nome << ", " << pessoa[i].aluno_ou_staff << ", " << pessoa[i].numero << ", " << pessoa[i].plafond << endl;
	}
}


void criar_número(pessoa* pessoa, int i) {
	pessoa[i].numero = rand() % 500 + 100;//problema, os nú
}

void criar_curso(pessoa* pessoa, int i) {
	if (pessoa[i].aluno_ou_staff == "Estudante") {
		pessoa[i].curso = random_line("cursos.txt");
	}
}

/*void criar_grupo(pessoa* pessoa, int itam) {
}*/


void plafond(pessoa* pessoa, int i){
	pessoa[i].plafond = (rand() % 1000 + 10)*0.1;
}

void adicionar_plafond(pessoa* pessoa, int i, float preco) {
	cout << "Insere o plafond adicionado \n";
	cin >> pessoa[i].plafond;
}

void especial(pessoa* pessoa, int i) {
	if (pessoa[i].aluno_ou_staff == "Estudante") {
		if (rand() % 100 < 5) {//possibilidade de 5% de ser especial
			//pessoa[i].especial = true;
			pessoa[i].especial = "true";
		}
		else {
			//pessoa[i].especial = false;
			pessoa[i].especial = "false";
		}
	}
}

/*void criar_grupo(pessoa*pessoa,int n) {
	array
	for (int i = 1; i <= n; i++) {
		if (pessoa[i].aluno_ou_staff == "Estudante") {
			
		}
	}
}*/
void criar_pessoa(pessoa* pessoa, int i) {
	criar_nome(pessoa, i);
	aluno_ou_staff(pessoa, i);
	criar_número(pessoa, i);
	criar_curso(pessoa, i);
	plafond(pessoa, i);
	especial(pessoa, i);
}