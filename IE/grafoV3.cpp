#pragma once

#include <string>
#include <vector>
#include "vectorTools.cpp"
#include <limits>

//encontrar índice 2
int eci2(
    const vector<float>& dist,
    const vector<bool>& conhecidos)
{
    float menor = numeric_limits<float>::max();
    int idx = -1;

    for (int i = 0; i < dist.size(); ++i)
    {
        if (!conhecidos[i] && dist[i] < menor)
        {
            menor = dist[i];
            idx = i;
        }
    }

    return idx;
}

//menor caminho 2
void mc2(vector<vector<float>> &grafo, vector<string> &unicos, int idxOrigem)
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
        conhecidos[i] = true;
        for (int z = 0; z < unicos.size(); ++z)
        {
            if (grafo[i][z] != 0 && !conhecidos[z])
            {
                float novaDist {distanciaPara[i] + grafo[i][z]};
                if (novaDist < distanciaPara[z])
                {
                    distanciaPara[z] = novaDist; 
                }
            }
        }     
              
        mostrarVetor(conhecidos);
        mostrarVetor(distanciaPara);
        
        i = eci2(distanciaPara, conhecidos);
        if (i == -1) break;        
    }
}
