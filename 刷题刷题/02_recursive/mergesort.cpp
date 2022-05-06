#include<iostream>
using namespace std;

int a[10]={4,2,2,6,7,10,9,8,44,222};
int b[10]; //辅助空间

int mergesort(int a[],int low,int high);
int merge(int a[],int b[],int low,int high);

int main()
{
    int low=0;
    int high=9;
    int i;
    mergesort(a,low,high);
    for(i=0;i<9;i++)
    {
        cout<<a[i]<<" ";
    }
    cout<<endl;
    return 0;
}

int mergesort(int a[],int low,int high)
{
    int mid;
    if(low<high)
    {
        mid = low + (high-low)>>2;
        mergesort(a,low,mid);
        mergesort(a,mid+1,high);
        merge(a,b,low,high);
    }
    else 
    {
        return ;
    }
}

int merge(int a[],int b[],int low,int high)
{
    int i,j,k;
    int mid;
    mid = low + (high-low)>>2;
    i=low;
    j=mid;
    k=low;
    while(i <= mid && j <= high) //只有在这里产生小何
    {
        if(a[i]<a[j])
        {
            b[k]=a[i];
            k++;
            i++;
        }

        else
        {
            b[k]=a[j];
            k++;
            j++;
        }

    } 

    //越界后不产生小河,只需要进行排序
    if(i==mid)
    {
        while(j!=high)
        {
            b[k]=a[j];
            k++;
            j++;
        }
    }   

    else if(j==high)
    {
        while(i!=mid)
        {
            b[k]=a[i];
            k++;
            i++;
        }
    }

}

