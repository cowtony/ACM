/*
ID:cowtony1
PROG:money
LANG:C++

有V种面值的硬币，求能组成面值为N的所有方案数

背包问题，dp[i]表示组成面值为i的可能性
对每一种面值p，对所有的j都要有dp[j]+=dp[j-p]，好理解吧

关键词：动态规划 
*/
#include<iostream>
#include<fstream>
using namespace std;

int main()
{
    freopen("money.in","r",stdin);
    freopen("money.out","w",stdout);
    
    int v,n;
    cin>>v>>n;
    
    long long dp[10001]={1};
    for(int i=0;i<v;i++)
    {
        int p;
        cin>>p;
        for(int j=p;j<=n;j++)
            dp[j]+=dp[j-p];
    }
 
    cout<<dp[n]<<endl;
}
