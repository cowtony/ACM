/*
一个图，每个节点上有一定的兵力，每破坏一条边要求用掉边两头节点的兵力和，要求该图不能有环，求所需的最小兵力

其实就是最小生成树，每条边的权为两头结点的和

关键词：图论，最小生成树 
*/
#include<iostream>
using namespace std;

int MST(int map[][100],int n)
{
    bool used[100]={true};
    int max_cost;
    int node;
    int total_cost=0;
    
    for(int cnt=1;cnt<n;cnt++)
    {
        node=-1;
        max_cost=0;
        for(int i=0;i<n;i++)if(used[i]==true)
        for(int j=0;j<n;j++)if(used[j]==false)
        {
            if((node==-1) || map[i][j]>max_cost)
            {
                max_cost=map[i][j];
                node=j;
            }
        }
        used[node]=true;
        total_cost+=max_cost;
    }
    return total_cost;
}

int main()
{
    //freopen("aaa.txt","r",stdin);
    
    int T;
    cin>>T;
    while(T--)
    {
        int m;
        cin>>m;
        
        int map[100][100]={0};
        int building[100];
        for(int i=0;i<m;i++)
        {
            int num;
            cin>>num;
            cin>>building[num];
            int c;
            cin>>c;
            for(int j=0;j<c;j++)
            {
                int t;
                cin>>t;
                map[num][t]=map[t][num]=1;
            }
        }
        
        int total=0;
        for(int i=0;i<m;i++)
            for(int j=0;j<m;j++)
                if(map[i][j]==1)
                {
                    map[i][j]=building[i]+building[j];
                    total+=map[i][j];
                }
        total/=2;

        cout<<total-MST(map,m)<<endl;
    }
    //while(1);
}
