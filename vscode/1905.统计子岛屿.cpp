/*
 * @lc app=leetcode.cn id=1905 lang=cpp
 *
 * [1905] 统计子岛屿
 */

// @lc code=start
#include<iostream>
#include<vector>
using namespace std;
/*
如果2是岛屿但是1不是的话直接淹没
然后再对岛屿2dfs就行了
当岛屿 B 中所有陆地在岛屿 A 中也是陆地的时候，岛屿 B 是岛屿 A 的子岛。

反过来说，如果岛屿 B 中存在一片陆地，在岛屿 A 的对应位置是海水，那么岛屿 B 就不是岛屿 A 的子岛。

那么，我们只要遍历 grid2 中的所有岛屿，把那些不可能是子岛的岛屿排除掉，剩下的就是子岛。

*/
class Solution {
public:
    int countSubIslands(vector<vector<int> >& grid1, vector<vector<int> >& grid2) {
        int i,j;
        int res=0;
        vector<vector<bool> > visited;
        vector<bool> curr;
        for(i=0;i<grid1[0].size();i++)
        {
            curr.push_back(false);
        }
        for(i=0;i<grid1.size();i++)
        {
            visited.push_back(curr);
        }

        for(i=0;i<grid1.size();i++)
        {
            for(j=0;j<grid1[0].size();j++)
            {
                if(grid2[i][j]==1 &&grid1[i][j]==0 && !visited[i][j])
                {   
                    dfs(i,j,grid2,visited);
                }
            }
        }

        for(i=0;i<grid1.size();i++)
        {
            for(j=0;j<grid1[0].size();j++)
            {
                if(grid2[i][j]==1 && !visited[i][j])
                {   
                    res++;
                    dfs(i,j,grid2,visited);
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

