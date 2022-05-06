/*
 * @lc app=leetcode.cn id=69 lang=cpp
 *
 * [69] Sqrt(x)
 */

// @lc code=start
#include<iostream>
using namespace std;
/*
向下取整的sqrt（x）实现 
利用二分查找实现
if( x / mid > mid && x/mid+1 < mid+1) 判断
如 sqrt（8） 大于2 小于 3 
       
利用均值不等式 定义右边界  int right = x/2 + 1;//右边界 
*/

class Solution {
public:
    int mySqrt(int x) {
        if(x == 0)
        {
            return 0;
        } 

        int left = 1;
        int right = x/2 + 1;//右边界 
        int res = left ;

        while(left <= right)
        {
            int mid = left + (right-left)/2;

            if( x / mid >= mid && x/ (mid+1) < mid+1)
            {
                res = mid ;
                break;
            }

            else if(x / mid > mid)
            {
                left = mid + 1;
            }

            else if( x / mid < mid)
            {
                right = mid - 1;
            }

        }
        return res;

    }
};
// @lc code=end

