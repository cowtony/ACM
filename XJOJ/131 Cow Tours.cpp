/*
输入n个节点的坐标，以及一个矩阵表示他们之间连边的关系。这些节点组成至少两个连通分量
求一条连通两分量的边使得新形成的连通分量直径尽可能小，求该最小直径

先读入数据，地图中map[i][j]表示i节点到j节点的距离，无穷大表示没有边相连
然后用floyd三重循环算出在同一连通分量却没有直接边相连的距离
然后mmax[i]表示i节点所在连通分量的周长
遍历所有不处于同一连通分量的两节点，找到最小直径
最后一个循环没看懂

关键词：图论 
*/
#include<iostream>
#include<fstream>
#include<cmath>
using namespace std;

const double MAXN=1e20;
double distance(double x1,double y1,double x2,double y2)
{
    return sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
}

int main()
{
    int n;
    cin>>n;
    int x[150],y[150];
    for(int i=0;i<n;i++)
        cin>>x[i]>>y[i];
        
    double map[150][150];    
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
        {
            char c;
            cin>>c;
            if(c=='1')map[i][j]=distance(x[i],y[i],x[j],y[j]);
            else map[i][j]=MAXN;
            if(i==j)map[i][j]=0;
        }

    for(int k=0;k<n;k++)
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
                map[i][j]=min(map[i][j],map[i][k]+map[k][j]);

    double mmax[150]={0};
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            if(map[i][j]!=MAXN)
                mmax[i]=max(mmax[i],map[i][j]);
                
    double result=MAXN;
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            if(map[i][j]==MAXN)
                result=min(result,distance(x[i],y[i],x[j],y[j])+mmax[i]+mmax[j]);
            
    for(int i=0;i<n;i++)
        result=max(result,mmax[i]);
        
    printf("%.6f\n",result);
}
