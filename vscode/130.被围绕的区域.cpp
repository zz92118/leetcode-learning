/*
 * @lc app=leetcode.cn id=130 lang=cpp
 *
 * [130] 被围绕的区域
 */

// @lc code=start
#include<vector>
#include<iostream>
using namespace std;

class Solution {
public:
    void solve(vector<vector<char> >& board) {
        vector<vector<bool> > visited;
        vector<bool> curr;
        int i,j;
        for(i=0;i<board[0].size();i++)
        {
            curr.push_back(false);
        }
        for(i=0;i<board.size();i++)
        {
            visited.push_back(curr);
        }

        for(i=0;i<board.size();i++)
        {
            dfs1(i,0,board,visited);
            dfs1(i,board[0].size()-1,board,visited);
        }
        for(j=0;j<board[0].size();j++)
        {
            dfs1(0,j,board,visited);
            dfs1(board.size()-1,j,board,visited);
        }
        //先把边上的 O干掉,
        for(i=1;i<board.size()-1;i++)
        {
            for(j=1;j<board[0].size()-1;j++)
            {
                if(board[i][j]=='O')
                {
                    dfs2(i,j,board,visited);
                }
            }
        }
    }
//O变成X
    void dfs2(int i,int j,vector<vector<char> >& board,vector<vector<bool> >& visited)
    {
        if(i<0 || j<0 || i>=board.size() || j>=board[0].size())
        {
            return ;
        }
        if(visited[i][j])
        {
            return ;
        }
        if(board[i][j]=='X')
        {
            return;
        }

        visited[i][j]=true;
        board[i][j]='X';

        dfs2(i-1,j,board,visited);
        dfs2(i+1,j,board,visited);
        dfs2(i,j-1,board,visited);
        dfs2(i,j+1,board,visited);
    }
//不淹没 直接dfs
    void dfs1(int i,int j,vector<vector<char> >& board,vector<vector<bool> >& visited)
    {
        if(i<0 || j<0 || i>=board.size() || j>=board[0].size())
        {
            return ;
        }
        if(visited[i][j])
        {
            return ;
        }
        if(board[i][j]=='X')
        {
            return;
        }

        visited[i][j]=true;

        dfs1(i-1,j,board,visited);
        dfs1(i+1,j,board,visited);
        dfs1(i,j-1,board,visited);
        dfs1(i,j+1,board,visited);
    }
};
// @lc code=end

