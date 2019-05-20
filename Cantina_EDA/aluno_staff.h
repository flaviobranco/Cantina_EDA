#pragma once
#include <string>
using namespace std;
struct pessoa { //grupo de alunos ou staff
	struct check { //neces�rio para verificar duas condi��es essenciais:
		string aluno_ou_staff;// Escolhe se � "Estudante" ou "Staff", Um ser� um grupo entre 2 a 10(exceto se especial for true, nesse caso s� ter� apenas 1)
	};
	struct grupo {//criar grupos de alunos de uma s� vez � mais eficiente
		bool especial;//o aluno � especial?
		int n_grupo;
		int n_elementos;
		struct aluno {// pilha de alunos
			string nome;
			int numero;
			string curso;
			float plafond;
			aluno* seguinte;//se especial==true, seguinte ser� null
		}; aluno* inicio;
	};
	struct departamento {//grupo do staff
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
	pessoa* seguinte;
}; pessoa* actual;


/*string random_line(const char* path);
void novo_grupoa();
void gerar_pessoa(pessoa pes);
void remover_pessoa();
void altura(pessoa pes);
bool p_vazia(pessoa pes);
//bool aluno(pessoa pes);
bool especial(grupo a);