/*
两个数分别是由1~100的某些数乘起来的。判断有没有作假，具体看原题

递归判断很经典
简单的搜索 

关键词：模拟，递归 
*/
#include<iostream>
using namespace std;

bool aTrue,bTrue;

void judge(int m,int n,int p)
{
    if(aTrue==true)return;
    else if(m==1 && n==1){aTrue=true;return;}
    
    if(n==1)bTrue=true;
    for(int i=p;i>1;i--)
    {
        if(m%i==0)judge(m/i,n,i-1);
        if(n%i==0)judge(m,n/i,i-1);
    }
}

int main()
{
    int a,b;
    while(cin>>a>>b)
    {
        if(a<b)swap(a,b);
        aTrue=false;
        bTrue=false;
        judge(a,b,100);
        
        if(aTrue==false && bTrue==true)
            cout<<b<<endl;
        else cout<<a<<endl;
    }
}
