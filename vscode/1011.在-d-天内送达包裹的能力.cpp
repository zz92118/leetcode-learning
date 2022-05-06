/*
 * @lc app=leetcode.cn id=1011 lang=cpp
 *
 * [1011] 在 D 天内送达包裹的能力
 */

// @lc code=start
#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
using namespace std;

/*
target:days
fx:求出当前运载能力下的day
x:运载能力 取值范围【left，right】

*/

class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) {
        if(weights.size()==0)
        {
            return 0;
        }

        int left = 0;
        int right = 0;
        for (vector<int>::iterator w=weights.begin();w<weights.end();w++) {
            left = max(left, *w);
            right += *w;
        }
        //确定左右区间

        while(left<=right)
        {
            int mid = left + (right-left) / 2;

            if(f(weights,mid) == days)
            {
                //减小
                right=mid-1;
            }

            else if(f(weights,mid) < days )
            {
                //减小
                right=mid-1;
            }

            else if (f(weights,mid) > days)
            {
                //加大
                left=mid+1;
            } 
        }
        return left;
    }
    
    int f(vector<int>& weights, int x) // x: 当前的运载能力 返回需要的天数
    {
        int i;
        int days=0;
        int curr = 0;
        for(i=0;i<weights.size();)
        {
            //自己不用写保护
            int cap=x;//当天可以装的剩余数量
            while(i<weights.size())
            {
                if(cap<weights[i])
                {
                    break;//表示这一天已经装满了
                }
                else 
                {
                    cap-=weights[i];
                }
                i++;
            }
            days++;
        }
        return days;
    }
};
// @lc code=en

int main()
{
    vector<int> arr;
    arr.push_back(1);
    arr.push_back(2);
    arr.push_back(3);
    arr.push_back(4);
    arr.push_back(5);
    arr.push_back(6);
    arr.push_back(7);
    arr.push_back(8);
    arr.push_back(9);
    arr.push_back(10);

    // arr.push_back(1);
    // arr.push_back(2);
    // arr.push_back(3);
    // arr.push_back(1);
    // arr.push_back(1);
    // arr.push_back(6);
    // arr.push_back(7);
    // arr.push_back(8);
    // arr.push_back(9);
    // arr.push_back(10);


    Solution s;
    cout<<s.f(arr,15)<<endl;
    cout<<s.shipWithinDays(arr,5);
}
