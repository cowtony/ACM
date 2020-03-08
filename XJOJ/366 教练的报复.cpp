/*
看原题 

dp[i][j][0]表示：i个人，1，2……i 个头依次递增，以j为排头，j后面一个人比他矮，可行的方案数。(j<=i) 
dp[i][j][1]表示：i个人，1，2……i 个头依次递增，以j为排头，j后面一个人比他高，可行的方案数。(j<=i) 
则动规方程为：
dp[i][j][0]=sigma(dp[i-1][x][1])，其中1<=x<j。 
dp[i][j][1]=sigma(dp[i-1][y][0])，其中j<=x<i。 
初始化：dp[1][1][0]=dp[1][1][1]=1; 
对于输入的人数n和排头m，可行的方案数为dp[n][m][0]+dp[n][m][1]。 
注意： 
1：n=1,m=1这组是特例，可行的方案数为1，不是2。 
2：后面几组的结果比较大，用long long别用int。 

关键词：动态规划 
*/
#include<iostream>
using namespace std;

int main()
{
    long long dp[21][21][2]={0};
    dp[1][1][0]=dp[1][1][1]=1;//初值状态
    
    for(int i=2;i<=20;i++)
    {
        for(int j=1;j<=i;j++)
        {
            for(int x=1;x<j;x++)
                dp[i][j][0]+=dp[i-1][x][1];
            for(int x=j;x<i;x++)
                dp[i][j][1]+=dp[i-1][x][0];
        }
    }
    
    int n,m;
    while(cin>>n>>m)
    {
        if(n==0 || m==0)break;
        
        if(n==1 && m==1)cout<<1<<endl;
        else cout<<dp[n][m][0]+dp[n][m][1]<<endl;
    }
}
