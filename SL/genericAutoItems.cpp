#include <iostream>
#include <fstream>
#include <string.h>

int main(int argc, char *argv[])
{
    std::ifstream  inFile {static_cast<std::string>(argv[1])};
    std::ofstream outFile {static_cast<std::string>(argv[2])};


    //prod local, versao, descricao, prod externo, codigo cliente
    
    std::string line;
    char delimiter {';'};
    while (std::getline(inFile, line, delimiter))
    {
        std::cout << line << '\n';
    }
}