/*
 * @lc app=leetcode.cn id=9 lang=cpp
 *
 * [9] 回文数
 */

// @lc code=start
#include<iostream>
using namespace std;
class Solution {
public:
    bool isPalindrome(int x) {
        if(x<0)
        {
            return false;
        }
        if(x>=0 && x<10)
        {
            return true;
        }

        int div=1;
        while(x/div>0)
        {
            div*=10;
        }
        div/=10;
        while(x>0)
        {
            int left=x/div;
            int right=x%10;
            if(left!=right && left!=0)
            {
                return false;
            }
            //只有一位数字了
            if(left==0)
            {

            }
            //先去掉首位，再去掉末位
            x=x%div;
            x=x/10;

            x=x+1;

            x=x/div;
        }
        return true;
    }
};
// @lc code=end
int main()
{
    Solution s;
    cout<<s.isPalindrome(1000021);
}
