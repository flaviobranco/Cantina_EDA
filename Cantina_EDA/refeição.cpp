#include <iostream>
#include <fstream>
#include "Refei��o.h"
using namespace std;


void alterar_refeicao (struct refeicao * ref) {
	ifstream g;
	cout << "Introduza a entrada: " << endl; 
	g.getline(cin, ref->entrada);
	cout << "Introduza prato: " << endl;
	g.getline(cin, ref->prato);
	cout << "Indroduza o pre�o \n";
	cin>> ref->pre�o;
}

void mostrar_refeicao (struct refeicao*ref) {
	cout << "Refei��o atual: \n";
	cout << "\t Entrada: " << ref->entrada << endl;
	cout << "\t Prato: " << ref->prato << endl;
	cout << "\t Pre�o: " << ref->pre�o <<"�"<< endl;
}

string ref_entrada (struct refeicao* ref) {
	return ref->entrada;;
}
string ref_prato(struct refeicao* ref) {
	return ref->prato;
}
float ref_preco(struct refeicao* ref) {
	return ref->pre�o;
}