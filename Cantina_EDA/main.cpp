
#include <iostream>
#include <string>
#include "Refeição.h"
#include "aluno_staff.h"
/*#include "Mesa.h"
#include "guardar_carregar.h"*/
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


void inicializacao(listaref &ref/*, mesa ms, f_espera f_esp, pessoa pes*/, int ciclo) {//Fase inicial, se não houver dados gardados
	ciclo += 1;
	alterar_refeicao(ref);
	mostrar_refeicao(ref);
	//nova mesa
	//int tam_cantina = rand() % 20 + 30; //tamanho da cantina
	//tam_cantina = rand() % 20 + 30;//http://www.cplusplus.com/forum/general/114978/ -> AeonFlux1212 ´"o rand convém ser acionado duas vezes para ter a certeza que gera um número aleatório 
	
	
		
	
}
/*void seguinte(listaref &ref, mesa ms, f_espera f_esp, pessoa pes,int ciclo){
	ciclo += 1;
	if (ciclo % 10 == 0) {
		alterar_refeicao(ref);
	}
}
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
	srand(time(NULL));
	locale::global(locale(""));
	listaref ref;
	pessoa pes;
	int ciclo=0;
	char opcao=' ';
	inicializacao(ref/*, ms, f_esp, pes*/,ciclo);
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