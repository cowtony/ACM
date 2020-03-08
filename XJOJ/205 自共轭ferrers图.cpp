/*
求关于n的自共轭ferrers图的个数

组合数学中整数拆分的问题
定理：自共轭ferrers图的个数和把n拆分成不相等的奇数的拆分数相同
证明：把自共轭ferrers图像剥洋葱一样一层一层剥开，就明白了 
所以就看n可以拆成多少组互不相等的奇数
f[a][b]表示把a拆成不大于b的奇数的拆分数
f[a][b]=sum(f[a-b][1],f[a-b][3]...f[a-b][k])其中k<b
初值是f[i][i]=1，其中i是奇数，就是说对于对于奇数i，他们可以构成层数为1的自共轭ferrers图
最后的答案就是sum(f[n][i])，其中i小于等于n 

关键词：动态规划，组合数学
*/
#include<iostream>
using namespace std;

int main()
{
    long long f[501][501]={0};
    
    for(int i=1;i<=500;i+=2)
        f[i][i]=1;
    
    for(int i=1;i<=500;i++)
        for(int j=1;j<i;j+=2)
            for(int k=1;k<j;k+=2)
                f[i][j]+=f[i-j][k];
    
    int n;
    cin>>n;

    long long sum=0;
    for(int j=0;j<=n;j++)
        sum+=f[n][j];
    if(sum==0)cout<<"NO ANSWER"<<endl;
    else cout<<sum<<endl;

    //while(1);
}
