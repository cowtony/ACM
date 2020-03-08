#include<iostream>
#include<vector>
#include<queue>
#include<stack>
using namespace std;

struct Overtake
{
    int car1;
    int car2;
    double time;
    double distance;
    bool operator <(const Overtake &i)const
    {
        if(time==i.time)return distance<i.distance;
        else return time<i.time;
    }
    Overtake(int i,int x1,int v1,int j,int x2,int v2)
    {
        car1=i;
        car2=j;
        time=double(x1-x2)/(v2-v1);
        distance=x1+v1*time;
    }
};

struct Info
{
    int ID;
    int start;
    Info(int a,int b)
    {
        ID=a;
        start=b;
    }
};

int main()
{
    int n,x,v;
    priority_queue<Overtake> pq;
    
    scanf("%d",&n);
    vector<Info> set_off[100];//表示车速为i的出发点列表 
    for(int i=0;i<n;i++)
    {
        scanf("%d %d",&x,&v);
        for(int j=v+1;j<100;j++)
        {
            for(vector<Info>::iterator it=set_off[j].begin();it!=set_off[j].end();it++)
            {
                pq.push(Overtake((*it).ID,(*it).start,j,i,x,v));
                if(pq.size()>10000)pq.pop();
            }
        }
        set_off[v].push_back(Info(i,x));
    }
    
    stack<Overtake> s;
    while(pq.empty()==false)
    {
        s.push(pq.top());
        pq.pop();
    }
        
    
    
    while(s.empty()==false)
    {
        Overtake temp=s.top();
        printf("%d %d\n",temp.car1+1,temp.car2+1);
        s.pop();
    }
        
    //while(1);
}
