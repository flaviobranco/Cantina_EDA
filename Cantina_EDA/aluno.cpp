#include "aluno_staff.h"
#include <iostream>
#include <fstream>
#include <string>
#include <time.h>
using namespace std;

std::string random_line(const char* path) //http://www.cplusplus.com/forum/general/114978/ -> from JLBorges
{
	std::string selected;
	std::ifstream file(path);
	//
	std::string line;
	std::streamsize nlines = 0;
	while (std::getline(file, line))
	{
		++nlines;
		if (std::rand() % nlines == 0) selected = line;
	}
	//
	return selected;
}

void criar_pessoa(pessoa*pessoa,int i) {
		string pn= random_line("primeiro_nome.txt");
		string un= random_line("ultimo_nome.txt");
		pessoa[i].nome = pn+" "+un;
		
}

void mostrar_pessoa(pessoa* pessoa, int i) {
	cout << "Nome: " << pessoa[i].nome <<  endl;
}