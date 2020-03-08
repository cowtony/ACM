/*
输入n个长度不同的棍子，让他们首尾相接有没有可能组成一个正方形

深度优先搜索来枚举排列方法
为了优化，把所有的棍子分成四组（因为正方形有四条边）
每一组内的棍子不考虑排列顺序，只考虑组合
DFS的第一个参数用来确保组内的棍子顺序始终为升序，这样就不会有多余的方案
第二个参数表示目前这条边已经有多长了
第三个参数表示目前拼到第几条边了
凑够三条边就可以成功结束了

关键词：深度优先搜索 
*/ 
#include<iostream>
#include<algorithm>
#include<cstring>
#include<cstdio>
using namespace std;

int M;
int stick[20];
bool used[20];
bool success;
int length;

void DFS(int p,int present,int part)
{
    if(part==3)success=true;
    if(success==true)return;
    
    for(int i=p;i<M;i++)
        if(used[i]==false && present+stick[i]<=length)
        {
            used[i]=true;
            if(present+stick[i]==length)DFS(0,0,part+1);
            else DFS(i+1,present+stick[i],part);
            used[i]=false;
        }
}

int main()
{
    //freopen("aaa.txt","r",stdin);
    
    int N;
    cin>>N;
    while(N--)
    {
        cin>>M;
        int sum=0;
        for(int i=0;i<M;i++)
        {
            cin>>stick[i];
            sum+=stick[i];
        }
        sort(stick,stick+M,greater<int>());//可以让搜索的树分支更少 
        if(sum%4!=0){cout<<"no"<<endl;continue;}
        length=sum/4;
        
        success=false;
        memset(used,false,sizeof(used));
        DFS(0,0,0);
        
        if(success==true)cout<<"yes"<<endl;
        else cout<<"no"<<endl;
    }
    
    //while(1);
}
