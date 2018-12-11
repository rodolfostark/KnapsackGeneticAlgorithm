#include "mochila.h"
#include "funcoes.h"
#include <cmath>
#include <algorithm>

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
        if(p < 0.45){
            childBag.push_back(cromossomo[i]);}
        else if(p < 0.90) {
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
        peso += 0.5 * cromossomo[i].peso;
        beneficio +=2 * cromossomo[i].beneficio;
    }

    this->fitness = (beneficio/peso) - this->repeticao;
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
void Mochila::setRepeticao()
{
    int len = cromossomo.size();
    int rep=0;
    //contando repetidos
    for(int i = 0; i < len; ++i){
        for(int j = 0; j < len; ++i){
            if(i!=j){
                if(cromossomo[i].nome==cromossomo[j].nome){
                    rep++;
                }
            }
        }
    }
    this->repeticao = rep;
}
