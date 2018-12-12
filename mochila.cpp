#include "mochila.h"
#include "funcoes.h"
#include <cmath>
#include <algorithm>
#include <iostream>

using namespace std;

Mochila::Mochila(vector<Item> _cromossomo)
{
    cromossomo = _cromossomo;
}

Mochila Mochila::crossover(Mochila m2)
{
    vector<Item> childBag;
    int len = cromossomo.size();
    for(int i = 0; i < len; i++){
        float p = random_num(0, 100)/100;
        if(p < 0.25){
            childBag.push_back(cromossomo[i]);}
        else if(p < 0.65) {
            childBag.push_back(m2.cromossomo[i]);}
        else{
            childBag.push_back(mutacao(cromossomo));
        }
    }
    return childBag;
}

Item Mochila::mutacao(vector<Item> _cromossomo)
{
    random_shuffle(_cromossomo.begin(), _cromossomo.end());
    return _cromossomo[0];
}

void Mochila::setFitness()
{
    int len = cromossomo.size();
    float peso = 0;
    int beneficio = 0;
    for(int i = 0; i < len; ++i){
        peso += cromossomo[i].peso;
        beneficio += cromossomo[i].beneficio;
    }

    this->fitness = (beneficio/peso)*100 - exp(this->repeticao);
}

void Mochila::setPeso()
{
    int len = cromossomo.size();
    float peso = 0;
    for(int i = 0; i < len; ++i){
        peso += cromossomo[i].peso;
    }
    this->peso = peso;
}

void Mochila::setRepeticao(Item itens[MAX_ITENS], int qtd_itens)
{
    int aparicoes = 0;
    int aux = 0;
    for(int i = 0; i < qtd_itens; ++i){
        aparicoes = count(cromossomo.begin(), cromossomo.end(), itens[i]);
        if(aparicoes >= 2){
            aux += aparicoes;
        }
    }
    repeticao = aux;
}
