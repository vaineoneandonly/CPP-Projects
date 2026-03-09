#include <iostream>
#include <fstream>
#include <map>
#include <vector>
#include <algorithm>
#include <bits/stdc++.h>

using namespace std;

void checarCEP(int CEP, map<string, pair<int, int>> mapa)
{
    for (auto faixa : mapa)
    {
        if (CEP > faixa.second.first && CEP < faixa.second.second)
        {
            std::cout << "CEP " << CEP << " encontrado na cidade " << faixa.first 
                      << " (CEPs entre " << faixa.second.first << " e " << faixa.second.second << ")\n";
            break;
        } 
    }
}

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

    for (auto u : unicos)
    {
        cout << u << " - "; 
    }
    cout << '\n';

    vector<vector<float>> t {unicos.size(), vector<float>(unicos.size(), 0)};

    string novaLinha;
    ifstream nt {"IN/transicoes"};
    while (getline(nt, novaLinha))
    {
        string  origem {novaLinha[0]};
        string destino {novaLinha[2]};
        float valorCorrida{stof(novaLinha.substr(4, 4))};

        auto i {find(unicos.begin(), unicos.end(),  origem) - unicos.begin()};
        auto j {find(unicos.begin(), unicos.end(), destino) - unicos.begin()};

        t[i][j] = valorCorrida;
    }
}

