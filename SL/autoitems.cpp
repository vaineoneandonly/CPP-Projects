#include <iostream>
#include <fstream>

int main()
{
    std::string modelo       {"I 656-7446 00                                            PC 6567446#00                   962 "};
    std::string modeloDAFMAG {"I ATRC292                                                PC ATRC292#VV                   962 "};

    std::ifstream products{"prodAndVerDAFMAGIUSFILIAL"}; // <<<
    std::string prod {"6138152	90"};

    std::ofstream newProds{"newProdsDAFMAG"};
    
    while (std::getline(products, prod))
    {
        //std::string prodStart {prod.substr(0, 3)};
        //std::string prodEnd   {prod.substr(3, 4)};
        
        std::string justProd {prod.substr(0, 7)};
        std::string prodVer   {prod.substr(8, 2)};



        //std::cout << prod.substr(0, 7) << ' ' << prod.substr(8, 2) << '\n';

        modeloDAFMAG.replace(2, 7, justProd);
        modeloDAFMAG.replace(60, 7, justProd);

        //modeloDAFMAG.replace(11, 2, prodVer);
        modeloDAFMAG.replace(68, 2, prodVer);
        
        newProds << modeloDAFMAG << '\n';


        //qqmodeloDAFMAG.replace(63, 4, prodEnd);

        //std::cout << modeloDAFMAG << '\n';
        //newProds << modeloDAFMAG << '\n';
    }
}