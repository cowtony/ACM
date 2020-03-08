/*
打地鼠，看原题

一维动态规划的题
time[i]代表第i的地鼠的出现时间，题中数据已保证time[i]是升序
mice[i][2]表示第i个地鼠的出现坐标
robot[i]表示当打到第i个地鼠时，最多打了几个地鼠
状态转移方程：
遍历robot[i]以前的地鼠，如果mice[i-t]在time[i]-time[i-t]时间内可以走到mice[i]
那么找出最大的robot[i-t]的值
robot[i]=robot[i-t]+1

关键词：一维动态规划 
*/
#include<iostream>
#include<cmath>
using namespace std;

int main()
{
    //freopen("aaa.txt","r",stdin);
    
    int mice[10000][2];
    int time[10000];
    int robot[10000]={0};
    
    int n,m;
    scanf("%d %d",&n,&m);
    for(int i=0;i<m;i++)
        scanf("%d %d %d",time+i,mice[i],mice[i]+1);
        
    for(int i=0;i<m;i++)
    {
        int max=0;
        for(int j=0;j<i;j++)
            if(time[i]-time[j]>=abs(mice[i][0]-mice[j][0])+abs(mice[i][1]-mice[j][1]))
                if(max<robot[j])max=robot[j];
        robot[i]=max+1;
    }
    
    int max=0;
    for(int i=0;i<m;i++)
        if(max<robot[i])max=robot[i];
        
    printf("%d",max);
    
    //while(1);
}
