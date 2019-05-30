
#include <iostream>
#include <string>
#include "Refei��o.h"
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
		cout << "Mesa " << mesa_aux->n_mesa <<" (CAPACIDADE: "<<mesa_aux->capacidade<<"):"<<endl;
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
			cout << " (Ciclos restantes: " << ocupante_aux->ciclos << ")" << endl;
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
		cout << ", Plafond: " << aux->plafond<<endl;
		aux = aux->seguinte;
	}
}

/*
void emergencia(){

}
void extrair(){

}
void guardar() {

}
void carregar() {

}
void opcoes(refeicao  *ref, mesa  *ms, f_espera  *f_esp) {
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
		cout << "Op��o inv�lida" << endl;
	}
	}
*/
void menu(listaref &ref, mesa *ms, pessoa_cantina *f_esp){
	centerstring("Cantina EDA");
	cout << endl;
	cout << "(s)Seguinte (e)Emerg�ncia (g)Gravar (c)Carregar Dados (o)Op��es (x)Sair" << endl;
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

	alterar_refeicao(ref);
	int ciclo = 0;
	char opcao = ' ';


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

	//int vezes_p_colocar_pessoa_mesa = cantina->n_mesas;
	fila_espera = coloca_pessoa_mesa(cantina, fila_espera);

	mostrar_mesa(cantina);
	mostrar_fila(fila_espera);
	
	while (opcao != 'x') {
		menu(ref, cantina,fila_espera);
		cout << "**** Comando: ";
		cin >> opcao;
		cout << endl;
		if (opcao != 'x') {
			switch (opcao) {
			case 's': {
				//seguinte(ref,ms,f_esp,pes,ciclo);
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
				//opcoes(ref, ms, f_esp, pes);
				break;
			}
			case'x': {
				cout << "Obrigado por usar o programa. A sair do programa..." << endl;
				break;
			}
			default: {
				cout << "Escolha uma op��o v�lida." << endl;
			}
			}
		}
	};
	return 0;
}