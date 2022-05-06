#include<iostream>
#include<unordered_set>
#include<unordered_map>
using namespace std;

int main()
{
    unordered_map<int,string> Map;
    unordered_set<int> Set;
    //map 存放
    Map[1]="string1";
    Map[2]="string2";
    //map 取
    cout<<Map[1]<<endl;
    Map.size();

    //set存放
    Set.insert(1);
    Set.insert(2);
    Set.insert(2);
    Set.insert(2);
    //set查询
    Set.size();
    cout<<Set.count(3)<<endl;;
}