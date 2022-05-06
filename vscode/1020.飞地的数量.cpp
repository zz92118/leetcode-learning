/*
 * @lc app=leetcode.cn id=1020 lang=cpp
 *
 * [1020] 飞地的数量
 */

// @lc code=start
#include<iostream>
#include<vector>
using namespace std;
/*

*/
//在边界上是没有办法计算的
//先把边界上的所有岛屿访问一遍,但不增加res

class Solution {
public:
    int numEnclaves(vector<vector<int> >& grid) {
        int i,j;
        int res=0;
        vector<vector<bool> > visited;
        vector<bool> curr;
        for(i=0;i<grid[0].size();i++)
        {
            curr.push_back(false);
        }
        for(i=0;i<grid.size();i++)
        {
            visited.push_back(curr);
        }

        for(i=0;i<grid.size();i++)
        {
            dfs(i,0,grid,visited);
            dfs(i,grid[0].size()-1,grid,visited);
        }
        for(j=0;j<grid[0].size();j++)
        {
            dfs(0,j,grid,visited);
            dfs(grid.size()-1,j,grid,visited);
        }
        
        for(i=0;i<grid.size();i++)
        {
            for(j=0;j<grid[0].size();j++)
            {
                if(grid[i][j]==1 && !visited[i][j])
                {   
                    res++;
                    // dfs(i,j,grid,visited);
                }
            }
        }
        return res;
    }

    void dfs(int i,int j,vector<vector<int> >& grid,vector<vector<bool> >& visited)
    {
        int m=grid.size();
        int n=grid[0].size();
        if(i>=m || j>=n ||i<0 ||j<0)
        {
            return ;
        }
        if(visited[i][j])
        {
            return ;
        }
        if(grid[i][j]==0)
        {
            return;
        }
        visited[i][j]=1;
        dfs(i,j-1,grid,visited);
        dfs(i,j+1,grid,visited);
        dfs(i-1,j,grid,visited);
        dfs(i+1,j,grid,visited);


    }
};
// @lc code=end

int main()
{
    Solution s;
    vector<vector<int> > arr;

    vector<int> temp;
    temp.push_back(0);
    temp.push_back(0);
    temp.push_back(0);
    temp.push_back(0);

    arr.push_back(temp);
    
    temp.clear();
    temp.push_back(1);
    temp.push_back(0);
    temp.push_back(1);
    temp.push_back(0);
    arr.push_back(temp);

    temp.clear();
    temp.push_back(0);
    temp.push_back(1);
    temp.push_back(1);
    temp.push_back(0);
    arr.push_back(temp);

    temp.clear();
    temp.push_back(0);
    temp.push_back(0);
    temp.push_back(0);
    temp.push_back(0);
    arr.push_back(temp);

    cout<<s.numEnclaves(arr);
}

