#include<iostream>
using namespace std;

/*
1.只有一个数出现了基数次,其他都出现了偶数粗,找到这个出现基础次数的数字
*/

/*
2.只有个数出现了基数次,其他都出现了偶数粗,找到这个出现基础次数的数字
*/

//便利 xor

int test1();
int test2();


int main()
{
    // 抑或的操作
    // 1. 0^n =n n^n=0
    //2.交换律 结合律
    //3. 随便换
    
    int x=10;
    int y=20;
    int a=x;
    int b=y;

    a=a^b;
    b=a^b;
    a=a^b;
    cout<<a<<endl<<b<<endl;
    test1();
    test2();

    return 0;
}

int test1()
{
    int a[9]={1,1,2,3,2,2,3,4,4};
    int i;
    int eor=0;
    for(i=0;i<9;i++){
        eor = eor ^ a[i];
    }
    //eor = 要找的数
    cout <<"只有一个数出现了奇数次: "<<eor<<endl;
    
}

int test2()
{
    int a[14]={1,1,2,3,2,2,3,4,4,4,5,5,6,6};
    int i;
    int eor=0;
    for (i=0;i<14;i++)
    {
        eor = eor ^ a[i];
    }
    //此时eor=a^b;
    cout<<eor<<endl;

    int eor_=0;

    int right_only_one= eor &(~eor+1); //提取出最右侧1的eor
    cout<<right_only_one<<endl;
    for(i=0;i<14;i++)
    {
        if((right_only_one & a[i]) != 0) //最右侧1这一位为1 括号
        {
            eor_=eor_^a[i];
        }
    }

    cout <<"只有两个数出现了奇数次: "<<"a:  "<<eor_<<"    b:  "<<(eor^eor_)<<endl;

}