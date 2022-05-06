#include<iostream>
#include<vector>
#include<unordered_map>
#include<unordered_set>
#include<queue>
#include<stack>
using namespace std;
/*
图是有环的 不要死循环
队列

*/
//类声明
class Node;
class Edge;
class Grapg;

class Node
{
public:
    int value;//节点值
    int in;//入度
    int out;//出度
    vector<Node*> nexts;//下一个节点
    vector<Edge*> edges; //相邻的边

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
    Node* from;//原点
    Node* to;//终点

    Edge()
    {
        weight=1;
    }
};

class Graph
{
public:
    Node *head;

    unordered_map<int,Node*> nodes;//int :编号 Node:节点
    unordered_set<Edge*> edgs;//边集

    Graph();

    void bfs(Node *head);
    void dfs(Node *head);
};

Graph::Graph()
{
    Node *A = new Node(1);
    Node *B = new Node(2);
    Node *C = new Node(3);
    Node *D = new Node(100);
    Node *E = new Node(5);

    A->in=A->out=3;
    A->nexts.push_back(B);
    A->nexts.push_back(C);
    A->nexts.push_back(E);

    B->in=B->out=2;
    B->nexts.push_back(C);
    B->nexts.push_back(A);

    C->in=C->out=4;
    C->nexts.push_back(A);
    C->nexts.push_back(B);
    C->nexts.push_back(D);
    C->nexts.push_back(E);

    E->in=E->out=3;
    E->nexts.push_back(A);
    E->nexts.push_back(C);
    E->nexts.push_back(D);

    D->in=D->out=2;
    D->nexts.push_back(C);
    D->nexts.push_back(E);

    head=A;
}

void Graph::dfs(Node *head)
{
    stack<Node*> s;
    unordered_set<Node*> hash_set;

    if(head==nullptr)
    {
        return ;
    }

    s.push(head);
    hash_set.insert(head);
    cout<<head->value<<" ";
    while(!s.empty())
    {
        Node *curr=s.top();//栈顶按照深度优先的顺序入栈并操作
        s.pop();//最后依次弹出stack众的元素
        for(vector<Node*>::iterator i=curr->nexts.begin();i<curr->nexts.end();i++)
        {
            if(!hash_set.count(*i))
            {
                s.push(curr);
                s.push(*i);
                hash_set.insert(*i);
                cout<<(*i)->value<<" ";
                break;
            }
        }
    }



}


void Graph::bfs(Node *head)
{
    if(head==nullptr)
    {
        return ;
    }

    queue<Node*> q;
    unordered_set<Node*> hash_set;

    q.push(head);
    hash_set.insert(head);
    while(!q.empty())
    {
        Node *curr=q.front();
        q.pop();
        cout<<curr->value<<" ";
        //相邻的节点
        for(vector<Node*>::iterator i=curr->nexts.begin();i<curr->nexts.end();i++)//i是一个指向指针的指针
        {
            //判断重复
            if(!hash_set.count(*i))
            {
                hash_set.insert(*i);
                q.push(*i);
            }
        }
    }
    cout<<endl;
}




int main()
{
    Graph g;
    g.bfs(g.head);
    g.dfs(g.head);
    
}