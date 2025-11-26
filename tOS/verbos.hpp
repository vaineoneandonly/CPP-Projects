#pragma once
#include "palavras.hpp"

enum class Classificacao
{
    regular,
    irregular,
    anomalo,
    defectivo,
    abundante
};
enum class Modo
{
    indicativo,
    subjuntivo,
    imperativo
};
enum class Tempo
{
    preteritoImperfeito,
    preteritoPerfeito,
    preteritoMaisQuePerfeito,
    presente,
    futuroDoPresente,
    futuroDoPreterito
};

struct Verbo : Palavra 
{
    std::list<Classificacao> classificacao
    {
        Classificacao::regular, 
        Classificacao::irregular, 
        Classificacao::anomalo, 
        Classificacao::defectivo, 
        Classificacao::abundante
    };

    std::list<Modo> modo 
    {
        Modo::indicativo, 
        Modo::subjuntivo, 
        Modo::imperativo
    };  
    
    std::list<Tempo> tempo
    {
        Tempo::preteritoImperfeito,
        Tempo::preteritoPerfeito,
        Tempo::preteritoMaisQuePerfeito,
        Tempo::presente,
        Tempo::futuroDoPresente,
        Tempo::futuroDoPreterito
    };

    void avaliarClassificacao()
    {

    }

    //Verbo(std::string novoVerbo)
    //{
    //    nome = novoVerbo;
    //    std::string terminaCom {nome.substr(nome.length()-2, nome.length()-1)};
    //    
    //    if (terminaCom == "ar" || terminaCom == "er" || terminaCom == "ir")
    //    {
    //        classificacao.erase(classificacao.begin() + 1, classificacao.)
    //    }
    //}

};





