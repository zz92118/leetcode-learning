#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;


class Solution {
public:
    int nums=0;
    int records[100];//records[i]代表了i行皇后的列号
    vector<vector<string> > result;
    vector<vector<string> > solveNQueens(int n) {
        set_records();
        process(n,0);
        return result;
    }

    void set_records();
    void process(int n ,int index);//index为行数
    void insert_one(int n);
    bool can_set(int row,int column);
};


bool Solution::can_set(int row,int column)
{
    // 检查之前摆过的行 
    int i;
    for(i=0;i<row;i++)
    {
        int j=records[i];
        if( (abs(j-column) == abs(row-i) ) || column==j )
        {
            return false;
        }
    }
    return true;
}

void Solution::set_records()
{
    int i;
    for(i=0;i<100;i++)
    {
        records[i]=0;
    }
}


void Solution::insert_one(int n)
{
    string base="";
    vector<string> re;
    int i;
    //先把一个结果全部设置成。。。。。。，然后再根据records的记录进行修改
    for(i=0;i<n;i++)
    {
        base+=".";
    }
    for(i=0;i<n;i++)
    {
        re.push_back(base);
    }
    //根据records进行修改
    for(i=0;i<n;i++)
    {
        // records[i]记录了i行皇后的列坐标
        re[i][records[i]]='Q';
    }

    result.push_back(re);

}



void Solution::process(int n,int index)
{
    //到递归终止条件，加入一个结果
    if(index>=n)
    {
        nums++;
        insert_one(n);
        return ;
    }

    else 
    {
        //第index行的皇后从0列开始尝试
        for(int j=0;j<n;j++)
        {  
            //如果在index行，j列可以放置
            if(can_set(index,j))
            {
                records[index]=j;
                process(n,index+1);
            }
        }
    }
}


int main()
{
    Solution s;
    s.solveNQueens(4);
    cout<<s.nums;
    return 0;
}