#pragma once
#include <string>
using namespace std;

struct pessoa {
	string nome;
	string aluno_ou_staff;
	int numero_a;
	int grupo;
	int numero_f;
	int n_departamento;
	string curso;
	float plafond;
};

string random_line(const char* path);
void criar_pessoa(pessoa*pessoa,int i);
void mostrar_pessoa(pessoa* pessoa, int i);
void aluno_ou_staff(pessoa* pessoa, int i)