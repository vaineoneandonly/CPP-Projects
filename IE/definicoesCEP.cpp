#pragma once

#include <iostream>
#include <map>

using namespace std;

string checarCEP(int CEP, map<string, pair<int, int>> mapa)
{
    for (auto faixa : mapa)
    {
        if (CEP > faixa.second.first && CEP < faixa.second.second)
        {
            std::cout << "CEP " << CEP << " encontrado na cidade " << faixa.first 
                      << " (CEPs entre " << faixa.second.first << " e " << faixa.second.second << ")\n";

            return faixa.first;
        } 
    }

    return "";
}