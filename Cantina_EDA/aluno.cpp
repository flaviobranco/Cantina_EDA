
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
//pessoa

/*bool p_vazia(pessoa& pes) {
	if (pes.aluno_ou_staff == "") {
		return true;
	}
	else {
		return false;
	}
}*/

void aluno_ou_staff(pessoa &pes) {
	if ((rand()% 100+1) <50) {
		pes.aluno_ou_staff= "Estudante";
	}
	else {
		pes.aluno_ou_staff = "Staff";
	}
}

bool aluno(pessoa& pes) {
	if (pes.aluno_ou_staff == "Estudante") {
		return true;
	}
	else {
		return false;
	}
}

void gerar_id(pessoa &pes) {
	if (aluno(pes)) {
		pessoa::grupo* aux = new struct pessoa::grupo();
		aux->n_grupo = rand() % 401 + 100;
		pes.grup= aux;
	}
	else
	{
		pessoa::departamento* aux = new pessoa::departamento();
		aux->n_departamento = rand() % 401 + 100;
		pes.depart = aux;
	}
}
void especial(pessoa& pes) {
	if (aluno(pes)) {
		pessoa::grupo* aux = new pessoa::grupo();
		if (rand() % 100 + 1 < 5) {
			aux->especial = true;
		}
		else {
			aux->especial = false;
		}
		pes.a_guardar = aux;
	}
}

bool e_especial(pessoa& pes) {
	return pes.a_guardar->especial;
}

void gerar_elemen(pessoa& pes) {
	if (aluno(pes)) {
		pessoa::grupo* aux = new pessoa::grupo();
		if (e_especial(pes)) {
			aux->n_elementos = 1;
		}
		else {
			aux->n_elementos = rand()%8+2;
		}
		pes.a_guardar = aux;
	}
	else {
		pessoa::departamento* aux = new pessoa::departamento();
		aux->n_elementos= rand() % 8 + 2;
		pes.d_guardar = aux;
	}
}

int num_elementos(pessoa& pes) {
	if (aluno(pes)) {
		pessoa::grupo* aux = pes.a_guardar;
		return aux->n_elementos;
	}
	else {
		pessoa::departamento* aux = pes.d_guardar;
		return aux->n_elementos;
	}
}
//grupo



void criar_nome(pessoa &pes) {
	if (aluno(pes)) {
		pessoa::grupo::aluno* aux = new struct pessoa::grupo::aluno();
		string pn = random_line("pr.txt");
		string un = random_line("ul.txt");
		aux->nome = pn + " " + un;
		aux->seguinte = pes.a_guardar->inicio;
		pes.a_guardar->inicio = aux;
	}
	else {
		pessoa::departamento::staff* aux = new struct pessoa::departamento::staff();
		string pn = random_line("pr.txt");
		string un = random_line("ul.txt");
		aux->nome = pn + " " + un;
		aux->seguinte = pes.d_guardar->inicio;
		pes.d_guardar->inicio = aux;
	}
}

void criar_numero(pessoa& pes) {
	if (aluno(pes)) {
		pessoa::grupo::aluno* aux = new struct pessoa::grupo::aluno();
		aux->numero = rand() % 89000 + 10000;
		pes.a_guardar->inicio = aux;
	}
	else {
		pessoa::departamento::staff* aux = new struct pessoa::departamento::staff();
		aux->numero = rand() % 8900 + 1000;
		pes.d_guardar->inicio = aux;
	}
}

void criar_plafond(pessoa& pes) {
	if (aluno(pes)) {
		pessoa::grupo::aluno* aux = new struct pessoa::grupo::aluno();
		aux->plafond = (rand() % 1000 + 10) *0.1;
		pes.a_guardar->inicio = aux;
	}
	else {
		pessoa::departamento::staff* aux = new struct pessoa::departamento::staff();
		aux->plafond = (rand() % 1000 + 10) *0.1;
		pes.d_guardar->inicio = aux;
	}
}

void gerar_curso(pessoa& pes) {
	if (aluno(pes)) {
		pessoa::grupo* aux = new struct pessoa::grupo();
		string curso = random_line("cursos.txt");
		aux->curso = curso;
		pes.a_guardar = aux;
	}
}

void gerar_ciclos(pessoa& pes) {
	if (aluno(pes)) {
		pessoa::grupo* aux = pes.a_guardar;
		aux->ciclos = rand() % 3 + 2;
	}
	else {
		pessoa::departamento* aux = pes.d_guardar;
		aux->ciclos = rand() % 3 + 2;
	}
}

void gerar_pessoa(pessoa& pes) {
	aluno_ou_staff(pes);
	especial(pes);
	gerar_id(pes);
	gerar_elemen(pes);
	gerar_curso(pes);
	gerar_ciclos(pes);
	criar_nome(pes);
	criar_numero(pes);
	criar_plafond(pes);
}

//mostrar
string mostrar_nome(pessoa& pes) {
	if (aluno(pes)) {
		return pes.a_guardar->inicio->nome;
	}
	else {
		return pes.a_guardar->inicio->nome;
	}
}
string mostrar_al_ou_stf(pessoa & pes) {
		return pes.aluno_ou_staff;
}

string mostrar_curso(pessoa& pes) {
	return pes.a_guardar->curso;
}

int mostrar_grupo(pessoa& pes) {
	return pes.a_guardar->n_grupo;
}

int mostrar_departamento(pessoa& pes) {
	return pes.d_guardar->n_departamento;
}

int mostrar_numero(pessoa &pes){
	if (aluno(pes)) {
		return pes.a_guardar->inicio->numero;
	}
	else {
		return pes.d_guardar->inicio->numero;
	}
}

int mostrar_ciclos(pessoa& pes) {
	if (aluno(pes)) {
		return pes.a_guardar->ciclos;
	}
	else {
		return pes.d_guardar->ciclos;
	}
}

float mostrar_plafond(pessoa& pes) {
	if (aluno(pes)) {

		return pes.a_guardar->inicio->plafond;
	}
	else {
		return pes.d_guardar->inicio->plafond;
	}
}


void mostrar_pessoa(pessoa& pes) {
	/*if (p_vazia(pes)) {
		cout << "ERRO: Vazio" << endl;
	}
	else {*/
		pessoa aux = pes;
		if (aluno(pes)) {
			do{
				cout << mostrar_nome(aux) << ", " << mostrar_al_ou_stf(aux) << ", " << mostrar_curso(aux) << ", " << mostrar_grupo(aux) << ", " << mostrar_numero(aux) << ", Duração, " << mostrar_ciclos(aux) << ", " << mostrar_plafond(aux) << endl;
				aux.a_guardar->inicio = aux.a_guardar->inicio->seguinte;
			} while (aux.a_guardar->inicio != 0);
		}
		else {
			do{
				cout << mostrar_nome(aux) << ", " << mostrar_al_ou_stf(aux) << ", Departamento: " << mostrar_departamento(aux) << ", " << mostrar_numero(aux) << ", Duração, " << mostrar_ciclos(aux) << ", " << mostrar_plafond(aux) << endl;
				aux.d_guardar->inicio = aux.d_guardar->inicio->seguinte;
			} while (aux.d_guardar->inicio != 0);
		}
	//}
}