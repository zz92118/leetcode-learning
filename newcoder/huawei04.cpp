#include<iostream>
#include<string>
using namespace std;

int main()
{
    string str;
    while(getline(cin,str))
    {
        while(str.size()>8)
        {
            cout <<str.substr(0,8)<<endl;//从0位置开始，截取8个数字。
            str = str.substr(8,str.size() - 8); //将剩余的数组重新放入到字符串中
        }
        
        if(str.size()==8)
        {
            cout<<str<<endl;
        }
        else if(str.size()<8)
        {
            string str1=str;
            while(str1.size()<8)
            {
                str1+="0";
            }
            cout<<str1<<endl;
        }
        else 
        {
            int num = str.size() / 8 + 1; //输出到行的个数
            int i;
            // 0-7 8-15 16-23 24-26
            for(i=0;i<num;i++)
            {
                cout<<str.substr(i*8,i*8+8)<<endl;
            }
            string str1=str.substr(8*i,str.size()-1);
            while(str1.size()<8)
            {
                str1+="0";
            }
            cout<<str1<<endl;
        }
    }
    return 0;
    
}