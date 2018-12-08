#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <list>

using namespace std;

int main()
{
    fstream arquivoItens;
    QString linha;
    list<string> lista;
    stringstream ss;
    string nome;
    int qtd_config;
    int qtd_itens;
    arquivoItens.open("/home/rodolfo/Documentos/C&T - COMPUTAÇÃO/4º SEMESTRE/TÓPICOS AVANÇADOS EM INFORMÁTICA I/BagGA/lista_itens.txt");
    while(arquivoItens.good()){
        getline(arquivoItens, linha);
        cout << linha << endl;
        linha += " ";
    }
    lista = linha.split()
    return 0;
}
