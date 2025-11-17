#include <iostream>
#include <fstream>

int main()
{
    std::ifstream myfile;
    myfile.open("things");
    
    std::ofstream aNewOne;
    aNewOne.open("newThings");

    std::string a;
    while (std::getline(myfile, a))
    {
        aNewOne << a.substr(3, 6) << '\n';
    }
}