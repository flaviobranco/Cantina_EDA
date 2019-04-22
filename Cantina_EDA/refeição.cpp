#include <iostream>
#include "Refeição.h"
using namespace std;


void alterar_refeicao(refeicao* refeicao) {
	cout << "Introduza a entrada: \n";
	cin >> refeicao->entrada;
	cout << "Introduza prato: \n";
	cin >> refeicao->prato;
	cout << "Indroduza o preço \n";
	cin >> refeicao->preço;
}

void mostrar_refeicao(refeicao*refeicao) {
	cout << "Refeição atual: \n";
	cout << "\t Entrada: " << refeicao->entrada << endl;
	cout << "\t Prato: " << refeicao->prato << endl;
	cout << "\t Preço: " << refeicao->preço << endl;
}