/*
求无权无向图的最短路径

邻接矩阵存储，宽度优先搜索

关键词：简单题，图论，广度优先搜索 
*/
#include<iostream>
#include<queue>
using namespace std;

struct Info
{
    int node;
    int length;
    Info(int a=0,int b=0):node(a),length(b){}
};

int main()
{
    int n,m;
    while(cin>>n>>m)
    {
        int a,b;
        bool map[101][101]={0};
        bool used[101]={0};
        queue<Info> q;
        
        for(int i=0;i<m;i++)
        {
            cin>>a>>b;
            map[a][b]=true;
            map[b][a]=true;
        }
        cin>>a>>b;
        if(a==b)
        {
            cout<<0<<endl;
            goto end;
        }
        
        q.push(Info(a,0));
        used[a]=true;
        
        while(q.empty()==false)
        {
            for(int i=1;i<=n;i++)
            {
                if(map[q.front().node][i]==true && used[i]==false)
                {
                    q.push(Info(i,q.front().length+1));
                    used[i]=true;
                    if(i==b)
                    {
                        cout<<q.back().length<<endl;
                        goto end;
                    }
                }
            }
            q.pop();
        }
        
        cout<<-1<<endl;
        end:;
    }
}
