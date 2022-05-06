#include<vector>
#include<iostream>
#include<queue>
#include<math.h>
using namespace std;

/*
准备一个大根一个小跟堆
heap1.size - heap2.size > 2 的时候进行调整

*/
class MedianFinder {
public:
    /** initialize your data structure here. */
    std::priority_queue<int,vector<int>, greater<int> > small_heap;
    std::priority_queue<int,vector<int>, less<int> > big_heap;

    MedianFinder() {


    }
    
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
    //直接用int类型的数字-好像会报错，负值越界的问题。
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
};