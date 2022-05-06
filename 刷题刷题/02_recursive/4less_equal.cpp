#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

/*
讲一个数组中的某个数放到正确的位置 左边小右边大
设置一个小于等于区

*/

// int a[10]={22,33,54,56,213,767,8767,111,21312,3};

int init(vector<int>& a)
{
    a.push_back(22);
    a.push_back(33);
    a.push_back(54);
    a.push_back(56);
    a.push_back(213);
    a.push_back(767);
    a.push_back(8767);
    a.push_back(111);
    a.push_back(2132);
    a.push_back(3);
}


int main()
{
    vector<int> a;
    init(a);

    for(vector<int>::iterator i=a.begin();i != a.end();i++)
    {
        cout<<*i<<" ";
    }
    cout<<endl;
    int low=0;
    int high=a.size();
    int i;
    int area;
    int key;
    key=a[7];
    area = -1 ;//小于等于区域 -1开始
    for(i=0;i<high;i++)
    {
        if(a[i]<=key)
        {
            swap(a[area+1],a[i]); //当前数和小于等于区下一个数交换
            area++;
        }

        else 
        {
            //
        }
    }
    for(vector<int>::iterator i=a.begin();i != a.end();i++)
    {
        cout<<*i<<" ";
    }
    return 0;
}

