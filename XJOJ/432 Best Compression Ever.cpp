/*
n个互不相同的文件，有没有可能把他们分别压缩成不大于b个二进制位的文件？

不大于b个二进制位的所有可能，是长度为0,1,2,...,b的串
每个串的不同情况为1,2,4,...,2^b
总情况为2^(b+1)-1，判断它和n的大小

关键词：简单题 
*/
#include<iostream>
using namespace std;

int main()
{
    long long n,b;
    cin>>n>>b;
    
    long long different=1;
    for(int i=1;i<=b+1;i++)
        different*=2;
    different--;

    if(n>different)cout<<"no";
    else cout<<"yes";
    
    //while(1);
}
