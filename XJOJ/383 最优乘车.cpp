/*
输入单向公交的路线图（途径的各个站点），问从1号站到N号站最少转几次车

根据公交线路建立一个有向无权图
每一站都可以直接到达他后面的所有站
然后宽搜即可
输入数据很麻烦，用cin.peek()会很方便

关键词：图论，宽度优先搜索 
*/
#include<iostream>
#include<queue>
using namespace std;

struct Node
{
    int node;
    int length;
    Node(int a=0,int b=0):node(a),length(b){}
};

int main()
{
    //freopen("aaa.txt","r",stdin);
    
    int M,N;
    cin>>M>>N;
    
    bool map[500][500];
    while(M--)
    {
        int bus[500];
        for (int i=0;;i++)
        {
            cin>>bus[i];
            for(int j=0;j<i;j++)
                map[bus[j]-1][bus[i]-1]=true;

            if (cin.peek()!=' ')break;
        }
    }

    queue<Node> q;
    q.push(Node(0,0));
    bool used[500]={false};
    used[0]=true;
    
    while(q.empty()==false)
    {
        int node=q.front().node;
        int length=q.front().length;
        q.pop();
        
        for(int i=0;i<N;i++)
        {
            if(used[i]==false && map[node][i]==true)
            {
                q.push(Node(i,length+1));
                used[i]=true;
                if(i==N-1)
                {
                    cout<<length<<endl;
                    return 0;
                }
            }
        }
    }
    cout<<"NO"<<endl;
}
