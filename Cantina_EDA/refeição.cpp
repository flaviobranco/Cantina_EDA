#include <iostream>
#include "Refei��o.h"
using namespace std;


void alterar_refeicao(refeicao* refeicao) {
	cout << "Introduza a entrada: \n";
	cin >> refeicao->entrada;
	cout << "Introduza prato: \n";
	cin >> refeicao->prato;
	cout << "Indroduza o pre�o \n";
	cin >> refeicao->pre�o;
}

void mostrar_refeicao(refeicao*refeicao) {
	cout << "Refei��o atual: \n";
	cout << "\t Entrada: " << refeicao->entrada << endl;
	cout << "\t Prato: " << refeicao->prato << endl;
	cout << "\t Pre�o: " << refeicao->pre�o << endl;
}