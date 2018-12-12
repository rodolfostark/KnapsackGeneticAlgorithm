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
        peso += 0.5*cromossomo[i].peso;
        beneficio += 2*cromossomo[i].beneficio;
    }

    this->fitness = (beneficio/peso)*100 - 10*this->repeticao;
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
        if(aparicoes > 2){
            aux += aparicoes;
        }
    }
    repeticao = aux;
    cout << "Repeticoes: " << aux << endl;
}
//void Mochila::setRepeticao()
//{
//    int len = cromossomo.size();
//    int rep=0;

//    vector<Item> repete;
//    bool repetiu=false;

//    //contando repetidos
//    for(int i = 0; i < len; ++i){
//        for(int j = 0; j < len; ++j){
//            if(i!=j){
//                if(cromossomo[i].nome==cromossomo[j].nome){
//                    for(int k=0; k < repete.size();k++){
//                        if(cromossomo[i].nome == repete[k].nome){
//                            repetiu=true;
//                        }
//                    }
//                    if(!repetiu){
//                        repete.push_back(cromossomo[i]);
//                    }
//                }
//            }
//        }
//    }
//    for(int k=0; k < repete.size();k++){
//        for(int i = 0; i < len; ++i){
//            if(cromossomo[i].nome == repete[k].nome){
//                rep++;
//            }
//        }
//    }

//    this->repeticao = rep;
//}
