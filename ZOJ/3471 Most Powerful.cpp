/*
有n<=10个原子，每两个合并后释放能量并且后者消失，输入一个矩阵表示i,j合并释放出的能量，输出最大可以得到的能量

利用位运算表示状态，0表示存在，1表示消失了，n个原子的状态可由一个int表示
dp[i]为当前状态，遍历所有的状态i，对于每一种状态，遍历所有还存在的两个原子组合k,j
他们消失时放出的能量为dp[i|(1<<j)]=max(dp[i|(1<<j)],dp[i]+map[k][j])
最后遍历一遍所有状态找出最大值输出

关键词：动态规划 
*/
#include<iostream>
using namespace std;

int main()  
{  
    int n;  
    while(cin>>n && n!=0)  
    {
        int map[10][10];  
        for(int i=0;i<n;i++)  
            for(int j=0;j<n;j++)  
                cin>>map[i][j];

        int dp[1<<10]={0};
        for(int i=0;i<(1<<n);i++)
            for(int j=0;j<n;j++)
                for(int k=0;k<n;k++)
                    if((i&(1<<j))==0 && (i&(1<<k))==0 && j!=k)
                        dp[i|(1<<j)]=max(dp[i|(1<<j)],dp[i]+map[k][j]);

        int ans=0;  
        for(int i=0;i<(1<<n);i++)  
            ans=max(ans,dp[i]);
        cout<<ans<<endl;
    }
}
