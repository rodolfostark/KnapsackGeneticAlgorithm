#include "funcoes.h"
#include <cmath>
#define MAX_ITENS 20

int random_num(int start, int end)
{
    int range = (end-start)+1;
    int random_int = start+(rand()%range);
    return random_int;
}

bool operator <(const Mochila &m1, const Mochila &m2)
{
    return m1.fitness < m2.fitness;
}

vector<Item> gerarCromossomo(Item listaItens[MAX_ITENS], ConfigBag config)
{
    vector<Item> cromossomo;
    int len = config.qt_itens;
    for(int i = 0; i < len; i++){
        int  index = random_num(0 , len-1);
        cromossomo.push_back(listaItens[index]);
    }
    return cromossomo;
}
