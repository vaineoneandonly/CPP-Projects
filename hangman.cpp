#include <iostream>
#include <string>
#include <vector>

int main()
{
    std::string a {"sdajkdskad"};
    std::string r;
    r.append(a.length(), '_');

    int i {static_cast<int>(a.find("k"))};

    std::vector<int> idxs {1, 2, 3};
    
    for (int i : idxs) 
    {
        std::cout << i << '\n';
        r.replace(i, 2, "o");
    }
    std::cout << r << '\n';    
    std::cout << "now?";
}