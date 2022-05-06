#include<string>
#include<iostream>
#include<vector>
using namespace std;


class Solution {
public:
    vector<int> result;
    void print_edge(vector<vector<int> >&,int,int,int,int);
    vector<int> spiralOrder(vector<vector<int> >& matrix) {
        int aRow,bColumn,cRow,dColumn;
        aRow=0;
        bColumn=0;
        cRow=matrix.size()-1;
        if(cRow==-1)
        {
            return result;
        }
        dColumn=matrix[0].size()-1;
        //判断空矩阵
        if(cRow==-1 && dColumn==-1)
        {
            return result;
        }
        else 
        {
            //按照圈层进行划分 打印矩阵
            while(aRow<=cRow && bColumn<=dColumn)
            {
                print_edge(matrix,aRow++,bColumn++,cRow--,dColumn--);
            }
            return result;
        }

    }
};

void Solution::print_edge(vector<vector<int> >& matrix,int aRow,int bCloumn,int cRow,int dColumn){
    int curr_row;
    int curr_column;
    curr_row=aRow;
    curr_column=bCloumn;

    //横线和竖线的边界条件
    if(aRow==cRow)
    {
        //打印一行　
        while(bCloumn<=dColumn)
        {
            result.push_back(matrix[aRow][bCloumn++]);
        }
    }
    else if(bCloumn==dColumn)
    {
        //打印一列
        while(aRow<=cRow)
        {
            result.push_back(matrix[aRow++][bCloumn]);
        }
    }

    //打印四个角
    else
    {
        while(curr_column!=dColumn)
        {
            result.push_back(matrix[curr_row][curr_column++]);
        }
        while(curr_row!=cRow)
        {
            result.push_back(matrix[curr_row++][curr_column]);
        }
        while(curr_column!=bCloumn)
        {
            result.push_back(matrix[curr_row][curr_column--]);
        }
        while(curr_row!=aRow)
        {
            result.push_back(matrix[curr_row--][curr_column]);
    }
    }


}

int main()
{
    vector<int> a;
    vector<int> b;
    vector<int> c;
    vector<vector <int> > m;

    a.push_back(1);
    a.push_back(2);
    a.push_back(3);

    b.push_back(4);
    b.push_back(5);
    b.push_back(6);

    c.push_back(7);
    c.push_back(8);
    c.push_back(9);

    m.push_back(a);
    m.push_back(b);
    m.push_back(c);

    Solution s;
    vector<int> re=s.spiralOrder(m);
    for(vector<int>::iterator i=re.begin();i<re.end();i++)
    {
        cout<<*i<<" ";
    }
    return 0;
}


