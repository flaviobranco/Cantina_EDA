#pragma once
#include <string>
using namespace std;

struct pessoa { //grupo de alunos ou staff
	string aluno ou staff;// Escolhe se é "Estudante" ou "Staff", Um será um grupo entre 2 a 10(exceto se especial for true, nesse caso só terá apenas 1)
	bool especial;//o aluno é especial? se for um grupo de staff, a resposta é imediatamente falsa
	struct grupo {//criar grupos de alunos de uma só vez é mais eficiente
		int n_grupo;
		struct aluno {// pilha de alunos
			string nome;
			int numero;
			string curso;
			float plafond;
			aluno* seguinte;//se especial==true, seguinte será null
		}; aluno* inicio;
	};
	struct departamento{//grupo do staff
		int n_elementos;
		int n_departamento;
		struct staff {
			string nome;
			int numero;
			int n_departamento;
			float plafond;
			staff* seguinte;
		}; staff* inicio;
	};
}; 


string random_line(const char* path);
void nova_pessoa();
void gerar_pessoa(pessoa pes);
void altura(pessoa pes);