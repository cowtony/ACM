/*
打一个字母一秒钟，复制一段文本5秒，粘贴一段2秒，求要打长度为n的文本最短多少时间

一维动态规划
f[i]表示生成长度至少为i的文本的最少时间
通过本题允许的几种文本操作容易得到状态转移方程
状态转移方程一个是f[i]=f[i-1]+1
另一个就是从以前的一个状态不停粘贴到现在，取最小的 

关键词：动态规划 
*/
#include<iostream>
using namespace std;

int main()
{
    int f[10001]={0};
    
    for(int i=1;i<=10000;i++)
    {
        f[i]=f[i-1]+1;
        for(int j=1;j<i;j++)
        {
            int times;//把长度为j的文本粘贴times次 
            if(i%j==0)times=i/j-1;
            else times=i/j;//为了达到长度i需要粘贴的次数 
            f[i]=min(f[i],f[j]+times*2+5);//看是再打一个字符快还是从以前某个状态复制粘贴快 
        }
    }
    
    int t,n;
    cin>>t;
    while(t--)
    {
        cin>>n;
        cout<<f[n]<<endl;
    }
}
