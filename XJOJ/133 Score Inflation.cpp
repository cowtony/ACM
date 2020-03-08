/*
输入总时间time和题目的种类数量kind，接下来输入每种题需要的时间elapse和能得到的分数score
求在总时间内最多可以得多少分

完全背包问题
动态规划dp[i]表示i时间内最多可以得到的分数
状态转移方程dp[i]=max(dp[i],dp[i-elapse]+score) 
 
关键词：动态规划，背包问题 
*/
#include<iostream>
using namespace std;

int main()
{
    int time,kind;
    cin>>time>>kind;
    
    int dp[10001]={0};
    for(int i=0;i<kind;i++)
    {
        int score,elapse;
        cin>>score>>elapse;
        
        for(int j=elapse;j<=time;j++)
            dp[j]=max(dp[j],dp[j-elapse]+score);
    }
    cout<<dp[time]<<endl;
}
