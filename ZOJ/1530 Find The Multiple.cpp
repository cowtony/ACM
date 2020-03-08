/*
输入一个数，输出它的倍数，要求只能有1和0这两个数字 

深度优先搜索
自己看函数吧

关键词：深度优先搜索 
*/
#include<iostream>
using namespace std;

int flag;

void output(int a[],int len,int rem,int n)
{
    if(rem==0 && flag)
    {
        flag=false;
        for(int i=0;i<len;i++)
            cout<<a[i];
        cout<<endl;
    }
    else if(flag==true && len<100)
    {
        a[len]=0;
        output(a,len+1,(10*rem)%n,n);
        a[len]=1;
        output(a,len+1,(10*rem+1)%n,n);
    }
}

int main()
{
    int n;
    while(cin>>n)
    {
        if(n==0)break;
        
        int digit[100]={1};
        flag=true;
        output(digit,1,1,n);
    }
}

