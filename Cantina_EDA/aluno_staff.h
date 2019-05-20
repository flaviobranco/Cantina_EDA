#pragma once
#include <string>
using namespace std;

struct pessoa {
	string aluno_ou_staff;// se � "Estudante" ou "Staff"
	struct grupo {//criar grupos de alunos de uma s� vez � mais eficiente
		bool especial;//o aluno � especial?
		int n_grupo;
		int n_elementos; //Um grupo entre 2 a 10(exceto se especial for true, nesse caso s� ter� apenas 1)
		string curso; //os grupos tem em comum o mesmo curso
		struct aluno {// pilha de alunos
			string nome;
			int numero;
			float plafond;
			aluno* seguinte;//se especial==true, seguinte ser� null
		}; aluno* inicio;
	};
	struct departamento {//grupo do staff
		int n_elementos;//Um departamento entre 2 a 10
		int n_departamento; 
		struct staff {
			string nome;
			int numero;
			float plafond;
			staff* seguinte;
		}; staff* inicio;
	}; 
};


/*string random_line(const char* path);
void novo_grupoa();
void gerar_pessoa(pessoa pes);
void remover_pessoa();
void altura(pessoa pes);
bool p_vazia(pessoa pes);
//bool aluno(pessoa pes);
bool especial(grupo a);