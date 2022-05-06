/*
 * @lc app=leetcode.cn id=547 lang=cpp
 *
 * [547] 省份数量
 */

// @lc code=start
#include<iostream>
#include<unordered_map>
#include<stack>
#include<vector>
#include<string>
using namespace std;
/*
DFS：visited数组是1纬的 
Union解法 先便利一遍,把所有的city联通起来,直接输出联通集合的个数(代表节点的大小)
*/

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


class Solution {
public:
    int findCircleNum(vector<vector<int> >& isConnected) {
        int res=0;
        vector<int> arr;
        int i,j;
        for(i=0;i<isConnected.size();i++)
        {
            arr.push_back(i);
        }
        Union<int> u(arr);
        
        for(i=0;i<isConnected.size();i++)
        {
            for(j=0;j<isConnected.size();j++)
            {
                if(isConnected[i][j])
                {
                    u.union_(i,j);
                }
            }
        }
        //转化为有几个联通的子集
        res = u.sizemap.size();
        return res;
    }
};


// @lc code=end
int main()
{
    vector<vector<int> >arr;
    vector<int> curr;

    curr.push_back(1);
    curr.push_back(0);
    curr.push_back(0);
    curr.push_back(1);
    arr.push_back(curr);
    curr.clear();

    curr.push_back(0);
    curr.push_back(1);
    curr.push_back(1);
    curr.push_back(0);
    arr.push_back(curr);
    curr.clear();

    curr.push_back(0);
    curr.push_back(1);
    curr.push_back(1);
    curr.push_back(1);
    arr.push_back(curr);
    curr.clear();

    curr.push_back(1);
    curr.push_back(0);
    curr.push_back(1);
    curr.push_back(1);
    arr.push_back(curr);
    curr.clear();

    Solution s;
    cout<<s.findCircleNum(arr)<<endl;
}



class Solution {
public:
    int res=0;

    int findCircleNum(vector<vector<int> >& isConnected) {
        int n=isConnected.size();
        vector<bool> visited; 
        int i;
        for(i=0;i<n;i++)
        {
            visited.push_back(false);
        }
        for(i=0;i<n;i++)
        {
            if(!visited[i])
            {
                res++;
                dfs(i,isConnected,visited);//联通的城市一起进行访问
            }
        }
        return res;
    }

    void dfs(int i,vector<vector<int> >& isConnected,vector<bool> &visited)
    {
        //访问当前城市
        visited[i]=true;
        //继续访问联通的城市
        int j;
        for(j=0;j<visited.size();j++)
        {
            if(isConnected[i][j] && visited[j]==false)
            {
                dfs(j,isConnected,visited);
            }
        }

    }
};