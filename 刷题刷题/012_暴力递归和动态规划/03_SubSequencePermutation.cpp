#include<iostream>
#include<vector>
#include<string>
#include<unordered_set>
using namespace std;


/*
对于排列交换问题
    不用额外的空间,直接swap,但是最后要swap回来 
    !!!!!就是恢复 现场!!!!
对于子序列问题:使用了额外的空间
*/
class Permutation
{
public:
    void print_all_permutations(string s);
    void print_all_permutations_no_repeated(string s);

    //path记录下当前弟归栈的一条路径,result为所有路径
    void process(string &s,int index,vector<string> &result);
    void process2(string &s,int index,vector<string> &result);//分枝
    //意思是从index位置开始swap获得新的string,不使用额外的存储空间 
    //不用额外的空间,直接swap,但是最后要swap回来
};

void Permutation::process(string &s,int index,vector<string> &result)//不用额外的空间,直接swap,但是最后要swap回来
{
    if(index>=s.length())
    {
        result.push_back(s);
        return ;
    }

    else 
    {
        int j;
        //从index开始可以交换
        for(j=index;j<s.length();j++)
        {
            swap(s[index],s[j]);
            process(s,index+1,result);
            swap(s[index],s[j]);//换回来
        }
    }
}

void Permutation::process2(string &s,int index,vector<string> &result)//不用额外的空间,直接swap,但是最后要swap回来
{
    if(index>=s.length())
    {
        result.push_back(s);
        return ;
    }
    else 
    {
        int j;
        unordered_set<char> hash_set;
        for(j=index;j<s.length();j++)
        {
            //在之前的位置里没有出现过 
            if(!hash_set.count(s[j]))
            {
                hash_set.insert(s[j]);//加入记录
                swap(s[index],s[j]);
                process2(s,index+1,result);
                swap(s[index],s[j]);

            }

        }
    }
}



void Permutation::print_all_permutations(string s)
{
    vector<string> result;
    process(s,0,result);
    cout<<"Sub Permutation Number: "<<result.size()<<endl;
    for(vector<string>::iterator i=result.begin();i<result.end();i++)
    {
        cout<<*i<<" ";
    }
    cout<<endl;

}

void Permutation::print_all_permutations_no_repeated(string s)
{
    vector<string> result;
    process2(s,0,result);
    cout<<"Sub Permutation Number no repeated: "<<result.size()<<endl;
    for(vector<string>::iterator i=result.begin();i<result.end();i++)
    {
        cout<<*i<<" ";
    }
    cout<<endl;

}


class SubSequence
{
public:
    void print_all_sub_sequence(string s);
    //path记录下当前弟归栈的一条路径,result为所有路径
    void process(string s,int index,vector<string> &result,string path);
    //不重复的打印,不出现重复字面的值
    void print_all_sub_sequence_no_repeated(string s);
    void process2(string s,int index,unordered_set<string> &result,string path);

};

void SubSequence::process2(string s,int index,unordered_set<string> &result,string path)
{
    if(index>=s.length())
    {
        result.insert(path);
        return ;
    }
    else 
    {
        string yes,no;
        yes=path+s[index];
        no=path;
        process2(s,index+1,result,yes);
        process2(s,index+1,result,no);
    }
}

void SubSequence::print_all_sub_sequence_no_repeated(string s)
{
    unordered_set<string> result;
    string path="";
    process2(s,0,result,path);
    cout<<"Sub Sequence None Repeated Number(就是子集，因为同样的出现的次序又先后): "<<result.size()<<endl;
    //遍历是无序的
    for(unordered_set<string>::iterator i=result.begin();i!=result.end();i++)
    {
        cout<<*i<<" ";
    }
    cout<<endl;

}




void SubSequence::print_all_sub_sequence(string s)
{
    vector<string> result;
    string path="";
    process(s,0,result,path);
    cout<<"Sub Sequence Number: "<<result.size()<<endl;
    for(vector<string>::iterator i=result.begin();i<result.end();i++)
    {
        cout<<*i<<" ";
    }
    cout<<endl;
}

void SubSequence::process(string s,int index,vector<string> &result,string path)
{
    if(index >= s.length())
    {
        result.push_back(path);
        return ;
    }

    else 
    {
        string yes,no;
        yes=path+s[index];//加入当前字符
        no=path;//不加入当前字符

        process(s,index+1,result,yes);
        process(s,index+1,result,no);
    }
}





int main()
{
    SubSequence solution;
    string str1="abc";
    solution.print_all_sub_sequence(str1);
    string str2="abb";
    solution.print_all_sub_sequence_no_repeated(str2);

    Permutation solution2;
    string str3="aaa";
    solution2.print_all_permutations(str3);
    solution2.print_all_permutations_no_repeated(str3);

}