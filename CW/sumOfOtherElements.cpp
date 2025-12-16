#include <iostream>
#include <vector>

std::pair<int, int> sums(std::vector<int> &v,int pos)
{
    std::vector<int>::iterator i {&(v.at(pos))};
    std::vector<int>::iterator j {i};
    std::vector<int>::iterator k {i};

    std::pair<int, int> sums {0, 0};

    for (j, k; j != v.begin() && k != v.end(); --j, ++k)
    {
        sums.first  += *j;
        sums.second += *k;
    }

    return sums;
}

void daTru(std::vector<int> &v)
{
    
    int pos =  v.size()/2;
    auto s {sums(v, pos)};
    if (s.first == s.second) 
    {
        std::cout << "found!";
    
    }
    else
    {
        bool toLeft {std::rand() % 100 < 50 ? true : false};
        int i {0};
        int j {0};

        if (toLeft)
        {
            for (i = pos; i >= 0; --i)
            {
                s = sums(v, i);
                std::cout << s.first <<  ' ' << s.second << '\n';
                if (s.first == s.second) 
                {
                    std::cout << "found! ";
                    break;
                }
            }
        }
        else
        {
            for (j = pos; j < v.size(); ++j)
            {
                s = sums(v, j);
                std::cout << s.first <<  ' ' << s.second << '\n';
                if (s.first == s.second) 
                {
                    std::cout << "found! ";
                    break;
                }
            }
        }
        std::cout << i << '\n' << j << '\n';
    }

    std::cout << s.first << ' ' << s.second << '\n';
}

int main()
{
    std::vector<int> n1 {1,    2,      3,      4,      3,  2,      1};
    std::vector<int> n2 {1,    100,    50,     -51,    1,  1};
    std::vector<int> n3 { 20,10,30,10,10,15,35 };
    
    daTru(n2);
}
