/*
0-99个频道的电视机遥控器，上面坏了一些键。现在求从一个频道到另一个频道最少要按多少下

建立一个100个节点的有向图，根据按键好坏的信息初始化它，节点与节点之间表示最短路径
然后用Floyd算法计算所有频道与频道之间的最短路径

关键词：图论，最短路径 
*/
#include<iostream>
#define INF 1000000000
using namespace std;

int main()
{
    int g[100][100];
    
    bool num[10],up,down,dash;
    cin>>num[1]>>num[2]>>num[3]>>up;
    cin>>num[4]>>num[5]>>num[6]>>down;
    cin>>num[7]>>num[8]>>num[9];
    cin>>dash>>num[0];
    
    int x,y;
    cin>>x>>y;
    
    for(int i=0;i<100;i++)
        for(int j=0;j<100;j++) 
            g[i][j]=INF;
    //初始化 
    for(int i=0;i<=9;i++)
        if(num[i]==true)
            for(int j=0;j<100;j++)g[j][i]=1;
    //一位数频道
    if(dash==true)
        for(int i=0;i<=9;i++)
            for(int j=0;j<=9;j++)
                if(num[i]==true && num[j]==true)
                    for(int k=0;k<100;k++)g[k][i*10+j]=3;
    //两位数的频道
    if(up==true)
        for(int i=0;i<100;i++)g[i][(i+1)%100]=1;
    if(down==true)
        for(int i=0;i<100;i++)g[i][(i+99)%100]=1;
    //上下键
    for(int i=0;i<100;i++)g[i][i]=0;
    //自己到自己的路径 
    for(int k=0;k<100;k++)
      for(int i=0;i<100;i++)
        for(int j=0;j<100;j++)
            g[i][j]=min(g[i][j],g[i][k]+g[k][j]);
    //求最短路径 
    if(g[x][y]==INF)cout<<-1<<endl;
    else cout<<g[x][y]<<endl;
}
