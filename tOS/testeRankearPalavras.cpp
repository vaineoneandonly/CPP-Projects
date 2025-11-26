#include <iostream>

#include "palavras.hpp"
#include "verbos.hpp"

int main()
{
    Palavra p1 {"correr"};
    Verbo novoVerbo {p1};
    
    for (Classificacao c = Classificacao::irregular; static_cast<int>(c) < 5; c = stati)
    {
        std::cout << static_cast<int>(c);
    }


    if  
    (
        p1.nome.substr(p1.nome.length()-2, p1.nome.length()-1) == "ar" ||
        p1.nome.substr(p1.nome.length()-2, p1.nome.length()-1) == "er" ||
        p1.nome.substr(p1.nome.length()-2, p1.nome.length()-1) == "ir" 
    )
    {
        for (Classificacao c = Classificacao::irregular; static_cast<int>(c) < 5;)
        {
            novoVerbo.classificacao.remove(c);
        }
    }
}
