#include <iostream>
#include <string>
#include <fstream>
#include "Refei��o.h"
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
	cout << "A cantina EDA precisa de uma nova refei��o" << endl;
	string entrada;
	string prato;
	float pre�o;
	cout << "Introduza a entrada: " << endl; 
	getline(cin,entrada);
	cout << "Introduza prato: " << endl;
	getline(cin,prato);
	cout << "Indroduza o pre�o \n";
	cin>> pre�o;
	novarefeicao(lista, entrada, prato, pre�o);
}

void mostrar_refeicao (struct listaref &lista) {
	listaref::refeicao* ref = lista.actual;
	cout << "Refei��o atual: \n";
	cout << "\t Entrada: " <<ref->entrada << endl;
	cout << "\t Prato: " <<ref->prato << endl;
	cout << "\t Pre�o: " <<ref->preco  <<"�"<< endl;
}


