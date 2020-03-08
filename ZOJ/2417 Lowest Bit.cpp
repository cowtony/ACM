/*
输入A，输出A的二进制最后(10000)形式的值。如26=11010，输出10=2。88=1011000，输出1000=8

本题的意思可以理解为输出A最大可以被2的几次方整除
用筛法思路先预存下100以内的答案，直接输出

关键词：数学题，简单题 
*/
#include<iostream>
using namespace std;

int main()
{
    int a;
    int data[101];
    
    for(int i=1;i<=100;i*=2)
        for(int j=i;j<=100;j+=i)data[j]=i;//核心的筛法 
    
    while(cin>>a)
    {
        if(a==0)return 0;
        cout<<data[a]<<endl;
    }
}
