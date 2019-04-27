#pragma once
#include <string>
using namespace std;

struct pessoa {
	string nome;
	string aluno_ou_staff;
	int numero;
	int grupo;
	int n_departamento;
	string curso;
	float plafond;
	//bool especial;
	string especial;
};


string random_line(const char* path);
void criar_pessoa(pessoa*pessoa,int i);
void mostrar_pessoa(pessoa* pessoa, int i);
void aluno_ou_staff(pessoa* pessoa, int i);
void criar_número(pessoa* pessoa, int i); 
void criar_curso(pessoa* pessoa, int i);
void plafond(pessoa* pessoa, int i);
void adicionar_plafond(pessoa* pessoa, int i, float preco);
void especial(pessoa* pessoa, int i);