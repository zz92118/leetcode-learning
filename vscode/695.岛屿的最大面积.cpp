/*
 * @lc app=leetcode.cn id=695 lang=cpp
 *
 * [695] 岛屿的最大面积
 */

// @lc code=start
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
/*
int 的dfs return的时候 
return 1+四种可能的情况
*/


class Solution {
public:
    int maxAreaOfIsland(vector<vector<int> >& grid) {
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
            for(j=0;j<grid[0].size();j++)
            {
                if(grid[i][j]==1 && !visited[i][j])
                {   
                    res=max(res,dfs(i,j,grid,visited));
                }
            }
        }
        return res;
    }

    int dfs(int i,int j,vector<vector<int> >& grid,vector<vector<bool> >& visited)
    {
        int m=grid.size();
        int n=grid[0].size();
        if(i>=m || j>=n ||i<0 ||j<0)
        {
            return 0;
        }
        if(visited[i][j])
        {
            return 0;
        }
        if(grid[i][j]==0)
        {
            return 0;
        }
        visited[i][j]=1;
        return 1+dfs(i,j-1,grid,visited)+dfs(i,j+1,grid,visited)+dfs(i-1,j,grid,visited)+dfs(i+1,j,grid,visited);
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

    cout<<s.maxAreaOfIsland(arr);
}


