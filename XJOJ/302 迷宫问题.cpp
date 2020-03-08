/*
求迷宫的最短路

动态规划，time[i][j]表示从起点走到[i][j]的最少步数
time的初值全为无穷大，只有起点是零
然后一点一点往开找，具体看代码就能明白

关键词：动态规划，迷宫，广度优先搜索 
*/
#include<iostream>
#define INF 100000
using namespace std;

int main()
{
    //freopen("aaa.txt","r",stdin);
    
    int n;
    while(cin>>n)
    {
        char map[100][100];
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
                cin>>map[i][j];
    
        int start[2],end[2];
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
            {
                if(map[i][j]=='S')
                {
                    map[i][j]='.';
                    start[0]=i;
                    start[1]=j;
                }
                if(map[i][j]=='E')
                {
                map[i][j]='.';
                end[0]=i;
                end[1]=j;
                }
            }
        
        int time[100][100];
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
                time[i][j]=INF;
        time[start[0]][start[1]]=0;
    
        int di[4]={0,0,1,-1};
        int dj[4]={1,-1,0,0};
    
        bool flag=true;
        while(flag==true)
        {
            flag=false;
        
            for(int i=0;i<n;i++)
                for(int j=0;j<n;j++)
                    if(map[i][j]=='.' && time[i][j]<INF)
                    {
                        for(int d=0;d<4;d++)
                        {
                            int x=i+di[d];
                            int y=j+dj[d];
                            if(x<n && x>=0 && y<n && y>=0 && map[x][y]=='.')
                                if(time[x][y]>time[i][j]+1)
                                {
                                    time[x][y]=time[i][j]+1;
                                    flag=true;
                                }
                        }
                    }
        }
        if(time[end[0]][end[1]]==INF)cout<<-1<<endl;
        else cout<<time[end[0]][end[1]]<<endl;
    }
    
    //while(1);
}
