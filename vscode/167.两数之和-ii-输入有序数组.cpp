/*
 * @lc app=leetcode.cn id=167 lang=cpp
 *
 * [167] 两数之和 II - 输入有序数组
 */

// @lc code=start
#include<vector>
using namespace std;
/*
双指针技巧
slow fast 
*/
class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int left=0;
        int right=numbers.size()-1;
        while(left<right)//同一个数字不能用两次 left！=right
        {
            int sum=numbers[left]+numbers[right];
            if(sum==target)
            {
                break;
            }
            else if(sum<target)
            {
                left+=1;
            }
            else if(sum>target)
            {
                right-=1;
            }
        }

        vector<int> result;
        result.push_back(left+1);
        result.push_back(right+1);

        return result;
        
    }
};
// @lc code=end

