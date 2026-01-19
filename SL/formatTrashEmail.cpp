#include <iostream>
#include <fstream>
#include <string.h>

int main()
{
    std::ifstream  inFile {"IN/renaultRef"};
    std::ofstream outFile {"OUT/renaultRefStupid"};

    std::string newLine;
    std::string formatted;
    int count {0};

    while (std::getline(inFile, newLine))
    {
        if (count < 11)
        {
            if (count == 0 || count == 2)
            {
                outFile << newLine;
            }
            else if (count == 1)
            {
                outFile << ':';
            }
            ++count;
        }
        else
        {
            outFile << '\n';
            count = 0;
        }
        
    }
}