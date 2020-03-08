/*
读入一个迷宫，求从起点走到终点要穿过多少个房间

宽度优先搜索，穿过的房间数就是总最短路除以二
读入数据要注意，一行一行的读
回车符有可能是两个字符（\n \r）

关键词：宽度优先搜索，BFS 
*/
#include<iostream>
#include<queue>
using namespace std;

struct Node
{
    int x,y;
    Node(int a=0,int b=0):x(a),y(b){}
};


int main()
{
    //freopen("aaa.txt","r",stdin);
    
    int T;
    cin>>T;
    while(T--)
    {
        int N,M;
        cin>>N>>M;
        
        int map[300][300];
        Node start,end;
        for(int i=0;i<2*N+1;i++)
        {
            char s[300];
            cin.getline(s,300);
            for(int j=0;j<2*M+1;j++)
            {
                char c=cin.get();
                if(c==' ')map[i][j]=0;
                else if(c=='#')
                {
                    end.x=i;
                    end.y=j;
                    map[i][j]=1;
                }
                else if(c=='*')
                {
                    start.x=i;
                    start.y=j;
                    map[i][j]=0;
                }
                else map[i][j]=1;
            }
        }
       
        queue<Node> q;
        q.push(end);
        while(q.empty()!=true)
        {
            Node temp=q.front();
            int x=temp.x;
            int y=temp.y;
            q.pop();
            
            if(x<2*N+1)if(map[x+1][y]==0)
            {
                q.push(Node(x+1,y));
                map[x+1][y]=map[x][y]+1;
                if(x+1==start.x && y==start.y){cout<<map[x+1][y]/2<<endl;break;}
            }
            if(x>0)if(map[x-1][y]==0)
            {
                q.push(Node(x-1,y));
                map[x-1][y]=map[x][y]+1;
                if(x-1==start.x && y==start.y){cout<<map[x-1][y]/2<<endl;break;}
            }
            if(y<2*M+1)if(map[x][y+1]==0)
            {
                q.push(Node(x,y+1));
                map[x][y+1]=map[x][y]+1;
                if(x==start.x && y+1==start.y){cout<<map[x][y+1]/2<<endl;break;}
            }
            if(y>0)if(map[x][y-1]==0)
            {
                q.push(Node(x,y-1));
                map[x][y-1]=map[x][y]+1;
                if(x==start.x && y-1==start.y){cout<<map[x][y-1]/2<<endl;break;}
            }
        }
    }
    
    //while(1);
}
