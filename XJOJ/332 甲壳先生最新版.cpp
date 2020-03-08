/*
m*n的格子纸，一个甲虫从左下角到右上角走直线，要经过几个格子？
如果已知经过格子数，求m,n的组合种数

甲虫经过的格子交叉点相距是一定的
又因为左下角和右上角是两个交叉点
对m,n提出一个公因数，所构成的也是在交叉点上
所以提出公因数k后得到a,b互质，此时a*b的路线只有左下和右上是整数点
甲虫从左走到右有a个格子，从下往上穿过了b-1条线，所以走了a+b-1个格子
再乘以最大公约数k，得到经过格子数为m+n-gcd(m,n)

第二问是解m+n-gcd(m,n)=c的解数，设gcd(m,n)=k
k(a+b-1)=c，k|c
所以a+b=x+1，其中x取遍c的约数，包括1和c
又因为a，b互质，所以x+1中x+1的所有约数及他的倍数不能取，否则ab不互质

关键词：数论 
*/
#include<iostream>
using namespace std;

long long gcd(long long a,long long b)
{
    if(a<b)return gcd(b,a);
    if(b==0)return 0;
    
    if(a%b==0)return b;
    else return gcd(b,a%b);
}//辗转相除法求最大公约数 

int f(int x)
{
    bool judge[10005]={0};
    int count=0;
    
    for(int i=2;i<=x/2;i++)
        if(x%i==0)
            for(int j=i;j<x;j+=i)
                judge[j]=1;

    for(int i=1;i<x;i++)
        if(judge[i]==0)count++;

    return count;
}

int main()
{
    long long n,m;
    int c;
    cin>>n>>m>>c;

    cout<<m+n-gcd(m,n)<<endl;//第一问
    
    int result=0;
    for(int i=1;i<=c;i++)
        if(c%i==0)
            result+=f(i+1);

    cout<<result;
    
    //while(1);
    return 0;
}


