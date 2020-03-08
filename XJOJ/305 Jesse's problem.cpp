/*
基础带权图最短路径问题

Dijkstra算法，邻接矩阵存储

关键词：图论，最短路，动态规划 
*/
#include<iostream>
#define INF 2000000000
using namespace std;

int main()
{
    int n,m;
    while(cin>>n>>m)
    {
        int arcs[201][201];
        for(int i=1;i<=n;i++)
            for(int j=1;j<=n;j++)
                arcs[i][j]=INF;
        for(int i=0;i<m;i++)
        {
            int a,b,value;
            cin>>a>>b>>value;
            arcs[a][b]=value;
            arcs[b][a]=value;
        }
        int start,end;
        cin>>start>>end;//input
        
        int D[201];
        bool used[201]={false};
        used[start]=true;
        
        for(int i=1;i<=n;i++)
            D[i]=arcs[start][i];//init 
            
        for(int t=1;t<n;t++)
        {
            int min=INF,u;
            for(int i=1;i<=n;i++)
                if(used[i]==false && min>D[i])
                    {min=D[i];u=i;}
            
            used[u]=true;
            for(int i=1;i<=n;i++)
                if(used[i]==false && D[i]>min+arcs[u][i])
                    D[i]=min+arcs[u][i];
        }//core
        
        if(D[end]==INF)cout<<-1<<endl;
        else cout<<D[end]<<endl;//output
    }
}
