/*#pragma once
#include"Mesa.h"
#include "Refeição.h"
#include "pessoa_cantina.h"
#include <string>

struct pessoas_removidas{
pessoa_cantina*centro;
pessoa_cantina*esquerda;
pessoa_cantina*direira;
}


void guardar(refeicao ref, f_espera f_esp, cantina cant);
void carregar(refeicao ref, f_espera f_esp, cantina cant);
void guardar_auto_pessoas(pessoa pes);//guardar aqueles que não tem plafond suficiente(f_espera), ou quem saiu da refeição por emergência(mesa)*/