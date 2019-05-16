#pragma once
#include <string>
using namespace std;

struct pessoa { //grupo de alunos ou staff
	string aluno ou staff;// Escolhe se � "Estudante" ou "Staff", Um ser� um grupo entre 2 a 10(exceto se especial for true, nesse caso s� ter� apenas 1)
	bool especial;//o aluno � especial? se for um grupo de staff, a resposta � imediatamente falsa
	struct grupo {//criar grupos de alunos de uma s� vez � mais eficiente
		int n_grupo;
		struct aluno {// pilha de alunos
			string nome;
			int numero;
			string curso;
			float plafond;
			aluno* seguinte;//se especial==true, seguinte ser� null
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