#include<iostream>
using namespace std;

int a[10]={4,2,2,6,7,10,9,8,44,222};
int b[10]; //辅助空间

int mergesort(int low,int high);
int merge(int low,int high);

int main()
{
    int low=0;
    int high=9;
    int i;
    mergesort(low,high);
    for(i=0;i<10;i++)
    {
        cout<<b[i]<<" ";
    }
    cout<<endl;
    return 0;
}

int mergesort(int low,int high)
{
    int mid;
    if(low<high)
    {
        mid = (low+high)/2;
        mergesort(low,mid);
        mergesort(mid+1,high);
        merge(low,high);
    }
}

int merge(int low,int high)
{
    int i,j,k;
    int mid;
    mid = (low+high)/2;
    i=low;
    j=mid+1;
    k=low;
    while(i <= mid && j <= high)
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

    if(i<=mid)
    {
        while(i<=mid)
        {
            b[k]=a[i];
            k++;
            i++;
        }
    }   

    else if(j<=high)
    {
        while(j<=high)
        {
            b[k]=a[j];
            k++;
            j++;
        }
    }
    //最后归并到a 忘了 额外的空间复杂度
    for(i=low;i<high;i++){
        a[i]=b[i];
    }

}

