#include "pessoa_cantina.h"
#include"Refeição.h"
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
	int n_elementos = rand() % 9 + 1;
	int n_grupo = rand() % 401 + 100;
	int ciclos = rand()%3 + 2;
	string curso= random_line("cursos.txt");
	bool tipo = false;//falso -aluno
	if (rand() % 10 < 5) {
		tipo = true;
	}
	bool especial = false;
	if (!tipo&&rand() % 100+ 1<= 5) {
		especial = true;
	}
	pessoa_cantina* grupo = NULL;
	if (especial) {
		n_elementos = 1;
	}
	for (int i = 0; i < n_elementos; i++) {
		//primeiro criar a pessoa
		pessoa_cantina* nova = new pessoa_cantina;
		string pn = random_line("pr.txt");
		string un = random_line("ul.txt");
		long numero = rand() % 89000 + 10000;
		if (tipo) {
			numero = rand() % 8900 + 1000;
		}
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

pessoa_cantina* remover_low_plafond(pessoa_cantina* fila, listaref refeicao) {
	pessoa_cantina* aux = fila;
	float preco = refeicao.actual->preco;
	float preco_fila;
	while (aux != NULL) {
		preco_fila = aux->plafond;
		if (preco_fila < preco) {
			//char opcao=NULL;
			//cout << "Umapessoa da fila não pussui o plafond suficiente para a refeiçao. O que quer fazer?" << endl << "1-Remover só a pessoa" << endl << "2-Remover o grupo" << endl;
			//cin >> opcao;
			//remover um elemento
			pessoa_cantina* aux2 = aux;
			while (preco_fila < preco && aux2 != NULL) {
				aux2 = aux2->seguinte;
				preco_fila = aux2->plafond;
			}
			cout << "Plafond baixo detetado, remover elemento" << endl;
			if (aux2 == NULL) {
				aux = NULL;
			}
			else if(aux2->seguinte==NULL){
				aux = aux2;
			}
			else {
				aux->seguinte = aux2;
				aux = aux->seguinte;
			}
		}
		aux = aux->seguinte;
	}
	return fila;
}

/*pessoa_cantina* sort_especial(pessoa_cantina* fila) {
	pessoa_cantina* aux = fila;
	while (aux != NULL) {
		if (aux->especial)) {

		}
		aux = aux->seguinte;
	}
	return fila;
}*/

	


/*pessoa_cantina* por_especial_primeiro(pessoa_cantina* f_esp) {
	pessoa_cantina* aux1 = f_esp;
	pessoa_cantina* aux2 = new struct pessoa_cantina;
	pessoa_cantina* aux3 = new struct pessoa_cantina;
	while (aux1&&aux2 != NULL) {
		if (aux1->seguinte->especial) { //se o grupo for especial, guarda esse grupo
			aux2 = aux1->seguinte;
		}
		if (aux1->seguinte == NULL && aux2 != NULL) {//se o aux1 não for NULL(não ser o primeiro) mas o seguinte for, passar este para o seguinte e continuar até chegar ao primeiro
			aux1->seguinte = aux1;
			aux1 = f_esp;
		}
		if (aux1 == NULL && aux2 != NULL) {
			aux1 = aux2;
		}
		else
		aux1 = aux1->seguinte;
	}
}

void sort_especial(pessoa_cantina* f_esp) {
	pessoa_cantina* aux1 = f_esp;
	pessoa_cantina* aux3 = new struct pessoa_cantina;

}*/