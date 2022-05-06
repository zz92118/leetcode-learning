#include<iostream>
#include<unordered_map>
#include<vector>
#include<stack>
using namespace std;

//可以给多个类型使用的模版
template <class T> class Node
{
public:
    T value;
    Node(T v)
    {
        value=v;
    }
};

template <class T> class UnionFind
{
public:
    unordered_map<T, Node<T> > nodes;
    unordered_map<Node<T>,Node<T> > parents
    
};

int main()
{
    return 0;
}