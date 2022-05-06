// 题目 一块金条切成两半，是需要花费和长度数值一样的铜板的。
// 比如长度为20的 金条，不管切成长度多大的两半，都要花费20个铜板。
// 一群人想整分整块金条，怎么分最省铜板？ 
// 例如,给定数组{10,20,30}，代表一共三个人，整块金条长度为 10+20+30=60. 
// 金条要分成10,20,30三个部分。 
// 如果， 
// 先把长度60的金条分成10和50，花费60再把长度50的金条分成20和30，花费50 一共花费110铜板。 
// 但是如果， 先把长度60的金条分成30和30，花费60再把长度30金条分成10和20，花费30一共花费90铜板。 
// 输入一个数组，返回分割的最小代价。
#include<iostream>
#include<queue>
#include<vector>
using namespace std;

/*
取出小根堆堆顶的两个元素

*/

class Solution
{
public:
    int less_money_split_gold(vector<int> a)
    {
        priority_queue <int,vector<int>,greater<int> >q;// 小根堆
        // priority_queue <int,vector<int>,less<int> >q;//大根堆
        for(vector<int>::iterator i=a.begin();i<a.end();i++)
        {
            q.push(*i);
        }
        int total_sum=0;
        while(q.size()>=2)
        {
            int x1=q.top();
            q.pop();
            int x2=q.top();
            q.pop();

            int curr=x1+x2;
            total_sum+=curr;
            q.push(curr);
        }
        return total_sum;
    }
};

int main()
{
    Solution s;
    vector<int> a;
    a.push_back(10);
    a.push_back(20);
    a.push_back(30);
    cout<<s.less_money_split_gold(a)<<endl;
    return 0;
}
