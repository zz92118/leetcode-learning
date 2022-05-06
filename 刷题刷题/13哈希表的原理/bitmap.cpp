#include<iostream>
using namespace std;


int main()
{
    int a[10]; //10*4*8=320位的信息
    int index=178;
    int NumIndex=index/32;//在那个数上找
    int BitIndex=index%32;//具体的Bit位

    // 获取index的状态
    int s = ((a[NumIndex]>>(BitIndex)) & 1);

    //index位置状态改成1
    a[NumIndex] = a[NumIndex] | (1<<BitIndex);
    //index位置状态改成0
    a[NumIndex] = a[NumIndex] & (~(1<<BitIndex)) ;


}