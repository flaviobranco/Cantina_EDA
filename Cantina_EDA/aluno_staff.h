#pragma once
#include <string>
using namespace std;

struct pessoa {
	string aluno_ou_staff;// se é "Estudante" ou "Staff"
	struct grupo {//criar grupos de alunos de uma só vez é mais eficiente
		bool especial;//o aluno é especial?
		int n_grupo;
		int n_elementos; //Um grupo entre 2 a 10(exceto se especial for true, nesse caso só terá apenas 1)
		string curso; //os grupos tem em comum o mesmo curso
		int ciclos;
		struct aluno {// pilha de alunos
			string nome;
			int numero;
			float plafond;
			aluno* seguinte;
		}; aluno* inicio;
	};
	grupo* grup;
	struct departamento {//grupo do staff
		int n_elementos;//Um departamento entre 2 a 10
		int n_departamento;
		int ciclos;
		struct staff {
			string nome;
			int numero;
			float plafond;
			staff* seguinte;
		}; staff* inicio;
	};
	departamento* depart;
	pessoa* seguinte;
};


void gerar_pessoa(pessoa& pes);
void mostrar_pessoa(pessoa& pes);
/*string random_line(const char* path);
void novo_grupoa();
void gerar_pessoa(pessoa pes);
void remover_pessoa();
void altura(pessoa pes);
bool p_vazia(pessoa pes);
//bool aluno(pessoa pes);
bool especial(grupo a);*/