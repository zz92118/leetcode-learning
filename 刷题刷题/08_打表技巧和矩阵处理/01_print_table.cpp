#include<iostream>
#include<vector>
using namespace std;

/*
解决数学规律问题

小虎去买苹果，商店只提供两种类型的塑料袋，每种类型都有任意数量。
1.能装下6个苹果的袋子，2.能装下8个苹果的袋子。
小虎可以自由使用两种袋子来装苹果，但是小虎有强迫症，
他要求自己使用的袋子数量必须最少，且使用的每个袋子必须装满。
给定一个正整数N，返回至少使用多少袋子。如果N无法让使用的每个袋子必须装满，返回-1。
*/

// 牛羊吃草 先后手 一次只能吃(1,4,16,64.....)


//一种数表达成 连续正数的和

bool EatGrass(int val)
//false 代表后手赢
//true 代表先手赢
{
    if(val<5)
    {
        if(val==0 || val==2)
        {
            return false;
        }
        else
        {
            return true;
        }
    }
    //递归暴力破解


    int base_grass=1;

    while(base_grass<=val)
    {
        if(EatGrass(val-base_grass)==false)
        {
            return true;
        }


        base_grass*=4;
    }
    return false;

}

//连续整数的和
bool MSumToN(int val)
{
    int i,j;
    int sum;
    for(i=1;i<val;i++)
    {
        sum=i;
        for(j=i+1;j<=val;j++)
        {
            sum+=j;
            if(sum==val)
            {
                return true;
            }
            else if(sum > val) 
            {
                break;
            }
        }
    }  
    return false;
}

int main()
{
    int i;
    for(i=1;i<500;i++)
    {
        cout<<i<<": "<<MSumToN(i)<<endl;
    }
}