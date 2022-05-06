#include<iostream>
#include<algorithm>
using namespace std;


//中点 l+(r-l)/2=l+(r-l)>>1

/*
·    master公式（也称主方法）是用来利用分治策略来解决问题经常使用的时间复杂度的分析方法，（补充：分治策略的递归解法还有两个常用的方法叫做代入法和递归树法，以后有机会和亲们再唠），众所周知，分治策略中使用递归来求解问题分为三步走，分别为分解、解决和合并，所以主方法的表现形式：

T [n] = aT[n/b] + f (n)（直接记为T [n] = aT[n/b] + O (N^d)）

其中 a >= 1 and b > 1 是常量，其表示的意义是n表示问题的规模，
a表示递归的次数也就是生成的子问题数，
b表示每次递归是原来的1/b之一个规模，(数据量大小) 子问题规模是否一样
f（n）表示分解和合并所要花费的时间之和。 一般是决策过程

!!!!!!!!!!!求解子问题规模等规模的递归

解法：
①当d<logb a时，时间复杂度为O(n^(logb a))
②当d=logb a时，时间复杂度为O((n^d)*logn)
③当d>logb a时，时间复杂度为O(n^d)
————————————————
版权声明：本文为CSDN博主「风一样的美代码」的原创文章，遵循CC 4.0 BY-SA版权协议，转载请附上原文出处链接及本声明。
原文链接：https://blog.csdn.net/qq_32595453/article/details/79516787
*/
int test1();
int find_max(int a[],int low,int high);

int main()
{
    test1();
}

int test1()
{
    int a[10]={3,6,7,8,10,22,90,33,111,13};
    int low = 0;
    int high = 9;
    int result;
    result = find_max(a,low,high);
    cout<<"max:"<<result<<endl;
    return 0;
}

int find_max(int a[],int low,int high)
{
    int mid;
    int leftmax;
    int rightmax;
    mid = low + (high-low)/2;

    if(low==high)
    {
        //递归终止条件
        return a[low];
    }
    leftmax=find_max(a,low,mid);
    rightmax=find_max(a,mid+1,high);
    return max(leftmax,rightmax);

}