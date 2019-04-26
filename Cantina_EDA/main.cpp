#include <iostream>
#include <string>
#include "Refeição.h"
#include "aluno_staff.h"
#include "Mesa.h"
#include "time.h"
using namespace std;

void inicializacao() {//Fase inicial
	refeicao* refeicao=new struct refeicao; // criar refeição
	//alterar_refeicao(refeicao);
	int tam = rand()%30+20; //tamanho da cantina
	tam = rand() % 30 + 20;//http://www.cplusplus.com/forum/general/114978/ -> AeonFlux1212
	int n_mesa = 0;//número de mesas
	int rnd=random_mesa(); //n cadeiras por mesa
	rnd = random_mesa();//http://www.cplusplus.com/forum/general/114978/ -> AeonFlux1212
	int tam_ant=0;//se tam <=1
	mesa *mesa = new struct mesa[20];//criar a variável struct mesa com o nome "mesa"
	while (tam != 0) {
		if(tam <= 1) {
			inserir_mesas(mesa, n_mesa, 0);
			n_mesa -= 1;
			tam = tam_ant;
		}
		else {
			n_mesa += 1;
			inserir_mesas(mesa, n_mesa, rnd);
			tam_ant = tam;
			tam = tam - rnd;
			rnd = random_mesa();
		}
	}
	//mostrar_mesas(mesa, n_mesa);
	//nova pessoa(aluno/staff)
	int tam_pessoa = 50; //1ª entrega, fila com o máximo de 50 pessoas
	pessoa*pessoa = new struct pessoa[tam_pessoa];
	for (int i = 1; i <= tam_pessoa; i++) {
		criar_pessoa(pessoa,i);
		//mostrar_pessoa(pessoa, i);
	}
}
void extrair() {

}
void guardar() {

}
void opcoes() {

}
int main() {
	srand(time(0)); 
	inicializacao();
	extrair();
	return 0;
}