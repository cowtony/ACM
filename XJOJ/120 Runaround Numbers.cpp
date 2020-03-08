/*
Runaround数的定义是：每个数位都不重复，且没有零。
比如81362，第一个是8，往右循环数8个数是6，再往右循环数6个数是2，最后全部数完又回到8
输入M，找出比M大的最小的Runaround数

写个函数判断一个数是不是Runaround，再枚举 

关键词：枚举，模拟，高精度 
*/
#include<iostream>
using namespace std;

bool Runaround(int n)
{
    int digit[10]={0};
    bool map[10]={0};
    bool used[10]={0};
    
    int length=0;
    while(n)
    {
        digit[length]=n%10;
        if(used[digit[length]]==false)used[digit[length]]=true;//如果某一位重复出现就错了 
        else return false;
        
        if(digit[length]==0)return false;//出现0也错了 
        length++;
        n/=10;
    }//把n按位存进数组 
    
    int l=length-1;
    int t=0;
    while(map[l]==false)
    {
        map[l]=true;
        l=((l-digit[l])%length+length)%length;//循环数个数，因为是反着村的所以反着数 
        t++;
    }
    if(t==length && l==length-1)return true;
    else return false;
}

int main()
{
    int M;
    cin>>M;
    
    for(int i=M+1;i<=987654321;i++)
        if(Runaround(i)==true)
        {
            cout<<i<<endl;
            break;
        }
    //while(1);
}
