#include "mochila.h"
#include "funcoes.h"
#include <iostream>
#include <fstream>
#include <string>
#include <locale.h>
#include <cstdlib>
#include <vector>
#include <algorithm>

#define POPULACAO_MAX 100
#define MAX_ITENS 20

using namespace std;

int main()
{
    setlocale(LC_ALL, "Portuguese");

    ConfigBag config[10];
    Item itens[MAX_ITENS];

    int qt_config = 0;
    int qt_itens = 0;

    ifstream arquivoConfig;
    arquivoConfig.open("/home/rodolfo/Documentos/C&T - COMPUTAÇÃO/4º SEMESTRE/TÓPICOS AVANÇADOS EM INFORMÁTICA I/BagGA/config.txt");
    while(arquivoConfig.good())
    {
        ConfigBagString config_bag;
        getline(arquivoConfig,config_bag.peso_suportado,',');
        getline(arquivoConfig,config_bag.populacao,',');
        getline(arquivoConfig,config_bag.qt_itens,',');
        getline(arquivoConfig,config_bag.timeout_sec,'\n');
        config[qt_config].peso_suportado = atof(config_bag.peso_suportado.c_str());
        config[qt_config].populacao = atoi(config_bag.populacao.c_str());
        config[qt_config].qt_itens = atoi(config_bag.qt_itens.c_str());
        config[qt_config].timeout_sec = atoi(config_bag.timeout_sec.c_str());
        qt_config++;
    }
    if(!arquivoConfig.is_open()){
        cout << "ERRO AO CARREGAR AS CONFIGURAÇÕES!" << endl;
    }
    else{
        cout << "CONFIGURAÇÕES CARREGADAS COM SUCESSO." << endl;
        arquivoConfig.close();
    }
    ifstream arquivoItens;
    arquivoItens.open("/home/rodolfo/Documentos/C&T - COMPUTAÇÃO/4º SEMESTRE/TÓPICOS AVANÇADOS EM INFORMÁTICA I/BagGA/lista_itens.txt");
    while(arquivoItens.good()){
        ItemString item_string;
        getline(arquivoItens,item_string.nome,',');
        getline(arquivoItens,item_string.beneficio,',');
        getline(arquivoItens,item_string.peso,'\n');
        itens[qt_itens].nome = item_string.nome.c_str();
        itens[qt_itens].beneficio = atoi(item_string.beneficio.c_str());
        itens[qt_itens].peso = atof(item_string.peso.c_str());
        qt_itens++;
    }
    if(!arquivoItens.is_open()){
        cout<< "ERRO AO CARREGAR OS ITENS!" << endl;
    }
    else {
        cout << "ITENS CARREGADOS COM SUCESSO." << endl;
        arquivoItens.close();
    }
    imprimir_config(config[1]);
    cout << "Itens: "<< endl;
    //imprimir_itens(itens, qt_itens);
    //Até aqui é pré-processamento dos itens e possíveis configurações
    cout << " foram comentados." << endl;
    int numero_iteracoes = 0;
    vector<Mochila> populacao;
    for(int i = 0;i < POPULACAO_MAX/qt_config; ++i){
        float fit = 0;
        for(int j = 0; j < qt_config; ++j){
            Mochila deCrianca(gerarCromossomo(itens, qt_itens, fit));
            deCrianca.fitness = fit;
            cout << "nome: "  << deCrianca.cromossomo[0].nome << endl;
            cout << "beneficio: "  << deCrianca.cromossomo[0].beneficio << endl;
            cout << "fitness: "<< fit << endl;
            populacao.push_back(deCrianca);
        }
    }
    cout << " foram comentados." << endl;
    while(numero_iteracoes < 100){
        sort(populacao.begin(), populacao.end());
        vector<Mochila> nova_populacao;
        int s = (10*POPULACAO_MAX)/100;
        for(int i = 0;i < s;i++){
            nova_populacao.push_back(populacao[i]);
        }
        s = (90*POPULACAO_MAX)/100;
        for(int i = 0;i < s;i++){
            int r = random_num(0, 50);
            Mochila deCrianca1 = populacao[r];
            r = random_num(0, 50);
            Mochila deCrianca2 = populacao[r];
            Mochila belzebu = deCrianca1.crossover(deCrianca2);
            nova_populacao.push_back(belzebu);
        }
        populacao = nova_populacao;/*
        cout << "Melhor mochila: " << endl;
        int pop_len = populacao.size();
        int cromo_len = populacao[0].cromossomo.size();
        for(int i = 0; i < pop_len; i++){
            for(int j = 0; j < cromo_len; ++j){
                cout << "Nome: " << populacao[i].cromossomo[j].nome << endl;
                cout << "Peso: " << populacao[i].cromossomo[j].peso << endl;
            }
            cout << "Fitness: " << populacao[0].fitness << endl;
        }*/
        numero_iteracoes++;
    }
    cout << " foram comentados." << endl;
    return 0;
}


