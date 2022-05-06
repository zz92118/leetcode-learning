#include<iostream>
#include<stack>
#include<vector>

using namespace std;


class MonotousStack
{
public:
    vector<int> nextGreaterElement(vector<int>& nums) {
        vector<int> res(nums.size()); // 存放答案的数组
        stack<int> s;
        // 倒着往栈里放
        for (int i = nums.size() - 1; i >= 0; i--) {
            // 判定个子高矮
            while (!s.empty() && s.top() <= nums[i]) {
                // 矮个起开，反正也被挡着了。。。
                s.pop();
            }
            // nums[i] 身后的 next great number
            res[i] = s.empty() ? -1 : s.top();
            s.push(nums[i]);
        }
        return res;
    }
};


int main()
{
    vector<int> arr;
    arr.push_back(2);
    arr.push_back(1);
    arr.push_back(2);
    arr.push_back(4);
    arr.push_back(3);

    MonotousStack s;
    s.nextGreaterElement(arr);
}