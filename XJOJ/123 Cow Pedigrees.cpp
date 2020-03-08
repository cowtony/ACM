/*
有n<200个节点，k<100层的二叉树，每个节点只有0或2个子节点。求n个节点，k层的二叉树有多少种？

动态规划，dp[k][n]表示k层及以下，n个节点的可能数。
状态转移方程：dp[i][j]+=dp[i-1][k]*dp[i-1][j-k-1]
注意结果要对9901取模，节点数只可能为奇数

关键词：动态规划 
*/
#include<iostream>
using namespace std;

int main()
{
    int n,k,dp[100][200]={0};
	cin>>n>>k;
	
	for(int i=1;i<=k;i++)dp[i][1]=1;
	
	for(int i=1;i<=k;i++)
		for(int j=3;j<=n;j+=2)
			for(int k=1;k<=j-2;k+=2)
			{
				dp[i][j]+=dp[i-1][k]*dp[i-1][j-k-1];
				dp[i][j]%=9901; 
            }
				
	cout<<(dp[k][n]-dp[k-1][n]+9901)%9901<<endl;
}
