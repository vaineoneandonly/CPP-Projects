#include <iostream>
#include <fstream>

int main()
{
    std::string modelo {"I 656-7446 00                                            PC 6567446#00                   1104"};
    
    std::ifstream products{"prodAndVer"}; // <<<
    std::string prod {"6138152	90"};

    std::ofstream newProds{"newProds"};
    
    while (std::getline(products, prod))
    { 
        std::string prodStart {prod.substr(0, 3)};
        std::string prodEnd   {prod.substr(3, 4)};
        std::string prodVer   {prod.substr(8, 2)};

        modelo.replace(2,  3, prodStart);
        modelo.replace(6,  4, prodEnd);
        modelo.replace(11, 2, prodVer);

        modelo.replace(60, 3, prodStart);
        modelo.replace(63, 4, prodEnd);
        modelo.replace(68, 2, prodVer);

        newProds << modelo << '\n';
    }
}