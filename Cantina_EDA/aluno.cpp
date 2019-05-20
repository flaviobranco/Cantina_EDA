
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



void aluno_ou_staff(pessoa pes) {
	pessoa::check* aux 
	string response;
	if (rand() 100+1<50) {
		response = "Estudante";
	}
	else {
		response = "Staff";
	}
}

void criar_nome(pessoa &pessoa) {
		string pn= random_line("primeiro_nome.txt");
		string un= random_line("ultimo_nome.txt");
		
}

void gerar_pessoa(pessoa pes) {
	aluno_ou_staff(pes);
}

bool aluno(pessoa pes) {
	if (aluno ou staff == "Estudante") {
		return true;
	}
	else {
		return false;
	}
}
*/