#include <iostream>
#include <fstream>
#include <vector>

int main()
{
    //one line for the name, one line for the description. Description doesn't matter if
    //the name of the entity is different from the next one.

    std::ifstream inputFile {"IN/parceiros.txt"};
    std::ofstream outputFile {"OUT/parceirosFORTBRAS.txt"};

    std::vector<std::string>  nameList;
    std::vector<std::string> placeList;

    bool sendingToNameList {true};

    std::string line;
    while (std::getline(inputFile, line))
    {
        if (sendingToNameList)
        {
            nameList.push_back(line);
        }
        else
        {
            line.pop_back();
            placeList.push_back(line);
        }

        sendingToNameList = !sendingToNameList;
    }

    for (int i = 0; i < nameList.size() - 1; ++i)
    {
        std::string aooga;

        if (nameList[i] == nameList[i+1] || nameList[i] == nameList[i-1])
        {
            aooga = nameList[i].substr(0, nameList[i].size() - 1) + " - " + placeList[i];
        }
        else
        {
            aooga = nameList[i];         
        }
        
        outputFile << aooga << '\n';
    }
}