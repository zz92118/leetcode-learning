#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;

/*
堆:在C++中的实现为优先队列 
进策略:先进·
出策略:高优先级的出·

*/

void stl_heap()
{
    priority_queue <int,vector<int>,greater<int> > heap_small;//小
    priority_queue <int,vector<int>, less<int> > heap_large;//大
    heap_small.push(1);
    heap_small.pop();
    heap_small.top();
}

class heap
{
private:
    vector<int> a;
public:
    heap(/* args */);
    ~heap();
    void heap_sort();
    void heap_out();
    void heap_insert(int i);
    void heapify(int index,int heapsize);//调整某个位置

    //在堆中去掉最大值
};


heap::heap(/* args */)
{
    a.push_back(3);
    a.push_back(5);
    a.push_back(9);
    a.push_back(4);
    a.push_back(6);
    a.push_back(7);
    a.push_back(0);
}

void heap::heap_sort()
{
    int i;
    if(a.size()==0 || a.size()<2)
    {
        return ;
    }
    //heap insert 进行排序
    for(i=0;i<a.size();i++)
    {
        heap_insert(i);
    }
    //排序 插入前提是所有的数据已经得到
    for(i=a.size()-1;i>=0;i--)
    {
        heapify(i,a.size());
    }
    //swap pop
    swap(a[a.size()-1],a[0]);
    cout<<a[a.size()-1];
    a.pop_back();

    while(a.size()>0)
    {
        heapify(0,a.size());
        //swap pop
        swap(a[a.size()-1],a[0]);
        cout<<a[a.size()-1];
        a.pop_back();
    }

}

void heap::heapify(int index,int heapsize)
{
    //指调整堆顶而不调整堆的其他元素
    int left=2*index+1;

    //比较左右两个孩子和当前节点的大小
    //下标从0开始 heapsize从1开始计算
    while(left<heapsize)
    {
        int right;
        int larger;
        right=left+1;
        //有右孩子
        if(right<heapsize)
        {
            if(a[left]>a[right])
            {
                larger=left;
            }

            else
            {
                larger=right;
            } 
        }
        else
        {
            larger = left;
        }

        larger = a[larger] > a[index] ? larger : index;
        
        if(larger==index)
        {
            break;
        }
        else
        {
            swap(a[larger],a[index]);
            index = larger;
            left = index * 2 +1;
        }
    }
}

void heap::heap_insert(int i)
{
    while(a[i]>a[(i-1)/2])
    {
        swap(a[i],a[(i-1)/2]);
        i = (i-1)/2;
    }
}

void heap::heap_out(/* args */)
{
    int i;
    for(vector<int>::iterator i=a.begin();i<a.end();i++)
    {
        cout<<*i<<" ";
    }
    cout<<endl;
}

heap::~heap()
{
}

int main()
{
    heap h1;
    h1.heap_sort();
    h1.heap_out();
    return 0;

}

