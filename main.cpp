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

void imprimir_itens(Item itens[MAX_ITENS], int tamanho);
void imprimir_config(ConfigBag configuracoes);

using namespace std;

int main()
{
    setlocale(LC_ALL, "Portuguese");

    ConfigBag config[10];
    Item itens[MAX_ITENS];

    int qt_config = 0;
    int qt_itens = 0;

    fstream arquivoConfig;
    arquivoConfig.open("/home/rodolfo/Documentos/C&T - COMPUTAÇÃO/4º SEMESTRE/TÓPICOS AVANÇADOS EM INFORMÁTICA I/BagGA/config.txt");
    if(arquivoConfig.is_open())
    {
        while(arquivoConfig.good())
        {
            ConfigBagString config_bag;
            getline(arquivoConfig,config_bag.peso_suportado,',');
            getline(arquivoConfig,config_bag.populacao,',');
            getline(arquivoConfig,config_bag.qt_itens,',');
            getline(arquivoConfig,config_bag.timeout_sec,'\n');
            config[qt_itens].peso_suportado = stof(config_bag.peso_suportado.c_str());
            config[qt_itens].populacao = stoi(config_bag.populacao.c_str());
            config[qt_itens].qt_itens = stoi(config_bag.qt_itens.c_str());
            config[qt_itens].timeout_sec = stoi(config_bag.timeout_sec.c_str());
            qt_itens++;
        }
        arquivoConfig.close();
    }
    else
    {
        cout << "ERRO AO CARREGAR AS CONFIGURAÇÕES!" << endl;
    }
    fstream arquivoItens;
    arquivoItens.open("/home/rodolfo/Documentos/C&T - COMPUTAÇÃO/4º SEMESTRE/TÓPICOS AVANÇADOS EM INFORMÁTICA I/BagGA/lista_itens.txt");
    if(arquivoItens.is_open()){
        while(arquivoItens.good()){
            ItemString item_string;
            getline(arquivoItens,item_string.nome,',');
            getline(arquivoItens,item_string.beneficio,',');
            getline(arquivoItens,item_string.peso,'\n');
            itens[qt_itens-3].nome = item_string.nome;
            itens[qt_itens-3].beneficio = stoi(item_string.beneficio.c_str());
            itens[qt_itens-3].peso = stof(item_string.peso.c_str());
            qt_itens++;
        }
        //finalizando o vetor ja que nao está usando o push
        itens[qt_itens].nome += '\0';
        arquivoItens.close();
        cout << "Deu bom" << endl;
    }
    else{
        cout<< "ERRO AO CARREGAR OS ITENS!";
    }
    imprimir_config(config[1]);
    cout << "Itens: "<< endl;
    imprimir_itens(itens,config[1].qt_itens);
    //Até aqui é pré-processamento dos itens e possíveis configurações

    int numero_iteracoes = 0;
    vector<Mochila> populacao;
    for(int i = 0;i < POPULACAO_MAX; i++){
        float fit = 0;
        Mochila deCrianca(gerarCromossomo(itens, config[i], fit));
        deCrianca.fitness = fit;
        populacao.push_back(deCrianca);
    }
    while(numero_iteracoes < 500){
        sort(populacao.begin(), populacao.end());
    }

    return 0;
}

void imprimir_config(ConfigBag configuracoes)
{
    cout << "Peso suportado pela mochila: "<< configuracoes.peso_suportado<<endl;
    cout << "Tamanho da população utilizada no algoritmo: "<< configuracoes.populacao<<endl;
    cout << "Quantidade de itens disponiveis para adicionar na mochila: "<< configuracoes.qt_itens<<endl;
    cout << "Tempo limite em (s) de execução: "<< configuracoes.timeout_sec<<endl;
}

void imprimir_itens(Item itens[MAX_ITENS], int tamanho){
    for(int i = 0; i < tamanho; i++){
        cout<< itens[i].nome << " / "<< itens[i].beneficio << " / " << itens[i].peso << endl;
    }
}
