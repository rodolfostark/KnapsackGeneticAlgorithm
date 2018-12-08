#include "mochila.h"
#include "funcoes.h"
#include <iostream>
#include <fstream>

#include <cstring>
#include <locale.h>
#include <sstream>
#include <cstdlib>

using namespace std;

int main()
{
    setlocale(LC_ALL, "Portuguese");

    ConfigBag config;
    Item itens[MAX_ITENS];

    int qt_config=0, qt_itens=0;

    ifstream arquivoConfig("/home/john/workspace/BagGA/config.csv");
    if(arquivoConfig.is_open())
    {
        while(arquivoConfig.good())
        {
            if(qt_config==0)
            {
                qt_config++;
                continue;
            }
            /*
            getInt(ip,config.qt_itens,';');
            getline(ip,config.peso_suportado,';');
            getline(ip,config.populacao,';');
            getline(ip,config.timeout_sec,'\n');
            */
        }
        arquivoConfig.close();
    }
    else
    {
        cout<<"ERRO AO CARREGAR AS CONFIGURAÇÕES!";
    }

    fstream arquivoItens("/home/john/workspace/BagGA/lista_itens.txt");
    if(arquivoItens.is_open())
    {
        while(arquivoItens.good())
        {
            if(qt_itens==0)
            {
                qt_itens++;
                continue;
            }
            cout<<"arquivo encontrado"<<endl;
        }

        arquivoItens.close();

    }
    else
    {
        cout<<"ERRO AO CARREGAR OS ITENS!";
    }

    return 0;
}
