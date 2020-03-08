/*
有n项杂务，每一项有自己的耗时，而且完成第n项还必须先完成其他几项，求全部做完的最小时间

关键路径的题，但是由于这道题声明“杂务k(k>1)的准备工作只可能在杂务1..k-1中”
所以可以直接用动态规划（递推）做
dp[i]表示第i个杂物完成时的最早时间
假设a,b,c是完成i的先决任务，那么dp[i]=max{dp[a],dp[b],dp[c]}+time[i]
线性时间就可以做出来了

关键词：动态规划，关键路径 
*/ 
#include<iostream>
using namespace std;

int main()
{
    //freopen("aaa.txt","r",stdin);
    int dp[10001];
    int n;
    cin>>n;
    
    int result=0;
    for(int i=1;i<=n;i++)
    {
        int time,need;
        cin>>time>>time;
        int max=0;
        while(cin>>need && need!=0)
            if(max<dp[need])max=dp[need];
        dp[i]=max+time;
        if(result<dp[i])result=dp[i];
    }
    
    cout<<result;
    //while(1);
}
