/*
看原题，01背包问题

不能定义f[n][m]内存会溢出
优化空间复杂度以后定义f[m]，表示容量为m的话最多能放多少价值的东西
状态转移方程：f[v]=max(f[v],f[v-w[i]]+s[i])表示f[v]取不放第i件物品和放第i件物品这两种方案的最大值
经典的优化内存

关键词：动态规划，01背包问题 
*/
#include<iostream>
using namespace std;

int main()
{
    int n,m;
    cin>>n>>m;
    
    int w[3402],s[3402];
    for(int i=0;i<n;i++)
        cin>>w[i]>>s[i];
        
    int f[12881]={0};
    for(int i=0;i<n;i++)
        for(int v=m;v>=0;v--)
            if(v>=w[i])
                f[v]=max(f[v],f[v-w[i]]+s[i]);
                
    cout<<f[m]<<endl;
    //while(1);
}
