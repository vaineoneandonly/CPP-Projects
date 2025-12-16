#include <iostream>
#include <string>
#include <vector>

int main()
{
    std::string word {"sdajkdskad"};
    std::string spaces;
    spaces.append(word.length(), '_');

    std::string guess;
    
    int limbs {6};
    
    system("clear");
    while (limbs != 0)
    {
        std::cout << spaces << '\n';

        std::cout << "guess a letter: ";
        std::cin >> guess;

        int cidx {0};
        for (char c : word) 
        {
            std::string currentChar {c};
            if (guess == currentChar)
            {
                std::cout << "found! \n";
                spaces.replace(cidx, 1, currentChar);
            }
            else
            {
                --limbs;
            }
            ++cidx;
        }

        std::cout << "\nany button to continue. ";
        std::cin >> guess;

        system("clear");
    }
}