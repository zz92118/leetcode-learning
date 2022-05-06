#include<iostream>
using namespace std;

int test1();//二分法找某个数字是否存在
int test2();//一个有序数组 找到大于等于某个数字最左侧的数字 小于等于某个数字的最右侧的数字(可能出现重复　) 二分最后return t!
int test3();
//局部最小值问题 无序的一个数组,任何两个相邻的数字不想等 
//定义:局部最小 对于位置i(如果i不是0或者n-1),则a[i]<a[i-1] && a[i]<a[i+1] a[0]<a[1], a[n]<a[n-1];
//在这样的数组中找到一个局部最小 复杂度小于o(n)

/*
数据状况:
标准:
*/
int binary(int a[],int low,int high,int k);
int binary2(int a[],int low,int high,int k,int t);
int binary3(int a[],int low,int high);



int main()
{
    test3();
}

int test1()
{
    int a[10]={1,2,3,4,5,6,7,9,10,11};
    int i;
    int low=0;
    int high=9;
    int k=100;
    int index=binary(a,low,high,k);
    if(index>=0)
    {
        cout<<"index:"<<index<<"    key:"<<a[index]<<endl;
    }
    else
    {
        cout<<"not found";
    }
}

int test2()
{
    int a[15]={1,2,2,3,3,3,3,3,3,4,4,5,5,5,5};
    int i;
    int low=0;
    int high=14;
    int k=2;
    if(k>=a[14] || k<=a[0])
    {
        cout<<"cant found such number"<<endl;
        return 0;
    }
    else 
    {
        int t;//核心是一个变量t 记录下最接近的位置
        t=high;//先记录下t为最大
        int index;
        index = binary2(a,low,high,k,t); 
        //index : 11
        cout<<"index:"<<index<<endl;
        return 0;
    }

}

int test3()
{
    int a[10]={9,5,4,7,15,12,3,5,8,10}; //4,2,3是局部最小 你只需要找到一个局部最小就可以了
    int i;
    int low,high;
    low =0 ;
    high=9;
    //先判断边界条件
    if(a[0]<a[1] || a[10]<a[9])
    {
        //局部最小再数组末端
        return 0;
    }
    else 
    {
        int index=binary3(a,0,9);
        cout<<"index:"<<index<<"    value:"<<(a[index])<<endl;

    }

}

int binary3(int a[],int low,int high)
{
    int mid;
    mid =(low+high)/2;
    if (low<high)
    {
        if((a[mid]<a[mid-1] && a[mid]<a[mid+1]))
        {
            return mid;
        }
        //判断趋势 左右导数不一样  只需要找到一个
        else if(a[mid]>a[mid-1])
        {
            return binary3(a,low,mid-1);
        }
        else 
        {
            return binary3(a,mid+1,high);
        }
    }

}


int binary2(int a[],int low,int high,int k,int t)
{
    int mid;
    mid = (low+high)/2;
    if(low<high)
    {
        if(a[mid]<k)
        {
            return binary2(a,mid+1,high,k,t);
        }
        else if(a[mid]>=k) //>=这里多加一个判断
        {
            t=mid;
            return binary2(a,low,mid-1,k,t);
        }
        // else 
        // {
        //     t=mid;
        //     return mid;
        // }
    }
    else {
        return t;//最后return t就行了?
    }
}

int binary(int a[],int low,int high,int k)
{
    int mid;
    mid = (low+high)/2;
    if(low<high)
    {
        if(a[mid]<k)
        {
            return binary(a,mid+1,high,k);
        }
        else if(a[mid]>k)
        {
            return binary(a,low,mid-1,k);
        }
        else 
        {
            return mid;
        }
    }
    else {
        return -1;//没有找到 return -1;
    }
}
