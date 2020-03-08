#include<iostream>
using namespace std;

int a,b,n;

int GCD(int a,int b)
{
    if(b==0)return a;
    else return GCD(b,a%b);
}

int LCM(int a,int b)
{
    return a/GCD(a,b)*b;
}

int S(int m)
{
    int count=0;
    for(int i=2;2*i<=m;i++)
    {
        int factor=max(m/i-1,0);
        int temp=i^n;
        
        if(temp==0)count+=factor;
        else
        {
            int lcm=LCM(i,temp);
            if(lcm>i)count+=factor-m/lcm;
        }
    }
    return count;
}

int d(int m)
{
    int count=0;
    for(int i=2;i<m;i++)
    {
        if(m%i==0)
        {
            if((i^n)==0)count++;
            else if(m%(i^n)!=0)count++;
        }
    }
    return count;
}

int main()
{
    while(scanf("%d%d%d",&a,&b,&n)!=NULL)
    {
        printf("%d\n",S(a+b)-S(a-1));
    }
} 
