/*
求扔骰子点数的期望，共有n个骰子，每个有m个面，最后总点数要减去k，小于1的当1计算

用深度搜索遍历n个骰子所有的组合情况，把最终点数记在times数组里
times[i]表示i这个点数有多少种组合方法
i/m^n就是i点的概率，再乘以(i-k)或1

关键词：概率，深度优先搜索 
*/
#include<iostream>
#include<cmath>
using namespace std;

int n,m,k;
int times[1000000];

void search(int layer,int total)
{
    if(layer==n){times[total]++;return;}
    
    for(int i=1;i<=m;i++)
        search(layer+1,total+i);
}

int main()
{
    while(cin>>n>>m>>k)
    {
        if(n==0 && m==0 && k==0)break;
        
        memset(times,0,sizeof(times));
        search(0,0);
         
        double p=0;
        double total=pow(m,double(n)); 
        for(int i=n;i<=m*n;i++)
        {
            if(i>k)p+=(i-k)*times[i]/total;
            else p+=times[i]/total;
        }
        printf("%.10f\n",p);
    }
}
