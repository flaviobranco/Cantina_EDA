#include <iostream>
#include <string>
#include "Refeição.h"
#include "aluno_staff.h"
#include "Mesa.h"
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
	alterar_refeicao(ref);
	/*int tam = rand()%30+20; //tamanho da cantina
	tam = rand() % 30 + 20;//http://www.cplusplus.com/forum/general/114978/ -> AeonFlux1212 ´"o rand convém ser acionado duas vezes para ter a certeza que gera um número aleatório 
	int n_mesa = 0;//número de mesas
	int rnd=random_mesa(); //n cadeiras por mesa
	rnd = random_mesa();//http://www.cplusplus.com/forum/general/114978/ -> AeonFlux1212
	int tam_ant=0;//se tam <=1
	while (tam != 0) {
		if(tam <= 1) {
			inserir_mesas(ms, n_mesa, 0);
			n_mesa -= 1;
			tam = tam_ant;
		}
		else {
			n_mesa += 1;
			inserir_mesas(ms, n_mesa, rnd);
			tam_ant = tam;
			tam = tam - rnd;
			rnd = random_mesa();
		}
	}
	//mostrar_mesas(mesa, n_mesa);
	//nova pessoa(aluno/staff) nova fila
	
	int tam_pessoa = rand()%50+30; //1ª entrega, fila com o máximo de 50 pessoas
	int pos_especial = 0; //para os alunos especiais
	for (int i = 1; i <= tam_pessoa; i++) {
		criar_pessoa(pes, i);
	};
	for (int i = 1; i <= tam_pessoa; i++) {
		mostrar_pessoa(pes, i);
	};
	//verificar_repeticao(pessoa, tam_pessoa);
	for (int i = 0; i <= tam_pessoa; i++) { //primeiro inserir, depois ordenar
		adicionar_fila_espera(f_esp, i, pes);
	}*/
}
void extrair(){

}
void guardar() {

}
void opcoes() {

}
void menu(refeicao* ref, mesa* ms, f_espera* f_esp, pessoa* pes){
	centerstring("Cantina EDA");
	cout << endl;
	cout << "(s)Seguinte (e)Emergência (g)Gravar (c)Carregar Dados (o)Opções" << endl;
	cout << endl;
	mostrar_refeicao (ref);
	//mostrar_fila(f_esp);
}

void comando(char* opcao) {
	cout << "**** Comando: ";
	cin >> opcao;
}
int main() {
	srand(time(NULL));
	refeicao* ref = new struct refeicao;  //é preciso criar as variáveis primeiro,independentemente de haver dados guardados ou não
	mesa* ms = new struct mesa[20];
	f_espera* f_esp = new struct f_espera[51];
	pessoa* pes = new struct pessoa[51];
	const char *opcao;
	inicializacao(ref,ms,f_esp,pes);
	menu(ref, ms, f_esp, pes);
	//extrair();
	return 0;
}