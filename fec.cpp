#include <iostream>
#include "CLILIB.cpp"

int main()
{
    Screen background {9, 16, 'x'};
    Screen composite{9, 16, 'x'};

    Rect r1 {3, 0, 5, 5};

    for (int i = 0; i < background.screenHeight; ++i)
    {
        for (int j = 0; j < background.screenWidth; ++j)
        {    
            std::string a {background.map.at(i * j)};
            composite.map.append(a);
        }
    }   
    
    for (int i = r1.x; i < r1.l; ++i)
    {
        composite.map.replace(i, 0, "1");
    }
    std::cout << composite;
    
}