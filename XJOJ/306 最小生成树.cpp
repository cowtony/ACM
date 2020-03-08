/*
最基本的无向图最小生成树问题

Prim算法，邻接矩阵存储

关键词：图论，最小生成树 
*/
#include<iostream>
#include<set>
#define MAX 999999
using namespace std;

struct Edge
{
    int node,cost;
    Edge(int x=1,int y=MAX):node(x),cost(y){}
};

int main()
{
    int n,m;
    while(cin>>n>>m)
    {
        int map[101][101];
        for(int i=1;i<=n;i++)
            for(int j=1;j<=n;j++)
                map[i][j]=MAX;
        
        int total_cost=0;
        for(int i=0;i<m;i++)
        {
            int a,b,value;
            cin>>a>>b>>value;
            map[a][b]=value;
            map[b][a]=value;
            total_cost+=value;
        }

        set<int> remain;
        for(int i=2;i<=n;i++)
            remain.insert(i);
        Edge closedge[101];
        for(int i=2;i<=n;i++)
            closedge[i]=Edge(1,map[1][i]);
        
        while(remain.size()>0)
        {
            int min_cost=MAX,node=0;
            for(set<int>::iterator r=remain.begin();r!=remain.end();r++)
                if(min_cost>closedge[*r].cost)
                    {node=*r;min_cost=closedge[node].cost;}
                
            for(set<int>::iterator r=remain.begin();r!=remain.end();r++)
                if(map[node][*r]<closedge[*r].cost)
                    closedge[*r]=Edge(node,map[node][*r]);
                
            remain.erase(node);
            total_cost-=min_cost;
        }
        cout<<total_cost<<endl;
    }
}
