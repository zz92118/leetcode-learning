#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class backpack
{
public:
    int maxvalue(vector<int> w,vector<int> v,int maxweight);
    int maxvalue_dp(vector<int> w,vector<int> v,int maxweight);
    int process(vector<int> w,vector<int> v,int index,int rest);
};


int backpack::maxvalue_dp(vector<int> w,vector<int> v,int maxweight)
{
    if(w.size()!=v.size())
    {
        return 0;
    }
    vector<vector<int> >dp;
    int i;
    int index,rest;
    vector<int> row;
    for(i=0;i<maxweight+1;i++)
    {
        row.push_back(0);
    }
    for(i=0;i<w.size()+1;i++)
    {
        dp.push_back(row);
    }

    for(index=w.size()-1;index>=0;index--)
    {
        //初始条件：dp[N]行为0 因为index只能取0-N-1
        for(rest=0;rest<=maxweight;rest++)
        {
            int price1=dp[index+1][rest];
            int price2=0;
            if(rest - w[index] > 0)//小于0的保护
            { 
                price2=v[index]+dp[index+1][rest-w[index]];
            }
            dp[index][rest]=max(price1,price2);
        }
    }
    return dp[0][maxweight];
}



int backpack::maxvalue(vector<int> w,vector<int> v,int maxweight)
{   
    if(w.size()!=v.size())
    {
        return 0;
    }
    return process(w,v,0,maxweight);
}

int backpack::process(vector<int> w,vector<int> v,int index,int rest)
{
    //没有空间了

    if(rest<0)
    {
        return -1;//不能得到可行解了
    }
    else 
    {
        //没有货了
        if(index>=w.size())
        {
            return 0;
        }

        else 
        {
            //index位置不取
            int price1=process(w,v,index+1,rest);//不加货物
            int price2=process(w,v,index+1,rest-w[index]);//加了货物的剩余价值
            if(price2>-1)//如果取能得到一个可行解
            {
                price2+=v[index];//剩下来的货的价值加上当前的价值
            }

            return max(price1,price2);//最大决策过程
        }
    }
}



int main()
{
    vector<int> weights;
    vector<int> values;

    weights.push_back(3);//1.6
    weights.push_back(2);//3
    weights.push_back(4);//0
    weights.push_back(7);//2.
    // weights.push_back(3);//4
    // weights.push_back(1);//4
    // weights.push_back(7);//0

    values.push_back(5);
    values.push_back(6);
    values.push_back(3);
    values.push_back(19);
    // values.push_back(12);
    // values.push_back(4);
    // values.push_back(2);

    int bag=11;

    backpack b;
    cout<<b.maxvalue(weights,values,bag)<<endl;
    cout<<b.maxvalue_dp(weights,values,bag)<<endl;
    return 0;
}

