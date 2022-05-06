// 输入： 参数1，正数数组costs 参数2，正数数组profits 参数3，正数k 参数4，正数m

// costs[i]表示i号项目的花费
// profits[i]表示i号项目在扣除花费之后还能挣到的钱(利润)
// k表示你不能并行、只能串行的最多做k个项目
// m表示你初始的资金

#include<iostream>
#include<queue>
#include<vector>
using namespace std;

class Project
{
public:
    int cost;
    int profit;
    Project(int c,int p)
    {
        cost=c;
        profit=p;
    }

};

//比较器
class MinCostCompare
{
public:
    bool operator ()(const Project* n1,const Project* n2) const
    {
        return n1->cost > n2->cost;
    }
};
class MaxProfitsCompare
{
public:
    bool operator ()(const Project* n1,const Project* n2)const{
        return n1->profit < n2->profit;
    }
}; 


class Soulution
{
public:
    int findMaxCapital(vector<int> costs,vector<int> profits,int k,int w)
    {
        //1.准备工作
        int i;
        vector<Project*> p;
        for(i=0;i<costs.size();i++)
        {
            Project *temp = new Project(costs[i],profits[i]);
            p.push_back(temp);
        }
        priority_queue<Project*,vector<Project*>,MinCostCompare> costheap;
        priority_queue<Project*,vector<Project*>,MaxProfitsCompare> profitheap;
        //2.准备小根堆
        for(i=0;i<p.size();i++)
        {
            costheap.push(p[i]);
        }

        for(i=0;i<k;i++)
        {
            //从小根堆的堆顶pop出项目加入大根堆
            while(!costheap.empty() && costheap.top()->cost < w)
            {
                Project *curr=costheap.top();
                costheap.pop();
                profitheap.push(curr);
            }
            //没有项目可以做的时候提前return
            if(profitheap.empty())
            {
                return w;
            }

            w+=profitheap.top()->profit;
            profitheap.pop();
        }
        return w;
    }

};


int main()
{
    vector<int> costs ;
    vector<int> profits;
    costs.push_back(10);
    costs.push_back(20);
    costs.push_back(30);
    costs.push_back(40);
    costs.push_back(50);

    profits.push_back(20);
    profits.push_back(60);
    profits.push_back(80);
    profits.push_back(70);
    profits.push_back(90);

    Soulution s;
    cout<<s.findMaxCapital(costs,profits,4,40);

}