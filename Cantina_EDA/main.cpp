
#include <iostream>
#include <string>
#include "Refeição.h"
#include "Mesa.h"
#include "pessoa_cantina.h"
//#include "guardar_carregar.h"
#include "time.h"
#include <locale>
using namespace std;
//flav


void centerstring(const char* s) // para escrever texto no centro -> from born2c0de https://www.dreamincode.net/forums/topic/13749-center-text-with-cout/
{
	int l = strlen(s);
	int pos = (int)((80 - l) / 2);
	for (int i = 0; i < pos; i++) {
		cout << " ";
	}
	cout << s;
}


/*
void emergencia(mesa ms,pessoa pes){

}
void extrair(refeicao  ref, mesa  ms, f_espera  f_esp, pessoa  pes, int ciclo){

}
void guardar(refeicao  ref, mesa  ms, f_espera  f_esp, pessoa  pes, int ciclo) {

}
void carregar(refeicao  ref, mesa  ms, f_espera  f_esp, pessoa  pes, int ciclo) {

}
void opcoes(refeicao  ref, mesa  ms, f_espera  f_esp, pessoa  pes) {
	char opcao;
	cout << "1-Mostrar todas as pessoas \n";
	cout << "4-Adicionar plafond\n";
	cin >> opcao;
	switch (opcao) {
	case '1':{
		mostrar_ordenado(pes);
		break;
	}
	case '4':{
		alterar_plafond(f_esp);
	}
	default:{
		cout << "Opção inválida" << endl;
	}
	}

void menu(listaref &ref, mesa &ms, f_espera &f_esp){
	/*centerstring("Cantina EDA");
	cout << endl;
	cout << "(s)Seguinte (e)Emergência (g)Gravar (c)Carregar Dados (o)Opções (x)Sair" << endl;
	cout << endl;
	mostrar_refeicao (ref);
	cout << endl;
	mostrar_mesas(ms);
	cout << endl;
	mostrar_fila_espera(f_esp);
	cout << endl;

}*/


int main() {
	srand(time(0));

	listaref ref;
	
	
	int ciclo=0;
	char opcao=' ';


	pessoa_cantina* fila_espera = NULL;
	mesa* cantina = NULL;
	cantina = cria_mesas();
	//criar primeiro grupo
	fila_espera = cria_grupo();

	for (int i = 0; i <= 9; i++) {
		pessoa_cantina* novo_grupo = cria_grupo();
		pessoa_cantina* aux = fila_espera;
		while(aux->seguinte != NULL) {
			aux = aux->seguinte;
		}
		aux->seguinte = novo_grupo;
	}

	pessoa_cantina* aux = fila_espera;
	while (aux != NULL) {
		cout << aux->pnome << aux->n_grup;

		if (aux->staff_ou_grupo)
			cout << " STAFF" << endl;
		else
			cout << "  ESTUDANTE" << endl;

		aux = aux->seguinte;
	}
	fila_espera = coloca_pessoa_mesa(cantina, fila_espera);
	mesa* mesa_aux = cantina;
	while (mesa_aux != NULL) {
		cout << "Mesa: " << mesa_aux->n_mesa << endl;
		pessoa_cantina* ocupante_aux = mesa_aux->ocupantes;
		while (ocupante_aux != NULL) {
			cout << ocupante_aux->pnome << "  " << ocupante_aux->n_grup << endl;
			ocupante_aux = ocupante_aux->seguinte;
		}
		mesa_aux=mesa_aux->seguinte;
	}

	aux = fila_espera;
	while (aux != NULL) {
		cout << aux->pnome << aux->n_grup;

		if (aux->staff_ou_grupo)
			cout << " STAFF" << endl;
		else
			cout << "  ESTUDANTE" << endl;

		aux = aux->seguinte;
	}
	//colocar noutra função
	
	/*while (opcao != 'x') {
		menu(ref, ms, f_esp, pes);
		cout << "**** Comando: ";
		cin >> opcao;
		cout << endl;
		if (opcao != 'x') {
			switch (opcao) {
			case 's': {
				seguinte(ref,ms,f_esp,pes,ciclo);
				break;
			}
			case'e': {
				emergencia(ms, pes);
				break;
			}
			case'g': {
				guardar(ref, ms, f_esp, pes, ciclo);
				break;
			}
			case'c': {
				carregar(ref, ms, f_esp, pes, ciclo);
				break;
			}
			case'o': {
				opcoes(ref, ms, f_esp, pes);
				break;
			}
			case'x': {
				cout << "Obrigado por usar o programa. A sair do programa..." << endl;
				break;
			}
			default: {
				cout << "Escolha uma opção válida." << endl;
			}
			}
		}
	};*/
	return 0;
}