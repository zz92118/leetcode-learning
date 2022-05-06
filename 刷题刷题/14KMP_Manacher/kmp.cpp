#include<iostream>
#include<string>
#include<vector>

/*
next[]数组：记录前缀后缀的长度
*/
using namespace std;

class KMP
{
public:
    int getindexof(string str1,string str2);
    vector<int> getnextArray(string str2);
};

int KMP::getindexof(string str1,string str2)
{
    if(str1.size()==0 || str2.size()==0 || str1.size()<=str2.size())
    {
        return -1;
    }
    int i1=0;
    int i2=0;

    vector<int> next=getnextArray(str2);

    while(i1<str1.length() && i2<str2.length())
    {
        if(str1[i1]==str2[i2])
        {
            i1++;
            i2++;
        }
        // str2无法往前跳了
        else if(next[i2]==-1)
        {
            i1++;
        }
        //next数组：对应str2往前跳
        else 
        {
            i2=next[i2];
        }
    }
    if(i2==str2.length())
    {
        return i1-i2;
    }
    return i1==str1.length() ? -1 : i1-i2;

}

vector<int> KMP::getnextArray(string str2)
{
    vector<int> next(str2.length());
    if(str2.length()==0)
    {
        next[0]=-1;
        return next;
    }
    //人为规定next[0]和next[1]
    next[0]=-1;
    next[1]=0;

    int i=2;//next数组的位置
    int cn=0;
    //用cn的位置和i-1的位置比
    //也代表i-1位置的信息是多少next[i-1]
    while(i<next.size())
    {
        if(str2[i-1]==str2[cn])
        {
            next[i]=cn+1;
            i++;
            cn++;
            //被下一部分的i利用，cn和i都++
        }
        //cn往前跳
        else if(cn>0)
        {
            cn=next[cn];
        }
        else
        {
            next[i]=0;
            i++;
        }
    }

    return next;
    
}



int main()
{
    KMP k;
    cout<<k.getindexof("hello","ll");
    return 0;
}