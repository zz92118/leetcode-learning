#include<vector>
#include<iostream>
#include<queue>
#include<math.h>
using namespace std;
/** initialize your data structure here. */
std::priority_queue<int,vector<int>, greater<int> > small_heap;
std::priority_queue<int,vector<int>, less<int> > big_heap;


void addNum(int num)
{

    //1.先加入大根堆
    if(big_heap.empty())
    {
        big_heap.push(num);
        return;
    }
    //根据num的大小决定进入的heap
    if(num<=big_heap.top())
    {
        big_heap.push(num);
    }

    else 
    {
        small_heap.push(num);
    }
    int x1=big_heap.size();
    int x2=small_heap.size();
    //相差>2进行堆调整
    if( (x1-x2 >=2) || (x1-x2<=-2))
    {
        //调整
        if(x1-x2>0)
        {
            //大根堆pop进小根堆
            int curr=big_heap.top();
            big_heap.pop();

            small_heap.push(curr);
        }

        else 
        {
            //小根堆pop进大根堆
            int curr=small_heap.top();
            small_heap.pop();
            big_heap.push(curr);
        }
    }

}

double findMedian()
{
    if(small_heap.size()==big_heap.size())
    {
        return (small_heap.top()+big_heap.top())/2.0;
    }

    else 
    {
        return small_heap.size()>big_heap.size() ? small_heap.top()*1.0 : big_heap.top()*1.0;
    }
}

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */
int main()
{
    addNum(1);
    addNum(2);
    // addNum(3);
    cout<<findMedian();
    return 0;
}