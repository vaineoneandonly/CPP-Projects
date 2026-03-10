#pragma once

#include <iostream>
#include <vector>
#include <limits>
#include "vectorTools.cpp"

using namespace std;

int encontrarIdxMaisProximoNaoConhecido(vector<vector<float>> &grafo, vector<bool> &conhecidos, int origem)
{
    int idxMaisProximo {-1};
    float valorMaisProximo {numeric_limits<float>::max()};
    for (int i = 0; i < grafo[origem].size(); ++i)
    {
        if (!conhecidos[i] && grafo[origem][i] != 0 && grafo[origem][i] < valorMaisProximo)
        {
            idxMaisProximo = i;
            valorMaisProximo = grafo[origem][i]; 
        }    
    }

    return idxMaisProximo;
}

void menorCaminho(vector<vector<float>> grafo, vector<string> unicos, int idxOrigem)
{
    vector<bool> conhecidos;
    vector<float> distanciaPara;

    for (int i = 0; i < unicos.size(); ++i)
    {
        conhecidos.push_back(false);
        distanciaPara.push_back(numeric_limits<float>::max());
    }

    distanciaPara[idxOrigem] = 0;

    mostrarVetor(distanciaPara);
    
    int i {idxOrigem};
    while (!todosVisitados(conhecidos))
    {
        for (int z = 0; z < unicos.size(); ++z)
        {
            if (grafo[i][z] < distanciaPara[z] && grafo[i][z] != 0)
            {
                if (distanciaPara[z] == numeric_limits<float>::max())
                {
                    distanciaPara[z] = grafo[i][z]; 
                }
                else
                {
                    distanciaPara[z] += grafo[i][z];
                }
            }
        }     
              
        mostrarVetor(conhecidos);
        mostrarVetor(distanciaPara);
        conhecidos[i] = true;

        i = encontrarIdxMaisProximoNaoConhecido(grafo, conhecidos, i);
        if (i == -1) break;        
    }
}