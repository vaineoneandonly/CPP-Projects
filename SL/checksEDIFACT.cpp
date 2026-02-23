#include <iostream>
#include <fstream>
#include <string.h>

int main()
{
    std::ifstream  inFile {"IN/arquivoCru"};
    std::ofstream outFile {"OUT/saindoCoisa"};

    std::string newLine;
    while (std::getline(inFile, newLine))
    {
        if (newLine.substr(0, 3) == "LIN")
        {
            outFile << newLine;
        }
        else if (newLine.substr(0, 3) == "IMD")
        {
            outFile << newLine << '\n';
        }
    }

}