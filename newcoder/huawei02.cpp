#include<string>
#include<iostream>
using namespace std;

int main(){
    string str;
    int i;
    int count=0;
    char c;
    getline(cin,str);
    cin>>c;
    for(i=0;i<str.size();i++)
    {
        if(tolower(c)==tolower(str[i]))
        {
            count++;
        }
    }
    cout<<count<<endl;
    return 0;
}