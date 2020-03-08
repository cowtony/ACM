/*
判断一个数是否为两个质数的乘积(semi-prime)

一个数n为semi-prime的充要条件是它在2至sqrt(n)内只有一个因数

关键词：数学题
*/
#include<iostream>
using namespace std;

int main()
{
    int n,i,d;
    
    while(cin>>n)
     {
         d=0;
         
         for(i=2;i*i<=n;i++)
             if(n%i==0)d++;    //求n在2至sqrt(n)内有几个因数
     
         if(d==1)cout<<"Yes"<<endl;
            else cout<<"No"<<endl;
     }
     return 0;
}


