
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
	while (tam_aux != 0) {
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
		enumerar_mesa(ms, pos_aux, 0);
		cap_mesa(ms, pos_aux, 0);
		while_aux -= 1;
		pos_aux += 1;
	}
	q_mesa(ms, pos_mesa_aux);
	//nova pessoa(aluno/staff) nova fila
	int tam_pessoa = 50;
	inserir_tam_fila(f_esp, tam_pessoa);
	for (int i = 1; i <= tm_fila(f_esp); i++) {
		criar_pessoa(pes, i);
		adicionar_fila_espera(f_esp, i, pes, i);
	};
	//por pessoas que estão na fila para a mesa
	for (int i = 1; i <= n_can(ms); i++) {
		por_pessoa_mesa(ms, i, f_esp[i].pessoa);
		retirar_fila_espera(f_esp);
	}
}
void seguinte(refeicao* ref, mesa* ms, f_espera* f_esp, pessoa* pes,int ciclo){

}
void emergencia(mesa*ms,pessoa*pes){

}
void extrair(refeicao* ref, mesa* ms, f_espera* f_esp, pessoa* pes, int ciclo){

}
void guardar(refeicao* ref, mesa* ms, f_espera* f_esp, pessoa* pes, int ciclo) {

}
void carregar(refeicao* ref, mesa* ms, f_espera* f_esp, pessoa* pes, int ciclo) {

}
void opcoes(refeicao* ref, mesa* ms, f_espera* f_esp, pessoa* pes) {
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
}
void menu(refeicao* ref, mesa* ms, f_espera* f_esp, pessoa* pes){
	centerstring("Cantina EDA");
	cout << endl;
	cout << "(s)Seguinte (e)Emergência (g)Gravar (c)Carregar Dados (o)Opções (x)Sair" << endl;
	cout << endl;
	mostrar_refeicao (ref);
	cout << endl;
	mostrar_mesas(ms);
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
	struct pessoa* pes = new struct pessoa[101];
	int ciclo;
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
			default: {
				cout << "Escolha uma opção válida." << endl;
			}
			}
		}
	} while (opcao != 'x');
	return 0;
}

