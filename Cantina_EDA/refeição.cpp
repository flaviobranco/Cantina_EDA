#include <iostream>
#include <string>
#include <fstream>
#include "Refeição.h"
using namespace std;

void novarefeicao(listaref &lista, string entrada, string prato, float preco) {
	listaref::refeicao* novarefeicao = new listaref::refeicao();
	novarefeicao->entrada = entrada;
	novarefeicao->prato = prato;
	novarefeicao->preco = preco;
	novarefeicao->anterior = lista.actual;
	lista.actual = novarefeicao;
}


void alterar_refeicao (struct listaref &lista) {
	cin.clear();//
	cin.seekg(0, std::ios::beg);// reset do getline, from Philip Nicoletti ->http://forums.codeguru.com/showthread.php?320724-how-to-reset-quot-getline(File-string)-quot
	cout << "A cantina EDA precisa de uma nova refeição" << endl;
	string entrada;
	string prato;
	float preço;
	cout << "Introduza a entrada: " << endl; 
	getline(cin,entrada);
	cout << "Introduza prato: " << endl;
	getline(cin,prato);
	cout << "Indroduza o preço \n";
	cin>> preço;
	novarefeicao(lista, entrada, prato, preço);
}

void mostrar_refeicao (struct listaref &lista) {
	listaref::refeicao* ref = lista.actual;
	cout << "Refeição atual: \n";
	cout << "\t Entrada: " <<ref->entrada << endl;
	cout << "\t Prato: " <<ref->prato << endl;
	cout << "\t Preço: " <<ref->preco  <<"€"<< endl;
}


