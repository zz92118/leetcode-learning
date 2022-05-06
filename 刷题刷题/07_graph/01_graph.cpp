#include<iostream>
#include<vector>
#include<unordered_map>
#include<unordered_set>
using namespace std;
/*
通用的图模版算法
*/
class Node
{
public:
    int value;//节点值
    int in;//入度
    int out;//出度
    vector<Node> nexts;//下一个节点
    vector<Edge> edges; //相邻的边

    Node(int val)
    {
        value=val;
        in=0;
        out=0;
        
    }
};
class Edge
{
public:
    int weight;//权重
    Node from;//原点
    Node to;//终点
};
class Graph
{
public:
    unordered_map<int,Node> nodes;//int :编号 Node:节点
    unordered_set<Edge> edgs;//边集

    Graph()
    {

    }
};