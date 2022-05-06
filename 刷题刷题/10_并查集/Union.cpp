#include<iostream>
#include<unordered_map>
#include<vector>
#include<stack>
using namespace std;

/*
指针指针还是指针

*/

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
//都用指针
    unordered_map<T, Node<T>* > nodes; //每个value建立一个Node结构
    unordered_map<Node<T>* , Node<T>* > parents;//每个节点对应的father
    unordered_map<Node<T>*, int> sizeMap;//代表点对应 集合的大小 代表点就是一个集合的父节点
    //初始化
    UnionFind(vector<T> values)
    {
        for(int i=0;i<values.size();i++)
        {
            Node<T> *node=new Node<T>(values[i]);
            nodes[values[i]]=node;
            parents[node]=node;
            sizeMap[node]=1;
        }
    }
    //找到父节点
    Node<T>* findFather(Node<T>* curr)
    {
        stack< Node<T>* > path;
        //找到父节点,并且找到一路上的路径
        //扁平化优化方案
        while(curr!=parents[curr])
        {
            path.push(curr);
            curr = parents[curr];
        }
        //此时curr为父节点
        while(!path.empty())
        {
            parents[path.top()]=curr;
            path.pop();
        }

        return curr;
    }

    bool isSameSet(T a,T b)
    {
        if(!nodes.count(a) || !nodes.count(b))
        {
            return false;
        }
        return findFather(nodes[a])==findFather(nodes[b]);
    }

    void Union(T a,T b)
    {
        Node<T> *aHead = findFather(nodes[a]);
        Node<T> *bHead = findFather(nodes[b]);
        if(aHead!=bHead)//不在同一个集合才能继续Union
        {
            int aSize = sizeMap[aHead];//代表节点对应的集合大小
            int bSize = sizeMap[bHead];
            Node<T> *big = aSize>=bSize ? aHead : bHead;
            Node<T> *small = aSize>=bSize? bHead : aHead;
            //把小的集合挂在大的集合底下
            // 更新father和sizeMap
            parents[small] = big;
            sizeMap[big] = aSize+bSize;
            sizeMap.erase(small);
        }
    }
    
};

int main()
{
    vector<int> arr;
    arr.push_back(1);
    arr.push_back(2);
    arr.push_back(3);
    arr.push_back(4);
    arr.push_back(5);
    UnionFind<int> u(arr);
    u.Union(1,2);
    u.Union(2,3);
    cout<<u.isSameSet(3,1)<<endl;
    cout<<u.isSameSet(5,3)<<endl;
    return 0;
}