/*
Implement the function unique_in_order which 
takes as argument a sequence and returns a list of items 
without any elements with the same value next to each other 
and preserving the original order of elements.

For example:

uniqueInOrder("AAAABBBCCDAABBB") == {'A', 'B', 'C', 'D', 'A', 'B'}
uniqueInOrder("ABBCcAD")         == {'A', 'B', 'C', 'c', 'A', 'D'}
uniqueInOrder([1,2,2,3,3])       == {1,2,3}

*/
#include<iostream>
#include <list> 
#include <vector>

#define PRINT(v) for (auto e : v) std::cout << e << std::endl

template <typename T>
std::vector<T> returnUniques(std::vector<T> &v)
{
    //std::vector<char>::iterator  replaced by auto easily.
    for (auto i = v.begin(); i != --v.end(); ++i)
    {
        if (*i == *(std::next(i))) 
        {
            std::cout << "found same!" << std::endl;
            v.erase(std::next(i));
        }   
    }

    return v;
}

int main()
{
    std::vector<char>   allCaps {'A', 'A', 'C', 'D', 'A', 'B'};
    std::vector<int>    nummies {1, 1, 4, 5, 8, 9};

    PRINT(allCaps);
    
    returnUniques(allCaps);
    
    PRINT(allCaps);
}
