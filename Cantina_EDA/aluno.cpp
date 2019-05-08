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
	pessoa[i].numero = rand() % 400 + 100;//problema, os nú
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

void adicionar_plafond(pessoa pessoa, float preco) {
	float aux;
	cout << "Insere o plafond adicionado \n";
	cin >> aux;
	pessoa.plafond += aux;
}
void remover_plafond(pessoa pessoa, float aux) {
	pessoa.plafond += aux;
}

void especial(pessoa* pessoa, int i) {
	if (pessoa[i].aluno_ou_staff == "Estudante") {
		if (rand() % 100 < 5) {//possibilidade de 5% de ser especial
			pessoa[i].especial = true;
		}
		else {
			pessoa[i].especial = false;
		}
	}
}

void mostrar_ordenado(pessoa* pes) {

}

/*void criar_grupo(pessoa*pessoa,int n) {

}*/



void criar_pessoa(pessoa* pessoa, int i) {
	criar_nome(pessoa, i);
	aluno_ou_staff(pessoa, i);
	criar_número(pessoa, i);
	criar_curso(pessoa, i);
	plafond(pessoa, i);
	especial(pessoa, i);
}