/*
f[n]=(f[n-1]+f[n-2])%10100，输入n<10^15，求f[n]

该数列肯定为循环数列
最大循环周期为10100^2
先编程得到此数列的循环周期为300
现在知道为什么是模10100而不是其他数了，换成别的周期都无比大！
然后就简单了存下这三百个数，把项数取模就行了
项数很大，用long long

关键词：数学题 
*/
#include<iostream>
using namespace std;

int main()
{
    //freopen("aaa.txt","r",stdin);
    
    int f[300]={1,1};
    long long n; 
    
    for(int i=2;i<300;i++)
        f[i]=(f[i-1]+f[i-2])%10100;
        
    while(cin>>n)
    {
        if(n==0)break;
        cout<<f[(n-1)%300]<<endl;
    }
    
    //while(1);
} 
