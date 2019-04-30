#include <iostream>
#include <fstream>
#include "Refeição.h"
using namespace std;


void alterar_refeicao (struct refeicao * ref) {
	ifstream g;
	cout << "Introduza a entrada: " << endl; 
	g.getline(cin, ref->entrada);
	cout << "Introduza prato: " << endl;
	g.getline(cin, ref->prato);
	cout << "Indroduza o preço \n";
	cin>> ref->preço;
}

void mostrar_refeicao (struct refeicao*ref) {
	cout << "Refeição atual: \n";
	cout << "\t Entrada: " << ref->entrada << endl;
	cout << "\t Prato: " << ref->prato << endl;
	cout << "\t Preço: " << ref->preço <<"€"<< endl;
}

string ref_entrada (struct refeicao* ref) {
	return ref->entrada;;
}
string ref_prato(struct refeicao* ref) {
	return ref->prato;
}
float ref_preco(struct refeicao* ref) {
	return ref->preço;
}