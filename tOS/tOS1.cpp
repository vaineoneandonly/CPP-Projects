#include <iostream>

enum Conjugacao
{
    Eu,
    Tu,
    Ele,
    Nos,
    Vos,
    Eles,
};

int main()
{
    const std::string Terminacoes[3] {"ar", "er", "ir"}; 
    const std::string verbos[3] {"rezar", "andar", "aturdir"};

    const std::string   PresenteIndicativo[3][6]
                        {
                            {"o", "as", "a", "amos", "ais", "am"},
                            {"o", "es", "e", "emos", "eis", "em"},
                            {"o", "es", "e", "imos",  "is", "em"},
                        };

        
    for (int j = 0; j < 3; ++j)
    {
        std::string verboAtual {verbos[j]};
        std::string terminaCom {verboAtual.substr( verboAtual.length()-2, verboAtual.length()-1)};
        
        int c//ategoria
        {
            terminaCom == "ar" ? 0 : 
            terminaCom == "er" ? 1 :
            terminaCom == "ir" ? 2 : 
            3
        };

        for (int i = 0; i < 6; ++i)
        {
            std::cout << verboAtual.substr(0, verboAtual.length()-2) << PresenteIndicativo[c][i] << '\n';
        }
        std::cout << '\n';
    }
}