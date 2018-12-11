#include "mochila.h"
#include "funcoes.h"
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <list>
#include <cstring>
#include <locale.h>
#include <sstream>
#include <cstdlib>
#include <vector>
#include <algorithm>

#define POPULACAO_MAX 100
#define MAX_ITENS 20

void imprimir_itens(Item i[MAX_ITENS], unsigned tam);
void imprimir_config(ConfigBag c);

using namespace std;

int main()
{
    setlocale(LC_ALL, "Portuguese");

    ConfigBag config[10];
    Item itens[MAX_ITENS];

    int qt_config=0, qt_itens=0;

    ifstream arquivoConfig("home/rodolfo/Documentos/C&T - COMPUTAÇÃO/4º SEMESTRE/TÓPICOS AVANÇADOS EM INFORMÁTICA I/BagGA/config.txt");
    if(arquivoConfig.is_open())
    {
        while(arquivoConfig.good())
        {
            ConfigBagString t;

            getline(arquivoConfig,t.peso_suportado,',');
            getline(arquivoConfig,t.populacao,',');
            getline(arquivoConfig,t.qt_itens,',');
            getline(arquivoConfig,t.timeout_sec,'\n');

            config[qt_itens].peso_suportado = stof(t.peso_suportado.c_str());
            config[qt_itens].populacao = stoi(t.populacao.c_str());
            config[qt_itens].qt_itens = stoi(t.qt_itens.c_str());
            config[qt_itens].timeout_sec = stoi(t.timeout_sec.c_str());

            qt_itens++;

        }
        arquivoConfig.close();
    }
    else
    {
        cout<<"ERRO AO CARREGAR AS CONFIGURAÇÕES!";
    }

    fstream arquivoItens("home/rodolfo/Documentos/C&T - COMPUTAÇÃO/4º SEMESTRE/TÓPICOS AVANÇADOS EM INFORMÁTICA I/BagGA/lista_itens.txt");
    if(arquivoItens.is_open())
    {
        while(arquivoItens.good())
        {
            if(qt_itens==0)
            {
                qt_itens++;
                continue;
            }
            else
            {
                ItemString i;

                getline(arquivoItens,i.nome,',');
                getline(arquivoItens,i.beneficio,',');
                getline(arquivoItens,i.peso,'\n');

                itens[qt_itens-3].nome = i.nome;
                itens[qt_itens-3].beneficio = stoi(i.beneficio.c_str());
                itens[qt_itens-3].peso = stof(i.peso.c_str());
            }

            qt_itens++;

        }
        //finalizando o vetor ja que nao está usando o push
        itens[qt_itens].nome='\0';

        arquivoItens.close();

    }
    else
    {
        cout<<"ERRO AO CARREGAR OS ITENS!";
    }

    imprimir_config(config[1]);
    cout<<"itens:"<<endl;
    imprimir_itens(itens,config[1].qt_itens);

    int numero_iteracoes = 0;
    vector<Mochila> populacao;
    for(int i = 0;i < POPULACAO_MAX; i++){
        Mochila deCrianca(gerarCromossomo(itens, config[i]));
        populacao.push_back(deCrianca);
    }
    while(numero_iteracoes < 500){
        sort(populacao.begin(), populacao.end());
        //travei aqui!!!!
    }

    return 0;
}

void imprimir_config(ConfigBag c)
{
    cout<<"peso suportado pela mochila:"<<c.peso_suportado<<endl;
    cout<<"numero da população utilizada no algoritmo:"<<c.populacao<<endl;
    cout<<"quantidade de itens disponiveis para adicionar na mochila:"<<c.qt_itens<<endl;
    cout<<"tempo limite em (s) de execução:"<<c.timeout_sec<<endl;
}

void imprimir_itens(Item item[MAX_ITENS], unsigned tam){

    for(unsigned i=0; i<tam; i++){

        cout<<item[i].nome<<" / "<<item[i].beneficio<<" / "<<item[i].peso<<endl;

    }
}
