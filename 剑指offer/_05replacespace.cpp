#include<iostream>
using namespace std;

class Solution {
public:
    string replaceSpace(string s) {}
        int length1=s.length();
        int length2;
        int i,j;
        int number=0;
        for(i=0;i<length1;i++)
        {
            if(s[i]==' ')
            {
                number++;
            }
        }
        
        length2=number*2+length1;

        i=length1;
        j=length2;

        while (i>0 && j>0)
        {
            if(s[i]==' ')
            {
                s[j--]='0';
                s[j--]='2';
                s[j--]='%';
                i--;
            }

            else
            // 替换j指向的位置
            {
                s[j--]=s[i--];
            }
        }
        
        // return length;
        return s;
    }
};

int main()
{
    string s="a b c d"; //7+1=8

    Solution slo;

    cout<<slo.replaceSpace(s)<<endl;

    // cout<<strlen(s);

    return 0;

}