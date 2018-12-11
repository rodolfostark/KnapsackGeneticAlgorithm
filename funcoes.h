#ifndef FUNCOES_H
#define FUNCOES_H

#include <vector>
#include "mochila.h"
#define MAX_ITENS 20

int random_num(int start, int end);
bool operator <(const Mochila &m1, const Mochila &m2);
vector<Item> gerarCromossomo(Item listaItens[MAX_ITENS], ConfigBag config);

#endif // FUNCOES_H
