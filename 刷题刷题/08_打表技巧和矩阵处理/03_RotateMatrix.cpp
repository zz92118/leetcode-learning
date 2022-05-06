#include<vector>
#include<iostream>
#include<algorithm>

using namespace std;

class Solution {
public:
    vector<int> result;
    void rotate(vector<vector<int> >& matrix) {
        int aRow,bColumn,cRow,dColumn;
        aRow=0;
        bColumn=0;
        cRow=matrix.size()-1;
        if(cRow==-1)
        {
            return ;
        }
        dColumn=matrix[0].size()-1;
        while(aRow<=cRow)
        {
            rotate_layer(matrix,aRow++,bColumn++,cRow--,dColumn--);
        }
    }

    void rotate_layer(vector<vector <int> >& matrix,int aRow,int bCloumn,int cRow,int dColumn);
};

void Solution::rotate_layer(vector<vector <int> >& matrix,int aRow,int bCloumn,int cRow,int dColumn)
{
    if(aRow==cRow)
    {
        return ;
    }
    else 
    {
        int i;
        for(i=0;i<dColumn-bCloumn;i++)
        {
            swap(matrix[aRow][bCloumn+i],matrix[aRow+i][dColumn]);
            swap(matrix[cRow][dColumn-i],matrix[cRow-i][bCloumn]);
            swap(matrix[aRow][bCloumn+i],matrix[cRow][dColumn-i]);
        }
    }
}

int main()
{
    vector<int> a;
    vector<int> b;
    vector<int> c;
    vector<vector <int> > m;
    int i,j;


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
    for(i=0;i<m.size();i++)
    {
        for(j=0;j<m.size();j++)
        {
            cout<<m[i][j]<<" ";
        }
        cout<<endl;
    }
    s.rotate(m);
    for(i=0;i<m.size();i++)
    {
        for(j=0;j<m.size();j++)
        {
            cout<<m[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}



