#include "pessoa_cantina.h"
#include <string>
#include <iostream>
#include <fstream>
using namespace std;

std::string random_line(string path) //http://www.cplusplus.com/forum/general/114978/ -> from JLBorges, ler linhas aleatórias
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
	return selected;
}


pessoa_cantina* cria_grupo() {
	int n_elementos = rand() % 8 + 2;
	int n_grupo = rand() % 401 + 100;
	int ciclos = rand()%3 + 2;
	string curso= random_line("cursos.txt");
	bool tipo = false;//falso -aluno
	if (rand() % 10 < 5) {
		tipo = true;
	}
	pessoa_cantina* grupo = NULL;

	for (int i = 0; i < n_elementos; i++) {
		//primeiro criar a pessoa
		pessoa_cantina* nova = new pessoa_cantina;
		string pn = random_line("pr.txt");
		string un = random_line("ul.txt");
		long numero = rand() % 89000 + 10000;
		nova->staff_ou_grupo = tipo;
		if (!tipo) {
			nova->curso = curso;
		}
		nova->pnome = pn;
		nova->unome = un;
		nova->plafond = (rand() % 1000 + 10) * 0.1;
		nova->numero = numero;
		nova->n_grup = n_grupo;
		nova->ciclos = ciclos;
		if (grupo == NULL){
			grupo = nova;
			nova->seguinte = NULL;
		}
		else {
			nova->seguinte = grupo;
			grupo = nova;
		}
	}
	return grupo;
}