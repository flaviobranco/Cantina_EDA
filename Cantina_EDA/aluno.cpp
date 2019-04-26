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

void criar_aluno() {
	for (int i = 1; i <= 50; ++i)
	{
		string pn= random_line("primeiro_nome.txt");
		string un= random_line("ultimo_nome.txt");
		string cs= random_line("cursos.txt");
		cout << "PNome: " << pn << " Unome: " << un << " Curso: " << cs << endl;
	}
}