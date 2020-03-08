/*
输入一堆赋值式，起初只有a有确定值，求现在有确定值的变量

因为变量只有26个，a=1表示有确定值，0则为无确定值
读入表达式并对数组操作
最后输出值为1的变量

关键词：简单题 
*/
#include<iostream>
using namespace std;

int main()
{
    bool c[26]={1};
    char e[4];
    int n;
    cin>>n;
    
    while(n--)
    {
        cin>>e;
        c[e[0]-'a']=c[e[2]-'a'];

    }
    
    int count=0;
    for(int i=0;i<26;i++)
        if(c[i]==1)count++;
     
    for(int i=0;i<26;i++)
        if(c[i]==1)cout<<char(i+'a')<<' ';
    
    if(count==0)cout<<"none";
    
    //while(1);
    return 0;
}
