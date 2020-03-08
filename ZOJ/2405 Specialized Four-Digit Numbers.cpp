/*
找出所有十进制的四位数，满足它在十进制，十二进制，十六进制时各位之和相等，按顺序输出

编一个按n进制求各位和的函数
再遍历所有十进制四位数，输出满足条件的

关键词：进制转换 
*/ 
#include<iostream>
using namespace std;

int main()
{
    int add(int,int);
    int sum_10,sum_12,sum_16;
    int temp,a,b;
    
    for(int i=1000;i<10000;i++)
    {
        sum_10=add(i,10);
        sum_12=add(i,12);
        sum_16=add(i,16);
        
        if(sum_10==sum_12&&sum_12==sum_16)cout<<i<<endl;
    }
    
    return 0;
}

int add(int n,int base)
{   
    int sum=0; 
    for(;n>0;n/=base)
        sum+=n%base;
    return sum;
}
