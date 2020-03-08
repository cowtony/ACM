/*
求带权无向图的0号节点到N-1号节点的最短路 

直接Floyd算法就可以了，Dij算法写起来比较复杂，但更符合这个题意 

关键词：简单题，图论 
*/
#include<iostream>
using namespace std;

int main()
{
    //freopen("aaa.txt","r",stdin);
    
    int N,M;
    cin>>N>>M;
    int map[200][200];
    
    for(int i=0;i<N;i++)
        for(int j=0;j<N;j++)
        {
            map[i][j]=1000000000;
            if(i==j)map[i][j]=0;
        }
    
    for(int i=0;i<M;i++)
    {
        int a,b,d;
        cin>>a>>b>>d;
        map[a][b]=map[b][a]=d;
    }
    
    for(int k=0;k<N;k++)
        for(int i=0;i<N;i++)
            for(int j=0;j<N;j++)
                if(map[i][k]+map[k][j]<map[i][j])
                   map[i][j]=map[i][k]+map[k][j];
                   
    cout<<map[0][N-1]<<endl;
    //while(1);
}
