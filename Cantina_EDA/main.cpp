
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

void mostrar_mesa(mesa* cantina) {
	mesa* mesa_aux = cantina;
	while (mesa_aux != NULL) {
		cout<<endl << "Mesa " << mesa_aux->n_mesa <<" (CAPACIDADE: "<<mesa_aux->capacidade<<"):"<<endl;
		pessoa_cantina* ocupante_aux = mesa_aux->ocupantes;
		while (ocupante_aux != NULL) {
			cout << ocupante_aux->pnome;
			if (ocupante_aux->staff_ou_grupo) {
				cout << ", STAFF, Departamento: ";
			}
			else {
				cout << ",  ESTUDANTE, " << ocupante_aux->curso << ", Grupo: ";
			}
			cout << ocupante_aux->n_grup;
			cout << "," << ocupante_aux->numero;
			cout << " (Ciclos: " << ocupante_aux->ciclos << ")" << endl;
			ocupante_aux = ocupante_aux->seguinte;
		}
		mesa_aux = mesa_aux->seguinte;
	}
}

void mostrar_fila(pessoa_cantina*fila_espera) {
	cout << "Fila de espera: " << endl;
	pessoa_cantina* aux = fila_espera;
	while (aux != NULL) {
		cout << aux->pnome;
		if (aux->staff_ou_grupo) {
			cout << ", STAFF, Departamento: ";
		}
		else {
			cout << ",  ESTUDANTE, " << aux->curso << ", Grupo ";
		}
		cout << aux->n_grup << ",";
		cout << aux->numero;
		cout << " (Ciclos restantes: " << aux->ciclos << ")";
		cout << ", Plafond: " << aux->plafond;
		if (aux->especial) {
			cout << " [ESPECIAL]";
		}
		cout << endl;
		aux = aux->seguinte;
	}
}


pessoa_cantina * seguinte(listaref ref, mesa* cantina, pessoa_cantina* fesp, int ciclo) {
	if (ciclo % 10 == 0) {
		alterar_refeicao(ref);
	}
	//ms_seguinte(cantina);
	pessoa_cantina* novo_grupo = cria_grupo();
	pessoa_cantina* aux = fesp;
	while (aux->seguinte != NULL) {
		aux = aux->seguinte;
	}
	aux->seguinte = novo_grupo;
	//remover_low_plafond(fesp, ref);


	return coloca_pessoa_mesa(cantina, fesp);
}


void menu(listaref &ref, mesa *ms, pessoa_cantina *f_esp){
	centerstring("Cantina EDA");
	cout << endl;
	cout << "(s)Seguinte (e)Emergência (g)Gravar (c)Carregar Dados (o)Opções (x)Sair" << endl;
	cout << endl;
	mostrar_refeicao (ref);
	cout << endl;
	mostrar_mesa(ms);
	cout << endl;
	mostrar_fila(f_esp);
	cout << endl;

}


int main() {
	srand(time(0));

	listaref ref;
	ref.actual = NULL;

	alterar_refeicao(ref);
	char opcao = ' ';
	int ciclo = 0;

	pessoa_cantina* fila_espera = NULL;
	mesa* cantina = NULL;
	//criar mesas
	cantina = cria_mesas();
	//criar primeiro grupo
	fila_espera = cria_grupo();
	//criar multiplos grupos e por na fila de espera
	for (int i = 0; i <= 9; i++) {
		pessoa_cantina* novo_grupo = cria_grupo();
		pessoa_cantina* aux = fila_espera;
		while (aux->seguinte != NULL) {
			aux = aux->seguinte;
		}
		aux->seguinte = novo_grupo;
	}
	//verificar se tem plafond
//remover_low_plafond(fila_espera, ref);

	mostrar_fila(fila_espera);

	//int vezes_p_colocar_pessoa_mesa = cantina->n_mesas;
	fila_espera = coloca_pessoa_mesa(cantina, fila_espera);

	//mostrar_mesa(cantina);
	mostrar_fila(fila_espera);
	
	while (opcao != 'x') {
		menu(ref, cantina,fila_espera);
		cout << "**** Comando: ";
		cin >> opcao;
		cout << endl;
			switch (opcao) {
			case 's': {
				ciclo++;
				if (ciclo % 10 == 0) {
					alterar_refeicao(ref);
				}
				//ms_seguinte(cantina);
				pessoa_cantina* novo_grupo = cria_grupo();
				pessoa_cantina* aux2 = fila_espera;
				while (aux2->seguinte != NULL) {
					aux2 = aux2->seguinte;
				}
				aux2->seguinte = novo_grupo;
				//remover_low_plafond(fesp, ref);

				fila_espera = coloca_pessoa_mesa(cantina, fila_espera);
				break;
			}
			case'e': {
				//emergencia(ms, pes);
				break;
			}
			case'g': {
				//guardar(ref, ms, f_esp, pes, ciclo);
				break;
			}
			case'c': {
				//carregar(ref, ms, f_esp, pes, ciclo);
				break;
			}
			case'o': {
				char opcao;
				cout << "1-Mostrar todas as pessoas \n";
				cout << "4-Adicionar plafond\n";
				cin >> opcao;
				switch (opcao) {
				case '1': {
					//mostrar_ordenado(fila_espera);
					break;
				}
				case '4': {
					//alterar_plafond(f_esp);
				}
				default: {
					cout << "Opção inválida" << endl;
				}
				}
				break;
			}
			case'x': {
				cout << "Obrigado por usar o programa :^) ." << endl;
				break;
			}
			default: {
				cout << "Escolha uma opção válida." << endl;
			}
		}
	};
	return 0;
}