#pragma once
#include <string>
using namespace std;
struct pessoa { //grupo de alunos ou staff
	struct check { //necesário para verificar duas condições essenciais:
		string aluno_ou_staff;// Escolhe se é "Estudante" ou "Staff", Um será um grupo entre 2 a 10(exceto se especial for true, nesse caso só terá apenas 1)
	};
	struct grupo {//criar grupos de alunos de uma só vez é mais eficiente
		bool especial;//o aluno é especial?
		int n_grupo;
		int n_elementos;
		struct aluno {// pilha de alunos
			string nome;
			int numero;
			string curso;
			float plafond;
			aluno* seguinte;//se especial==true, seguinte será null
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