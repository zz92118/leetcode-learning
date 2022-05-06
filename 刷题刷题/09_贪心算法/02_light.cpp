#include<iostream>
#include<string>
using namespace std;

// 2021-03-18：给定一个字符串str，只由‘X’和‘.’两种字符构成。
// ‘X’表示墙，不能放灯，也不需要点亮，‘.’表示居民点，可以放灯，需要点亮。
// 如果灯放在i位置，可以让i-1，i和i+1三个位置被点亮。
// 返回如果点亮str中所有需要点亮的位置，至少需要几盏灯。

class Solution
{
public:
    int light_arrange(string s)
    {
        int num=0;
        int i=0;
        while(i<s.length())
        {
            if(s[i]=='X')
            {
                i++;
            }
            //一定 会放灯
            else 
            {
                if(i+1<s.length())
                {
                    if(s[i+1]=='X')
                    {
                        num+=1;//i放一个灯
                        i+=2;//i+2做决定
                    }

                    else
                    {
                        // i+1放一个灯
                        num+=1;
                        i+=3;//i+3做决定
                    }
                }
                else if(i+1==s.length())
                {
                    num++;
                    i++;
                }
            
            }
        }
        return num;
    }
};

int main()
{
    string str=".X..XX.......";
    Solution s;
    cout<<s.light_arrange(str);
}
