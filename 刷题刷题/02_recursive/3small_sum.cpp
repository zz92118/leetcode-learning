#include<iostream>
using namespace std;

/*
小和问题
1 3 4 2 5 
sum= 1 + 1+3 +1 +1+2+3+4=1+4+1+10=16
转化为右侧有几个数比他大 4*1+2*3+1*4+2*1=4+6+4+2=16

*/

int a[5]={1,2,3,4,5};
int b[5]; //辅助空间

int small_sum(int low,int high);
int merge(int low,int high);

int main()
{
    int low=0;
    int high=4;
    int i;
    int result =0;
    result = small_sum(low,high);
    for(i=0;i<5;i++)
    {
        cout<<a[i]<<" ";
    }
    cout<<endl;
    cout<<"small sum:"<<result<<endl;
    return 0;
}

int small_sum(int low,int high)
{
    int mid;
    mid = low +((high-low)>>1);
    if (low<high)
    {
        return small_sum(low,mid) + small_sum(mid+1,high) + merge(low,high);
    }
}

int merge(int low,int high)
{
    int mid;
    int temp=0;
    mid = low +((high-low)>>1);
    int i=low;
    int j=mid+1;
    int k=low;

    while(i<=mid && j<=high)
    {
        if(a[i]<a[j])
        {
            temp+=a[i]*(high-j+1); //右侧有多少个比当前左侧大的数
            b[k] = a[i];
            i++;
            k++;
        }
        else if(a[i]>=a[j])
        {
            b[k]=a[j];
            j++;
            k++;
        }
    }
    while(i<=mid)
    {
        b[k]=a[i];
        i++;
        k++;
    }

    while(j<=high)
    {
        b[k]=a[j];
        j++;
        k++;
    }

    for(k=low;k<=high;k++)
    {
        a[k]=b[k]; 
    }

    return temp;

}



