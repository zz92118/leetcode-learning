/*
 * @lc app=leetcode.cn id=37 lang=cpp
 *
 * [37] 解数独
 */

// @lc code=start
#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    void solveSudoku(vector<vector<char> >& board) {
        dfs(board,0,0);
    }

    bool dfs(vector<vector<char> >& board ,int i,int j)
    {
        int n=board.size();
        //终止条件
        //遍历下一行
        if(i==n)
        {
            return true;
        }
        else 
        {
            if(j==n)
            {
                return dfs(board,i+1,0);
            }


            if(board[i][j]!='.')
            {
                return dfs(board,i,j+1);
            }

            for(char x='1';x<='9';x++)
            {
                if(can_set(board,i,j,x))
                {
                    board[i][j]=x;
                    if(dfs(board,i,j+1))
                    {
                        return true;
                    }
                    board[i][j]='.';//回溯过程
                }
            }
            return false;
        }

    
    }
    bool can_set(vector<vector<char> >& board,int row,int column,char x)
    {
        int i;
        int j;
        for(i=0;i<9;i++)
        {
            if (board[row][i] == x) return false;
            if (board[i][column] == x) return false;
            if(board[(row/3)*3 + i/3][(column/3)*3 + i%3] == x)
            {
                return false;
            }

        }
        return true;
    }
};
// @lc code=end

