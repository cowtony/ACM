/*
把一个分数表示成不同埃及分数的和，要求分数尽量少，且最大的分母尽可能的小

IDA*算法，迭代深度优先搜索
深度为埃及分数的个数，从1开始枚举最大深度进行深度优先搜索，直到该深度有解，此时找到该深度的最优解
由于涉及大量相乘，用int会溢出，导致某些结果不正确
用long long再加上约分会很慢很慢，所以此题存数据采用double，虽然比较危险但是没办法
还有为了节省时间和内存尽量不要再dfs里加参数，都用全局变量
搜索的时候从分母最小的分数开始，这样可以确定它的取值范围

关键词：迭代加深搜索，深度优先搜索，IDA 
*/
#include<iostream>
#include<cmath>
using namespace std;

int layer=0;
bool flag=false;
double a[10],b[10],best[10],result[10];

void dfs(int d)
{
    if(d==layer)
    {
        if(result[layer]<best[layer])
            memcpy(best,result,sizeof(best));
        flag=true;
        return;
    }
    
    int start=max(ceil(b[d]/a[d]),result[d]+1);//core 
    int end=(layer-d)*b[d]/a[d];//core 
    
    for(int i=start;i<=end;i++)
    {
        a[d+1]=a[d]*i-b[d];
        b[d+1]=b[d]*i;
        if(a[d+1]>=0)
        {
            result[d+1]=i;
            dfs(d+1);
        }
    }
}

int main()
{
    cin>>a[0]>>b[0];
    for(int i=0;i<10;i++)best[i]=1000000000;
    
    while(flag==false)
    {
        layer++;
        result[0]=0;
        dfs(0);
    }
            
    for(int i=1;i<layer;i++)
        cout<<int(best[i]+0.5)<<' ';
    cout<<int(best[layer]+0.5)<<endl;
}
