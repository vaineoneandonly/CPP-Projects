#include <iostream>
#include <vector>
#include <map>
#include <bits/stdc++.h>
#include <stack>
#include <queue>

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

    void printEdgesFrom(T v)
    {
        for (auto e : valueMap[v])
        {
            cout << e << '\n'; 
        }
    }

    vector<T> getEdgesFrom(T v)
    {
        return valueMap[v];
    }

    void depthTraverseFrom(T n)
    {
        stack<T> depthStack;

        T current {n};
        depthStack.push(current);

        while (!depthStack.empty())
        {
            vector<T> a {getEdgesFrom(current)};
            for (auto e : a)
            {
                depthStack.push(e);
            }

            cout << current << ' ';
            
            current = depthStack.top();
            a = getEdgesFrom(current);

            depthStack.pop();
        }
    }

    void breadthTraverseFrom(T n)
    {
        queue<T> breadthQueue;
        
        T current {n};
        breadthQueue.push(n);

        while (!breadthQueue.empty())
        {            
            vector<T> a {getEdgesFrom(current)};
            for (auto e : a)
            {
                breadthQueue.push(e);                
            }

            cout << current << ' ';

            breadthQueue.pop();
            current = breadthQueue.front();
            
            a = getEdgesFrom(current);
        }
    }
};

void testIntGraphFrom(int n)
{
    graph<int> g1;
    g1.addNode(2, {1, 3, 4});
    g1.addEdges(2, {9});
    g1.addNode(1, {3});
    g1.addNode(4, {1, 3});
    //g1.printValueMap();

    g1.addEdges(5, {7, 8, 9});
    //g1.printValueMap();

    g1.addNode(8, {2, 3, 4});
    //g1.printValueMap();
    
    g1.depthTraverseFrom(n);
}

void testCharGraphFrom(char c)
{
    graph<char> g2;
    g2.addNode('A', {'B', 'C'});
    g2.addNode('B', {'D'});
    g2.addNode('C', {'E'});
    g2.addNode('D', {'F'});
    g2.addNode('E', {});
    //g2.printValueMap();

    //g2.depthTraverseFrom(c);
    g2.breadthTraverseFrom(c);
}

int main(int argc, char **argv)
{
    //testIntGraphFrom(2);
    testCharGraphFrom(*argv[1]);
}