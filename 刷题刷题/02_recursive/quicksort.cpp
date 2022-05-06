#include<iostream>
#include<vector>
using namespace std;


int a[10]={22,33,54,56,213,767,8767,111,21312,3};
int partition(int low,int high); //其中a[i]=a[j] a[j]=a[i] 第一次换了pivot
int quicksort(int low,int high);

int main()
{
    int low=0;
    int high=9;
    int i;
    quicksort(low,high);
    for(i=0;i<10;i++)
    {
        cout<<a[i]<<" ";
    }
    cout<<endl;
    return 0;
}

int partition(int low,int high)
{
    //,右边开始找到小的 
    //左边找到大的
    int i,j;
    int pivot =a[low];
    i = low;
    j = high;
    while(i<j)
    {
        while( (i<j) && a[j]>=pivot)
        {
            j--;
        }
        a[i]=a[j]; //这里换一下left位置 操作一次基准为
        while( (i<j) && a[i]<=pivot)
        {
            i++;
        }
        a[j]=a[i];
        // swap(a[i],a[j]);
    }
    a[i]=pivot;
    return i; //partition的位置

}

int quicksort(int low,int high)
{
    int position;
    //递归终止条件
    if(low<high)
    {
        position = partition(low,high);
        quicksort(low,position-1);
        quicksort(position+1,high);
    }

}
 