/*
 * @lc app=leetcode.cn id=990 lang=cpp
 *
 * [990] 等式方程的可满足性
 */

// @lc code=start

#include<iostream>
#include<unordered_map>
#include<stack>
#include<vector>
#include<string>
using namespace std;
// 模版编程

template <class V> class Node
{
public:
    V v;
    Node (V value)
    {
        v=value;
    }
};

template <class V> class Union
{
public:
    unordered_map<V,Node<V>*> nodes;//转化为nodes结构
    unordered_map< Node<V>* , Node<V>* > parents;//直接父节点
    unordered_map< Node<V>* , int> sizemap;//代表节点的集合大小

    Union(vector<V> arr);//初始化
    bool connected(V a,V b);//向上找到的代表节点
    Node<V>* get_grandfather(Node<V>* curr); //扁平化压缩优化
    void union_(V a,V b);
};

template <class V>  Union<V>::Union(vector<V> arr)
{
    int i;
    for(i=0;i<arr.size();i++)
    {
        Node<V> *temp=new Node<V>(arr[i]);
        nodes[arr[i]]=temp;
        parents[temp]=temp;
        sizemap[temp]=1;
    }
    
}

template <class V> bool Union<V>::connected(V a,V b)
{
    if(!nodes.count(a) || !nodes.count(b))
    {
        return false;
    }

    return get_grandfather(nodes[a])==get_grandfather(nodes[b]);
}

template <class V> Node<V>* Union<V>::get_grandfather(Node<V> * curr)
{
    stack<Node<V>* > s;
    //一直向上 直到找到根节点
    while(curr!=parents[curr])
    {
        s.push(curr);
        curr=parents[curr];
    }
    while(!s.empty())
    {
        parents[s.top()]=curr;
        s.pop();
    }

    return curr;
}

template <class V> void Union<V>::union_(V a,V b)
{
    Node<V> *aHead=get_grandfather(nodes[a]);
    Node<V> *bHead=get_grandfather(nodes[b]);

    if(!connected(a,b))
    {
        int asize=sizemap[aHead];
        int bsize=sizemap[bHead];

        Node<V> * bignode= asize >= bsize ? aHead : bHead;
        Node<V> * smallnode= asize < bsize ? aHead : bHead;
        //小挂大 size调整 
        parents[smallnode]=bignode;
        sizemap[bignode]=asize+bsize;
        sizemap.erase(smallnode);
    }
}

/*
连通性:
将所有==的字符联通
!=的字符检测是不是在同一个集合中
*/

class Solution {
public:
    bool equationsPossible(vector<string>& equations) {
        vector<char> arr;
        int i;
        for(i=0;i<26;i++)
        {
            arr.push_back('a'+i);
        }
        //类型为char的Union结构
        Union<char> u(arr);
        for(i=0;i<equations.size();i++)
        {
            if(equations[i][1]=='=')
            {
                u.union_(equations[i][0],equations[i][3]);
            }
        }
        for(i=0;i<equations.size();i++)
        {
            if(equations[i][1]=='!')
            {
                if(u.connected(equations[i][0],equations[i][3]))
                {
                    return false;
                }
            }
        }
        return true;
    }
};
// @lc code=end
int main()
{
    Solution s;
    vector<string> arr;
    arr.push_back("a==b");
    arr.push_back("b==a");
    cout<<s.equationsPossible(arr);
    return 0;

}
