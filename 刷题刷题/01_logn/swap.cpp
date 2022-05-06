#include<iostream>
using namespace std;

/*
只有一个数出现了基数次,其他都出现了偶数粗,找到这个出现基础次数的数字
*/

//便利 xor

int a[9]={1,1,2,3,2,2,3,4,4};

int main()
{
    int i;
    int eor=0;
    for(i=0;i<9;i++){
        eor = eor ^ a[i];
    }
    cout <<eor<<endl;
    

}