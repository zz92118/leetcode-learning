#include<string>
#include<iostream>
#include<vector>
using namespace std;

/*
主要是分支界限的处理

1-26分别转化成 A B ……Z

*/

class ConvertToLeterString
{
public:
    int convert_num(string s)
    {
        return process(s,0);
    }
    int convert_num_dp(string s);
    
    int process(string s,int index);
};

int ConvertToLeterString::convert_num_dp(string s)
{
    vector<int> dp;
    int index,i;
    int n=s.length();

    //改dp 一个可变参数----一维数组
    for(i=0;i<s.length()+1;i++)
    {
        dp.push_back(0);
    }
    //从index=N向前
    //dp依赖于后面的位置
    dp[n]=1;//递归终止条件N位置是1
    for(index=n-1;index>=0;index--)
    {
        if(s[index]=='0')
        {
            dp[index]=0;
        }

        if(s[index]=='1')
        {
            int result=dp[index+1];//
            if(index+1<n)
            {
                result+=dp[index+2];
            }
            dp[index]=result;
        }
        if(s[index]=='2')
        {
            int result=dp[index+1];
            if((index+1<n) && (s[index+1]-'0'>=0 && (s[index+1]-'0'<=6)))
            {
                result+=dp[index+2];
            }
            dp[index]=result;
        }
        int result=dp[index+1];
    }    
    return dp[0];

}


int ConvertToLeterString::process(string s,int index)
{
    if(index>=s.length())
    {
        return 1;
    }

    if(s[index]=='0')
    {
        //不合法的序列，直接return
        return 0;
    }

    if(s[index]=='1')
    {
        int result=process(s,index+1);
        if(index+1<s.length())
        {
            result+=process(s,index+2);
        }
        return result;//return语句
    }

    if(s[index]=='2')
    {
        int result=process(s,index+1);
        if((index+1<s.length()) && (s[index+1]-'0'>=6 && s[index+1]-'0'<=9))
        {
            result+=process(s,index+2);
        }
        return result;
    }

    int result = process(s,index+1);
    return result;
    //分支限界提前结束
}

int main()
{
    ConvertToLeterString c;
    cout<<c.convert_num("11111")<<endl;
    cout<<c.convert_num_dp("11111")<<endl;
    return 0;
}