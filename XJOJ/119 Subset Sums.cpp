/*
把1到n的自然数分成两组，使得每组的和相等，求分组数

动态规划
count[i][j]表示在1-i的自然数中凑出j的方案数
题中所要求的就是count[n][sum(n)/2]
状态转移方程为count[i][j]=count[i-1][j]+count[i-1][j-i]
其意义是：i中凑出j的方案数等于i-1中凑出j的方案数（不选取i本身）加上i-1中凑出j-i的方案数（选取i本身进入方案）

关键词：动态规划 
*/
#include<iostream>
using namespace std;

int main()
{    
    int n;
    cin>>n;
    
    int sum=(1+n)*n/2;
    int count[40][1000]={0};
    count[1][1]=1;
    
    for(int i=2;i<=n;i++)
        for(int j=1;j<=(1+i)*i/2;j++)
            count[i][j]=count[i-1][j]+count[i-1][max(0,j-i)];

    if(sum%2!=0)cout<<0;
    else cout<<count[n][sum/2];
   
    //while(1);
}
