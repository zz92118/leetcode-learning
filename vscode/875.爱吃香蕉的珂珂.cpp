/*
 * @lc app=leetcode.cn id=875 lang=cpp
 *
 * [875] 爱吃香蕉的珂珂
 */

// @lc code=start
#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
using namespace std;

/*
 x ----> f（x）的映射
 x:代表当前吃香蕉的速度
 fx:代表对应的时间，是一个单调递减（非增函数）
 targe:给出的h
 target 和 fx都代表时间，是同一个物理量
*/

class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        //二分搜索的左右边界
        int left_speed=1;
        int right_speed=pow(10,9);

        //寻找左侧边界的问题
        while(left_speed<=right_speed)
        {
            int mid = (left_speed+right_speed)/2;

            if(f(piles,mid)==h)
            {
                //减小速度
                right_speed=mid-1;
            }

            else if(f(piles,mid)>h)
            {
                //加大速度
                left_speed=mid+1;
            }
            

            else if(f(piles,mid)<h)
            {
                //减小速度
                right_speed=mid-1;
            }

        }
        // if(left_speed<1 || f(piles,left_speed) != h)
        // {
        //     return -1;
        // }
        return left_speed;
    }
    
    int f(vector<int>& piles,int x)//计算速度x吃香蕉需要的时间
    {
        int i;
        int hours=0;
        for(i=0;i<piles.size();i++)
        {
            hours+=piles[i]/x;

            if(piles[i] % x != 0 )
            {
                hours++;
            }           

        }
        return hours;
    }
};
// @lc code=end

int main()
{
    Solution s;
    vector<int> arr;

    arr.push_back(30);
    arr.push_back(11);
    arr.push_back(23);
    arr.push_back(4);
    arr.push_back(20);

    cout<<s.f(arr,30)<<endl;

}

