#include <iostream>
#include <vector>
#include <map>
#include <bits/stdc++.h>

using namespace std;

template <typename T>
struct graph
{
    map<T, vector<T>> valueMap;

    void addNode(T n, vector<T> e)
    {
        valueMap[n] = e;
    }

    void addEdges(T n, vector<T> m)
    {
        for (auto v : m)
        {
            valueMap[n].push_back(v);
        }
    }
    void printValueMap()
    {
        for (auto v : valueMap)
        {
            int i {0};
            cout << v.first << " -> ";
            for (auto e : v.second)
            {
                cout << e;
                if (i != v.second.capacity() - 1) cout << ", ";
                ++i;
            }
            cout << '\n';
        }
        cout << '\n';
    }
};

int main()
{
    graph<int> g1;
    g1.addNode(2, {1, 3, 4});
    g1.addEdges(2, {9});
    g1.addNode(1, {3});
    g1.addNode(4, {1, 3});
    g1.printValueMap();

    g1.addEdges(5, {7, 8, 9});
    g1.printValueMap();

    g1.addNode(8, {2, 3, 4});
    g1.printValueMap();

    graph<char> g2;
    g2.addNode('F', {'S', 'A', 'Y'});
    g2.printValueMap();
}