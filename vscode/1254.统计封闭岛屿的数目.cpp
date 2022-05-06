/*
 * @lc app=leetcode.cn id=1254 lang=cpp
 *
 * [1254] 统计封闭岛屿的数目
 */

// @lc code=start

#include<iostream>
#include<vector>
using namespace std;
/*
思路是淹没每个岛屿相邻的陆地,变成海水
也可以用visited判断重复 

*/
//在边界上是没有办法计算的
//先把边界上的所有岛屿访问一遍,但不增加res

class Solution {
public:
    int closedIsland(vector<vector<int> >& grid) {
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
        //边上的给它淹掉
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
                if(grid[i][j]==0 && !visited[i][j])
                {   
                    res++;
                    dfs(i,j,grid,visited);
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
        if(grid[i][j]==1)
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

