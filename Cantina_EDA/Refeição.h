#pragma once
struct refeicao {
	std::string entrada;
	std::string  prato;
	float pre�o;
};

void alterar_refeicao(refeicao* refeicao);
void mostrar_refeicao(refeicao* refeicao);