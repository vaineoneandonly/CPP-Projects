#include <iostream>
#include <fstream>
#include <map>
#include <vector>
#include <bits/stdc++.h>
#include <limits>

#include "grafoV1.cpp"
#include "grafoV2.cpp"
#include "grafoV3.cpp"
#include "vectorTools.cpp"
#include "definicoesCEP.cpp"

using namespace std;

int main()
{
    map<string, pair<int, int>> mapaDeFaixas;
    
    ifstream faixasDeCEP {"IN/CEPs"};
    string linhaFaixa;
    while (getline(faixasDeCEP, linhaFaixa))
    {
        string nome {linhaFaixa[0]};
        int min {stoi(linhaFaixa.substr(2, 9))};
        int max {stoi(linhaFaixa.substr(11))};

        if (min > max) swap(min, max);

        mapaDeFaixas[nome] = {min, max};
    }
    
    checarCEP(60000330, mapaDeFaixas);

    //ex2 a partir daqui
    vector<string> unicos;
    string linhaTransicao;
    ifstream transicoesDeCEP {"IN/transicoes"};
    while (getline(transicoesDeCEP, linhaTransicao))
    {
        string  origem {linhaTransicao[0]};
        string destino {linhaTransicao[2]};
        if (count(unicos.begin(), unicos.end(), origem) == 0)
        {
            unicos.push_back(origem);
        }
        else if (count(unicos.begin(), unicos.end(), destino) == 0)
        {
            unicos.push_back(destino);
        }
    }

    vector<vector<float>> grafo {unicos.size(), vector<float>(unicos.size(), 0)};

    string novaLinha;
    ifstream nt {"IN/transicoes"};
    while (getline(nt, novaLinha))
    {
        string  origem {novaLinha[0]};
        string destino {novaLinha[2]};
        float valorCorrida{stof(novaLinha.substr(4, 4))};

        auto i {find(unicos.begin(), unicos.end(),  origem) - unicos.begin()};
        auto j {find(unicos.begin(), unicos.end(), destino) - unicos.begin()};

        grafo[i][j] = valorCorrida;
        grafo[j][i] = valorCorrida;
    }

    string   esseCEP {checarCEP(10001086, mapaDeFaixas)};
    string aqueleCEP {checarCEP(80000245, mapaDeFaixas)};

    auto   indiceDesseCEP {find(unicos.begin(), unicos.end(),   esseCEP) - unicos.begin()};
    auto indiceDaqueleCEP {find(unicos.begin(), unicos.end(), aqueleCEP) - unicos.begin()};

    //menor caminho 2
    mc2(grafo, unicos, indiceDesseCEP);
}
