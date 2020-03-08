/*
最普通的求最小生成树问题

节点较少，选用Prim算法

关键词：图论，最小生成树
*/
#include<iostream>
using namespace std;

const int MAX=1000000000;

int main()
{
    int N;
    cin>>N;
    
    int map[100][100];
    for(int i=0;i<N;i++)
        for(int j=0;j<N;j++)
            cin>>map[i][j];
            
    int result=0;        
    bool use[100]={false};
    int distance[100]={0};
    for(int i=1;i<N;i++)
        distance[i]=MAX;
    
    for(int i=0;i<N;i++)
    {
        int min=MAX,x;
        for(int j=0;j<N;j++)
            if(use[j]==false && distance[j]<min)
            {
                min=distance[j];
                x=j;
            }
        result+=min;
        use[x]=true;
        for(int j=0;j<N;j++)
            if(use[j]==false && map[x][j]<distance[j])
                distance[j]=map[x][j];
    }//Prim 
    
    cout<<result<<endl;
}
