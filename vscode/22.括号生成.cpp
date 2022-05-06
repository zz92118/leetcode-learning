/*
 * @lc app=leetcode.cn id=22 lang=cpp
 *
 * [22] 括号生成
 */

// @lc code=start
#include <iostream>
#include<string>
#include<vector>
using namespace std;
/*
选择列表 left righrt两个参数
路径 temp:当前的选择
种植条件 left <right 越界

*/

class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> result;
        string temp;

        dfs(result,0,0,n,temp);
        return result;

    }

    void dfs(vector<string> &result,int left_index,int right_index,int n,string &temp)
    {
        if(right_index>left_index || right_index>n || left_index>n)
        {
            return ;
        }
        else 
        {
            if(right_index==n && left_index==n)
            {
                result.push_back(temp);
            }

            else 
            {
                //两个可选的选择列表 左右
                temp.push_back('(');
                dfs(result,left_index+1,right_index,n,temp);
                temp.pop_back();

                temp.push_back(')');
                dfs(result,left_index,right_index+1,n,temp);
                temp.pop_back();
            }
        }
    }

};
// @lc code=end



int main()
{
    Solution s;
    s.generateParenthesis(3);
}

