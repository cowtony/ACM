#include<iostream>
#include<stack>
using namespace std;

int N,K;
int map[11][11]={0};

struct Point
{
    int x;
    int y;
    Point(int a=0,int b=0)
    {
        x=a;
        y=b;
    }
    bool operator <=(Point p)
    {
        if(y==p.y)return x<=p.x;
        else return y<p.y;     
    }
    bool operator ==(Point p)
    {
        return x==p.x && y==p.y;     
    }
    Point operator +(int i)
    {
        Point temp;
        temp.x=x+i;
        temp.y=y;
        while(temp.x>=N)
        {
            temp.x-=N;
            temp.y++;
        }
        return temp;
    }
    Point next()
    {
        for(Point p=*this+1;p<=Point(N-1,N-1);p=p+1)
            if(map[p.y][p.x]==0)return p;
        return Point(-1,-1);
    }
};

void put(Point p)
{
    for(int i=p.y-1;i<=p.y+1;i++)
        for(int j=p.x-1;j<=p.x+1;j++)
            if(i>=0 && i<N && j>=0 && j<N)
                map[i][j]++;
}     
void move(Point p)
{
    for(int i=p.y-1;i<=p.y+1;i++)
        for(int j=p.x-1;j<=p.x+1;j++)
            if(i>=0 && i<N && j>=0 && j<N)
                map[i][j]--;
}

int main()
{
    cin>>N>>K;
    long long c=0;
    stack<Point> step;
        
    Point p(0,0);
    step.push(p);
    step.push(p);
    put(p);
        
    while(step.size()>0)
    {                            
        p=p.next();
        
        if(step.size()-1==K || p==Point(-1,-1))
        {
            if(step.size()-1==K)c++;
            p=step.top();
            step.pop();
            move(p);
        }
        else
        {
            step.push(p);
            put(p);
        }
    }
    cout<<c<<endl;
    //while(1);
}
