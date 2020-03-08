/*
验证哥德巴赫猜想，输出两质数差最大的一组解

先打出1000000内的素数表
然后就找即可
用cin会超时 

关键词：数论，简单题 
*/
#include<iostream>
using namespace std;

int main()
{
    bool prime[1000001];
    memset(prime,true,sizeof(prime));
    
    for(int i=2;i*i<=1000001;i++)
        for(int j=i*2;j<=1000000;j+=i)
            prime[j]=false;
    
    int n;
    while(scanf("%d",&n)!=EOF)
    {
        if(n==0)break;
        
        for(int i=3;i<=n/2;i+=2)
            if(prime[i]==true && prime[n-i]==true)
            {
                printf("%d = %d + %d\n",n,i,n-i);
                break;
            }
    }
} 
