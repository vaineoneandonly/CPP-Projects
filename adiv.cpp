#include <iostream>
#include <random>

int main()
{
    constexpr int maxNumber {100};
    int chosen {99};

    int currMax {maxNumber};
    int currMin {0};

    float tentative;
    int x;
    
    std::cout << tentative << '\n';
    while (fabs(chosen - tentative) > 0.5)
    {
        if (tentative > chosen)
        {
            currMax = tentative;
        } 
        else if (tentative < chosen)
        {
            currMin = tentative;
        }
        
        std::cout << tentative << '\n';
        tentative = (currMax + currMin) / 2;
    }

    std::cout << tentative;

}