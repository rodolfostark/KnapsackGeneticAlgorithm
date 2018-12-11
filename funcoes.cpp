#include "funcoes.h"
#include <iostream>
#include <cmath>
#define MAX_ITENS 20

using namespace std;

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

vector<Item> gerarCromossomo(Item listaItens[MAX_ITENS], int qt_itens)
{
    vector<Item> cromossomo;
    int len = qt_itens;
    for(int i = 0; i < len-1; i++){
        int  index = random_num(0 , len-1);
        cromossomo.push_back(listaItens[index]);
    }
    return cromossomo;
}
void imprimir_config(ConfigBag configuracoes)
{
    cout << "Peso suportado pela mochila: "<< configuracoes.peso_suportado<< endl;
    cout << "Tamanho da população utilizada no algoritmo: "<< configuracoes.populacao<< endl;
    cout << "Quantidade de itens disponiveis para adicionar na mochila: "<< configuracoes.qt_itens<< endl;
    cout << "Tempo limite em (s) de execução: "<< configuracoes.timeout_sec << endl;
}

void imprimir_itens(Item itens[MAX_ITENS], int tamanho){
    for(int i = 0; i < tamanho-1; i++){
        cout<< itens[i].nome << " / "<< itens[i].beneficio << " / " << itens[i].peso << endl;
    }
}
