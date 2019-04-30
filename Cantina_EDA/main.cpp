#include <iostream>
#include <string>
#include "Refeição.h"
#include "aluno_staff.h"
#include "Mesa.h"
#include "guardar_carregar.h"
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


void inicializacao(refeicao* ref, mesa* ms, f_espera* f_esp, pessoa* pes) {//Fase inicial, se não houver dados gardados
	int ciclo = 1;
	ref->ciclo = ciclo;
	alterar_refeicao(ref);
	//nova mesa
	int tam_cantina = rand() % 20 + 30; //tamanho da cantina
	tam_cantina = rand() % 20 + 30;//http://www.cplusplus.com/forum/general/114978/ -> AeonFlux1212 ´"o rand convém ser acionado duas vezes para ter a certeza que gera um número aleatório 
	int tam_aux = tam_cantina; //para o ciclo while
	int n_mesa = 0;//número de mesas
	cantina(ms, tam_cantina);
	int pos_mesa_aux = 0; //para o ciclo while
	int rnd_mesa = random_mesa(); //n cadeiras por mesa
	rnd_mesa = random_mesa();//http://www.cplusplus.com/forum/general/114978/ -> AeonFlux1212
	int pos_aux = 1;
	int while_aux=1;
	/*while (tam_aux != 0) {
		if (while_aux == 0) {
			pos_mesa_aux += 1;
			q_mesa(ms, pos_mesa_aux);
			enumerar_mesa(ms, pos_aux, pos_mesa_aux);
			cap_mesa(ms, pos_aux, rnd_mesa);
			int tam_anterior = tam_aux;
			while_aux = rnd_mesa;
			tam_aux -= rnd_mesa;
			if (tam_aux == 1||tam_aux<0) {
				do {
					cap_mesa(ms, pos_aux, 0);
					tam_aux = tam_anterior;
					rnd_mesa = random_mesa();
					cap_mesa(ms, pos_aux, rnd_mesa);
					tam_anterior = tam_aux;
					while_aux = rnd_mesa;
					tam_aux -= rnd_mesa;
				} while (tam_aux == 1 || tam_aux < 0);
			}
		}
		while_aux -= 1;
		pos_aux += 1;
	}
	q_mesa(ms, pos_aux);*/
	//nova pessoa(aluno/staff) nova fila
	int tam_pessoa = 50;
	inserir_tam_fila(f_esp, tam_pessoa);
	for (int i = 1; i <= tam_pessoa; i++) {
		criar_pessoa(pes, i);
		adicionar_fila_espera(f_esp, i, pes, i);
	};
	//por pessoas que estão na fila para a mesa
	/*for (int i = 1; i <= n_can(ms); i++) {
		por_pessoa_mesa(ms, i, f_esp[i].pessoa);
		retirar_fila_espera(f_esp);
	}*/
}
void seguinte(){

}
void emergencia(){

}
void extrair(){

}
void guardar() {

}
void carregar() {

}
void opcoes() {

}
void menu(refeicao* ref, mesa* ms, f_espera* f_esp, pessoa* pes){
	centerstring("Cantina EDA");
	cout << endl;
	cout << "(s)Seguinte (e)Emergência (g)Gravar (c)Carregar Dados (o)Opções (x)Sair" << endl;
	cout << endl;
	mostrar_refeicao (ref);
	cout << endl;
	//mostrar_mesas(ms);
	cout << endl;
	mostrar_fila_espera(f_esp);
	cout << endl;
}


int main() {
	srand(time(NULL));
	locale::global(locale(""));
	struct refeicao* ref = new struct refeicao;  //é preciso criar as variáveis primeiro,independentemente de haver dados guardados ou não
	struct mesa* ms = new struct mesa[51];
	struct f_espera* f_esp = new struct f_espera[51];
	struct pessoa* pes = new struct pessoa[51];
	char opcao;
	inicializacao(ref, ms, f_esp, pes);
	do {
		menu(ref, ms, f_esp, pes);
		cout << "**** Comando: ";
		cin >> opcao;
		cout << endl;
		if (opcao != 'x') {
			switch (opcao) {
			case 's': {
				seguinte();
				break;
			}
			case'e': {
				emergencia();
				break;
			}
			case'g': {
				guardar();
				break;
			}
			case'c': {
				carregar();
				break;
			}
			case'o': {
				opcoes();
				break;
			}
			default: {
				cout << "Escolha uma opção válida." << endl;
			}
			}
		}
	} while (opcao != 'x');
	return 0;
}