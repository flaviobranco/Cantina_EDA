#pragma once
#include <string>
using namespace std;

struct pessoa {
	string nome;
	int numero_a;
	int grupo;
	int numero_f;
	int n_departamento;
	string curso;
	float plafond;
};

string random_line(const char* path);
void criar_aluno(pessoa*pessoa,int i);
void mostrar_aluno(pessoa* pessoa, int i);