#include<iostream>
#include<string>
using namespace std;

int main(){
    string str;
    getline(cin,str);
    int fast,slow;
    fast = 0;
    slow = 0;
    string temp="";
    while(fast<str.size()){
        if(str[fast]==' ')
        {
            temp="";
            fast++;
            continue;
        }
        temp+=str[fast];
        fast++;
    }
    cout<<temp.size()<<endl;
    return 0;
}