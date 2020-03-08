/*
求g以内最大的数，使其能整除C(n,n+f)

从g开始往下枚举，看把这个数分解质因数以后是不是C(n,n+f)分解质因数的子集
比如20=2*2*5，就看C(n,n+f)是不是至少含有两个2，一个5
为了加快速度，先预处理好100000以内的数的质因数分解列表
然后在程序内部预处理好C(n,n+f)这个数在g以内的素因数各有多少次
最后就直接判断就可以了
怎么求C(n,n+f)有多少个prime因数呢？
function函数是求n!以内有多少个prime因数的。稍微改一下就可以了

关键词：数论 
*/
#include<iostream>
#include<map>
using namespace std;

int value[100001];
map<int,int> factor[100001];
int PRIME[10000];

int function(int n,int prime)
{
    int count=0;
    while(n)
    {
        count+=n/prime;
        n/=prime;
    }
    return count;
}//求n!以内有多少个prime因数 

void Init_value(int n,int f,int g)
{
    for(int i=0;PRIME[i]<=g;i++)
        value[PRIME[i]]=function(n+f,PRIME[i])-function(n,PRIME[i])-function(f,PRIME[i]);
}//预处理 

bool judge(int n,int f,int g)
{
    for(map<int,int>::iterator it=factor[g].begin();it!=factor[g].end();it++)
        if((*it).second>value[(*it).first])return false;
    return true;
}

void Init_prime(void)
{
    int n=0;
    PRIME[n++]=2;
    for(int i=3;n<10000;i+=2)
    {
        for(int j=0;PRIME[j]*PRIME[j]<=i;j++)
            if(i%PRIME[j]==0)goto end;
        PRIME[n++]=i;
        end:;
    }
}//初始化好前10000个质数 

void Init_factor()
{
    for(int i=0;PRIME[i]<100000;i++)
        for(long long j=PRIME[i];j<=100000;j*=PRIME[i])
            for(int k=j;k<=100000;k+=j)
                factor[k][PRIME[i]]++;
}//筛法对100000以内的数分解质因数 

int main()
{
    Init_prime();
    Init_factor();
    
    int t;
    cin>>t;
    while(t--)
    {
        int n,f,g;
        cin>>n>>f>>g;
        
        Init_value(n,f,g);
        
        for(int i=g;i>0;i--)
            if(judge(n,f,i)==true)
            {
                cout<<i<<endl;
                break;
            }
    }
}
