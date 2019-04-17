#include <iostream>
#include "Refeição.h"
#include "Mesa.h"
using namespace std;

int main() {
	int tam = rand() % 20+ 30;
	int max_mesa=0;
	mesa* mesa = new struct mesa;
	inserir_mesas(mesa, tam, max_mesa);
	mostrar_mesas(mesa, max_mesa);
	return 0;
}