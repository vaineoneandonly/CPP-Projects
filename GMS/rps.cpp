#include <iostream>

unsigned int retornaIndiceJogada(std::string jogada)
{
    if (jogada == "pedra")
    {
        return 0;
    }
    else if (jogada == "papel")
    {
        return 1;
    }
    else if (jogada == "tesoura")
    {
        return 2;
    }
    else
    {
        return 3;
    }
}

int main()
{
    std::string resultados[3][3]
    {               // P2
                  // ped   pap   tes
        /*ped*/    {"NA", "P2", "P1"},
        /*P1 pap*/ {"P1", "NA", "P2"},
        /*tes*/    {"P2", "P1", "NA"},
    };

    std::string jogadaP1{"tesoura"};
    std::string jogadaP2{"papel"};

    unsigned int indiceP1{retornaIndiceJogada(jogadaP1)};
    unsigned int indiceP2{retornaIndiceJogada(jogadaP2)};

    std::cout << "P1 jogou " << jogadaP1 << '\n'  
              <<"e P2 jogou " << jogadaP2 << ".\n"
              <<"resultado: " << resultados[indiceP1][indiceP2] << '\n';
}