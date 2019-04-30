#include <iostream>
#include <string>
#include "Refeição.h"
#include "aluno_staff.h"
#include "Mesa.h"
#include "guardar_carregar.h"
#include "time.h"
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


void inicializacao(refeicao*ref,mesa*ms,f_espera*f_esp,pessoa*pes) {//Fase inicial, se não houver dados gardados
	int ciclo = 1;
	alterar_refeicao(ref);
	//nova mesa
	int tam_cantina = rand()%30+20; //tamanho da cantina
	tam_cantina = rand() % 30 + 20;//http://www.cplusplus.com/forum/general/114978/ -> AeonFlux1212 ´"o rand convém ser acionado duas vezes para ter a certeza que gera um número aleatório 
	int tam_aux = tam_cantina; //para o ciclo while
	int n_mesa = 0;//número de mesas
	int pos_mesa_aux = 0; //para o ciclo while
	int rnd_mesa=random_mesa(); //n cadeiras por mesa
	rnd_mesa = random_mesa();//http://www.cplusplus.com/forum/general/114978/ -> AeonFlux1212
	int tam_ant=0;//se tam <=1
	for (int i = 1; i <= tam_cantina; i++) { //determinar o n de mesas
		do {
			pos_mesa_aux += 1;
			if (i != 1) {
				rnd_mesa = random_mesa();
			}
			enumerar_mesa(ms, i, pos_mesa_aux);
			cap_mesa(ms, i, rnd_mesa);
			tam_aux -= rnd_mesa;
			if (tam_aux <= 1) {
				cap_mesa(ms, i, 0);
				tam_aux += rnd_mesa;
			}
		} while (rnd_mesa == 0);
		rnd_mesa -= 1;
	}

	//nova pessoa(aluno/staff) nova fila
	int tam_pessoa = 50; //1ª entrega, fila com o máximo de 50 pessoas
	for (int i = 1; i <= tam_pessoa; i++) {
		criar_pessoa(pes, i);
	};
	for (int i = 0; i <= tam_pessoa; i++) { //primeiro inserir, depois ordenar
		adicionar_fila_espera(f_esp, i, pes);
	}
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
	cout << "(s)Seguinte (e)Emergência (g)Gravar (c)Carregar Dados (o)Opções (e)Sair" << endl;
	cout << endl;
	mostrar_refeicao (ref);
	cout << endl;
	//mostrar_mesa(f_esp);
	cout << endl;
}


int main() {
	srand(time(NULL));
	refeicao* ref = new struct refeicao;  //é preciso criar as variáveis primeiro,independentemente de haver dados guardados ou não
	mesa* ms = new struct mesa[51];
	f_espera* f_esp = new struct f_espera[51];
	pessoa* pes = new struct pessoa[51];
	char opcao;
	inicializacao(ref, ms, f_esp, pes);
	do {
		menu(ref, ms, f_esp, pes);
		cout << "**** Comando: ";
		cin >> opcao;
		cout << endl;
		if (opcao != 'e') {
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
	} while (opcao != 'e');
	return 0;
}