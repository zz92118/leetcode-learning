/*
 * @lc app=leetcode.cn id=200 lang=cpp
 *
 * [200] 岛屿数量
 */

// @lc code=start
#include<iostream>
#include<vector>
using namespace std;
/*
思路是淹没每个岛屿相邻的陆地,变成海水
也可以用visited判断重复 

*/
class Solution {
public:
    int numIslands(vector<vector<char> >& grid) {
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
                if(grid[i][j]=='1' && !visited[i][j])
                {   
                    res++;
                    dfs(i,j,grid,visited);
                }
            }
        }
        return res;
    }

    void dfs(int i,int j,vector<vector<char> >& grid,vector<vector<bool> >& visited)
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
        if(grid[i][j]=='0')
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
    vector<vector<char> > arr;

    vector<char> temp;
    temp.push_back('1');
    temp.push_back('1');
    temp.push_back('1');
    temp.push_back('1');
    temp.push_back('0');
    arr.push_back(temp);
    
    temp.clear();
    temp.push_back('1');
    temp.push_back('1');
    temp.push_back('0');
    temp.push_back('1');
    temp.push_back('0');
    arr.push_back(temp);

    temp.clear();
    temp.push_back('1');
    temp.push_back('1');
    temp.push_back('0');
    temp.push_back('0');
    temp.push_back('0');
    arr.push_back(temp);

    temp.clear();
    temp.push_back('0');
    temp.push_back('0');
    temp.push_back('0');
    temp.push_back('0');
    temp.push_back('0');
    arr.push_back(temp);

    cout<<s.numIslands(arr);
}

