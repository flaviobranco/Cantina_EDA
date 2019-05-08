#include <iostream>
#include <string>
#include <fstream>
#include "Refei��o.h"
using namespace std;

void alterar_refeicao (struct refeicao * ref) {
	cin.clear();//
	cin.seekg(0, std::ios::beg);// reset do getline, from Philip Nicoletti ->http://forums.codeguru.com/showthread.php?320724-how-to-reset-quot-getline(File-string)-quot
	cout << "Introduza a entrada: " << endl; 
	getline(cin,ref->entrada);
	cout << "Introduza prato: " << endl;
	getline(cin,ref->prato);
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