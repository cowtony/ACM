/*
ID:cowtony1
PROG:maze1
LANG:C++

读入一个地图，地图有两个出口，求能保证牛从迷宫中任意一点走出迷宫的最小步数。

先对地图做初始化，注意空格无法当做char读入，要用cin.get()
其次把墙的值设为0，可以走的地方设为MAXN
把两个出口的值设为1，表示一步就可以走出去
这样不考虑墙的话，每个点可以走出去的最小步数就是周围四个点的最小值加1，再与自己取最小值
如此不断循环计算，直到整个地图不再改进
遍历找出最大的数
输出它除以2的值，因为地图的定义问题 
此题宽搜也可以做 

关键词：宽度搜索 
*/
#include<iostream>
#include<fstream>
#include<queue>
using namespace std;

const int MAXN=10000000;

struct Point
{
    int x,y;
    Point(int a=0,int b=0):x(a),y(b){}
};

int main()
{
    freopen("maze1.in","r",stdin);
    freopen("maze1.out","w",stdout);
    
    int W,H;
    cin>>W>>H;
    
    int step[201][77];
    for(int i=0;i<2*H+1;i++)
    {
        cin.get();
        for(int j=0;j<2*W+1;j++)
            step[i][j]=cin.get()==' '?MAXN:0;
    }
    
    for(int i=0;i<2*H+1;i++)
    {
        if(step[i][0]==MAXN)step[i][0]=1;
        if(step[i][2*W]==MAXN)step[i][2*W]=1;
    }
    for(int j=0;j<2*W+1;j++)
    {
        if(step[0][j]==MAXN)step[0][j]=1;
        if(step[2*H][j]==MAXN)step[2*H][j]=1;
    }
    
    bool flag=true;
    while(flag==true)
    {
        flag=false;
        for(int i=1;i<2*H;i++)
            for(int j=1;j<2*W;j++)
            {
                int a=1000000;
                if(step[i][j+1]>0)a=min(a,step[i][j+1]);
                if(step[i][j-1]>0)a=min(a,step[i][j-1]);
                if(step[i+1][j]>0)a=min(a,step[i+1][j]);
                if(step[i-1][j]>0)a=min(a,step[i-1][j]);
                if(step[i][j]>a+1)
                {
                    step[i][j]=a+1;
                    flag=true;
                }
            }
    }
    
    int maxn=0;
    for(int i=0;i<2*H+1;i++)
        for(int j=0;j<2*W+1;j++)
            maxn=max(maxn,step[i][j]);
    
    cout<<maxn/2<<endl;
}
