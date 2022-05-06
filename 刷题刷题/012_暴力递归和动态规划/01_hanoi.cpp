/*
1.把问题转化为规模缩小了的同类的子问题
2.弟归终止条件
3.子问题的决策过程
4.记录子问题的解（dp和暴力递归的区别）
*/
#include<iostream>
#include<string>
#include<vector>
using namespace std;


// 如下图所示，从左到右有A、B、C三根柱子，
// 其中A柱子上面有从小叠到大的n个圆盘，现要求将A柱子上的圆盘移到C柱子上去，
// 期间只有一个原则：一次只能移到一个盘子且大盘子不能在小盘子上面，
// 求移动的步骤和移动的次数

void move();
void hanoi(int);

class Solution {
public:
    void hanota(vector<int>& A, vector<int>& B, vector<int>& C) {
        int n;
        n= A.size();
        move(n,A,B,C);
    }

    void move(int n,vector<int>& A, vector<int>& B, vector<int>& C)
    //借助B将n-1层的A移动到C
    {
        if(n==1)//不用借
        {
            int curr=A.back();
            C.push_back(curr);
            A.pop_back();
            return ;
        }

        move(n-1,A,C,B);//n-1个盘子从A通过C移动到B
        //把A移动到C
        int curr=A.back();
        C.push_back(curr);
        A.pop_back();

        move(n-1,B,A,C);//n-1个盘子从B通过A移动到C
    }
};


int main()
{
    int n=2;
    hanoi(n);
}


void move(int n,string A,string B,string C)
{
    //借助B将n-1层的A移动到C
    if(n==1)
    {
        cout<<"move 1 from "<<A<<" to "<<C<<endl;
    }

    else 
    {
        move(n-1,A,C,B);
        cout<<"move "<<n<< " from "<<A<<" to "<<C<<endl;
        move(n-1,B,A,C);
    }
}

void hanoi(int n)
{
    if(n>0)
    {
        move(n,"A","B","C");
    }
}