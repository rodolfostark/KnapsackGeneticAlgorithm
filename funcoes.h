#ifndef FUNCOES_H
#define FUNCOES_H

#include <vector>
#include "mochila.h"
#define MAX_ITENS 20

int random_num(int start, int end);
bool operator <(const Mochila &m1, const Mochila &m2);
vector<Item> gerarCromossomo(Item listaItens[MAX_ITENS], int qt_itens);
void imprimir_itens(Item itens[MAX_ITENS], int tamanho);
void imprimir_config(ConfigBag configuracoes);

#endif // FUNCOES_H
