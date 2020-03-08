/*
ID:cowtony1
PROG:stamps
LANG:C++

信封上最多可以贴K<=200张邮票，共有N种面值的邮票，问可以贴出1到多少面值？

动态规划，f[i]表示贴出面值为i最少需要多少张邮票
状态转移方程就是f[i]=min{f[i-value[j]]}+1
意义是面值为i-value[j]的方案再贴上一张面值为value[j]的邮票
最后输出得到的第一个超过K的数减1

关键词：动态规划，背包 
*/
#include<iostream>
#include<algorithm>
#include<fstream>
using namespace std;

int f[2000001];

int main()
{
    freopen("stamps.in","r",stdin);
    freopen("stamps.out","w",stdout);
    
    int K,N;
    cin>>K>>N;
    
    int value[50];
    for(int i=0;i<N;i++)
        cin>>value[i];
        
    sort(value,value+N);
    
    f[0]=0;
    for(int i=1;i<=K*value[N-1];i++)
    {
        int min=99999999;
        for(int j=0;j<N && i-value[j]>=0;j++)
            if(min>f[i-value[j]])min=f[i-value[j]];
        f[i]=min+1;
        
        if(f[i]>K)
        {
            cout<<i-1<<endl;
            return 0;
        }
    }
    cout<<K*value[N-1]<<endl;
}
