#pragma once

#include <iostream>
#include <vector>
#include <limits>

using namespace std;

bool checarTransicao(vector<vector<float>> t, int origem, int destino, vector<float> soma)
{
    cout << "checando transição do índice " << origem << " para o índice " << destino << '\n';
    soma.push_back(t[origem][destino]);
    if (t[origem][destino] != 0)
    {
        for (auto v : soma) cout << v << " -> ";
        cout << "\n";

        return true;
    }
    else
    {
        for (int i = 0; i < t.size(); ++i) 
        {
            if (t[i][destino] != 0) 
            {
                checarTransicao(t, origem, i, soma);
                if (t[origem][i] != 0)
                {
                    return true;
                }
                else
                {
                    return false;
                }
            }
        }
    }

    return false;
}

int encontrarIdxMaisProximo(vector<vector<float>> grafo, int origem)
{
    int idxMaisProximo {-1};
    float valorMaisProximo {numeric_limits<float>::max()};
    for (int i = 0; i < grafo[origem].size(); ++i)
    {
        if (grafo[origem][i] != 0 && grafo[origem][i] < valorMaisProximo)
        {
            idxMaisProximo = i;
            valorMaisProximo = grafo[origem][i]; 
        }    
    }

    return idxMaisProximo;
}