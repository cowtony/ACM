/*
输入一串数，输出他们的最小公倍数

最大公约数，最小公倍数，函数都快背下来了
LCM注意先除后乘

关键词：简单题，数论，数学题 
*/
#include<iostream>
using namespace std;

int GCD(int a,int b)
{
    if(a<b)return GCD(b,a);
    
    if(b==0)return a;
    else return GCD(b,a%b); 
}

int LCM(int a,int b)
{
    return a/GCD(a,b)*b;//先除后乘，避免溢出 
}

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        
        int a,b;
        cin>>a;
        for(int i=1;i<n;i++)
        {
            cin>>b;
            a=LCM(a,b);
        }
        cout<<a<<endl;
    }
} 
