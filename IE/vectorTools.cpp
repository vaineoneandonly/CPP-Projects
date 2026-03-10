#pragma once

#include <vector>

using namespace std;

bool todosVisitados(vector<bool>&conhecidos)
{
    for (auto c : conhecidos)
    {
        if (c == false) return false; 
    }

    return true;
}

template <typename T>
void mostrarVetor(vector<T> &v)
{
    for (auto e : v)
    {
        cout << e << "; ";
    }
    cout << '\n';
}