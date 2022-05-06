#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    int movingCount(int m, int n, int k) ;
    int bitsum(int i,int j);
    int dfs(int indexi,int indexj,int m,int n,int k,vector<vector<bool> > &visited);
};

int Solution::dfs(int indexi,int indexj,int m,int n,int k,vector<vector<bool> > &visited)
{
    if(indexi>=m || indexj>=n || bitsum(indexi,indexj)>k || visited[indexi][indexj])//终止条件
    {
        return 0;
    }
    else 
    {
        visited[indexi][indexj]=true;
        return 1+dfs(indexi+1,indexj,m,n,k,visited)+dfs(indexi,indexj+1,m,n,k,visited);
    }
}


int Solution::movingCount(int m, int n, int k) 
{
    vector<vector <bool> > visited;
    vector<bool> curr; 
    int i,j;
    for(i=0;i<n;i++)
    {
        curr.push_back(false);
    }
    for(i=0;i<m;i++)
    {
        visited.push_back(curr);
    }
    int r = dfs(0,0,m,n,k,visited);
    return r;
}

int Solution::bitsum(int i,int j)
{
    int sum=0;
    while(i>0)
    {
        sum+=i%10;
        i/=10;
    }

    while(j>0)
    {
        sum+=j%10;
        j/=10;
    }
    return sum;
}

int main()
{
    Solution s;
    cout<<s.bitsum(9,10)<<endl;
    cout<<s.movingCount(38,15,9);
}


