#pragma once
struct refeicao {
	std::string entrada;
	std::string  prato;
	float preço;
};

void alterar_refeicao(refeicao* refeicao);
void mostrar_refeicao(refeicao* refeicao);