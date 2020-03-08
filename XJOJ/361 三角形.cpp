/*
输入一个整数边长，输出含有他并各边均为整数的所有直角三角形

先考虑已知边是一条直角边的情况，设它是a
则a^2=c^2-b^2=(c+b)*(c-b)
假设a^2可写成p*q,p<q
则c-b=p,c+b=q
遍历p(q)的值，当上方程组有整数解时输出

再考虑是斜边的情况
直接遍历一条直角边，看剩下的是不是完全平方数就可以了
由于数很大用的long long所以要小心
开方后加0.5再取整（四舍五入）

关键词：数学题 
*/
#include<iostream>
#include<cmath>
using namespace std;

int main()
{
    long long n,a,b;
    double t;
    int solution=0;
    cin>>n;
    
    for(int i=1;i<n;i++)
    {
        if((n*n)%i==0)
        {
            if((n*n/i+i)%2==0 && (n*n/i-i)%2==0)
            {
                cout<<(n*n/i+i)/2<<','<<(n*n/i-i)/2<<endl;
                solution++;
            }
        }
    }
    
    for(int i=n-1;i>n/sqrt(2);i--)
    {
        b=sqrt(n+i)*sqrt(n-i)+0.5;
        if((n+i)*(n-i)==b*b)
        {
            cout<<i<<','<<b<<endl;
            solution++;
        }
    }
    
    if(solution==0)cout<<0<<endl;
    
    //while(1);
}
