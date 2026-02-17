#include <iostream>
#include <fstream>

void checkValueOfCharInString(std::string s)
{
    for (char c : s)
    {
        std::cout << c << "-" << static_cast<int>(c) << '\n';
    }
}

void JACTOparaGOLIN()
{
    //implementar um check de booleano se tiver versão
    //e outro se a versão fizer parte do produto local local

    //para produto local;descrição;produto externo. daria pra fazer uma parte só pra mapear essa leitura
    //que seria bem interessante.
    std::string inputLine {"0003930509;DISPOSITIVO DE CONTROLE DOBRA 1282906/1282907 - Nº 970013272;1282907/1282906 -CONTROLE"};

    int maximumDescriptionSize {35};

    int firstCommaIndex         {static_cast<int>(inputLine.find_first_of(';'))};
    int secondCommaIndex        {static_cast<int>(inputLine.substr(firstCommaIndex + 1).find_first_of(';')) + firstCommaIndex + 1};

    int localProductStart       {0};
    int localProductSize        {firstCommaIndex};

    int descriptionStart        {firstCommaIndex + 1};
    int descriptionSize         {secondCommaIndex - firstCommaIndex - 1};

    int externalProductStart    {secondCommaIndex + 1};
    int externalProductSize     {static_cast<int>(inputLine.find_first_of('\n')) - 1};

    std::string localProduct    {inputLine.substr(localProductStart, localProductSize)};

    std::string description     {inputLine.substr(descriptionStart, descriptionSize)};    
    if (description.size() > maximumDescriptionSize) description.resize(maximumDescriptionSize);

    std::string externalProduct {inputLine.substr(externalProductStart, externalProductSize)};

    std::cout   << localProduct     << " ends localProduct \n"
                << description      << " ends description \n"
                << externalProduct  << " ends externalProduct\n";
}

void paraVOLVO()
{
    std::string inputProd {"16929621 SAFETY DECAL WARNING HIGH VOLTAGE                 "};
    
    std::ifstream products {"modeloProdutosVOLVOPEDER"};
    std::ofstream prn {"novosProdutosVOLVOPEDER"};

    while (std::getline(products, inputProd))
    {
        int i {static_cast<int>(inputProd.find_first_of(' '))};

        std::string prod {inputProd.substr(0, i)};
        std::string desc2 {"                                   "};
        std::string desc {inputProd.substr(i+1, 35)};

        desc2.replace(0, desc.size(), desc);

        std::string outputProd {"I                                                         PC                              "};
        outputProd.replace(2, prod.size(), prod);
        outputProd.replace(61, prod.size(), prod);
    
        outputProd.replace(22, 35, desc2);
        
        prn << outputProd << '\n';
    }
}    

void paraCAT()
{
    std::string modelo       {"I xxxxxxxxxx                                              PC xxyyyy#vv                    "};
    
    std::ifstream products{"modeloProdutosVEXSP2"}; // <<<
    std::string prod {"1P-2807 07                     	-                                                 "};

    std::ofstream newProds{"novosProdutosVEXSP2"};
    
    while (std::getline(products, prod))
    {
        std::string prodStart        {prod.substr(0, 2)};
        std::string prodEnd          {prod.substr(3, 4)};
        std::string prodVer          {prod.substr(8, 2)};
        std::string prodDesc         {prod.substr(32, 35)};

        /*
        std::cout << prodStart << '-' 
                  << prodEnd << ' ' 
                  << prodVer << " description:" 
                  << prodDesc << '\n';
        */

        modelo.replace(2, 2, prodStart);
        modelo.replace(5, 4, prodEnd);
        modelo.replace(10, 2, prodVer);
        modelo.replace(22, 35, prodDesc);

        modelo.replace(61, 2, prodStart);
        modelo.replace(63, 4, prodEnd);
        modelo.replace(68, 2, prodVer);

        newProds << modelo << '\n';
        
        //modeloVEX.replace(2, 7, justProd);
        //modeloVEX.replace(60, 7, justProd);

        //modeloVEX.replace(11, 2, prodVer);
        //modeloVEX.replace(68, 2, prodVer);
        
        //newProds << modeloVEX << '\n';


        //qqmodeloVEX.replace(63, 4, prodEnd);

        //std::cout << modeloVEX << '\n';
        //newProds << modeloVEX << '\n';
    }
}


int main()
{
    //paraVOLVO();
    JACTOparaGOLIN();
    //checkValueOfCharInString("0003930705	SAC R  80,00 X 100,00 X  8,00	P0000000426");
}
