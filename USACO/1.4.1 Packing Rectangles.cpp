/*
ID:cowtony1
PROG:packrec
LANG:C++
四个矩形不重叠放到一个大矩形里，求大矩形的最小面积及所有可能的长宽 

利用两个深度优先搜索枚举出四个矩形所有的排列和转向（一个矩形可以竖着也可以横着）
生成了一个特定排列以后带入五种模式计算，这五种模式在题上已经画出来了
用set记录后输出就可以了，爆恶心的枚举 

关键词：枚举，深度优先搜索 
*/
#include<iostream>
#include<fstream>
#include<set>
using namespace std;

struct Rectangle
{
    int x,y;
    bool operator <(const Rectangle r)const
    {
        if(x*y!=r.x*r.y)return x*y<r.x*r.y;
        else if(min(x,y)!=min(r.x,r.y))return min(x,y)<min(r.x,r.y);
        else return max(x,y)<max(r.x,r.y);
    }
    Rectangle swap()
    {
        Rectangle r;
        r.x=y;
        r.y=x;
        return r;
    }
}result[4],f[4],A[4];



int fmax(int a,int b=0,int c=0,int d=0)
{
    return max(max(a,b),max(c,d));
}

set<Rectangle> s;
void solve()
{
    Rectangle r;
    r.x=f[0].x+f[1].x+f[2].x+f[3].x;
    r.y=fmax(f[0].y,f[1].y,f[2].y,f[3].y);
    if(r.x>r.y)r=r.swap();
    s.insert(r);
    
    r.x=fmax(f[0].x,f[1].x+f[2].x+f[3].x);
    r.y=f[0].y+fmax(f[1].y,f[2].y,f[3].y);
    if(r.x>r.y)r=r.swap();
    s.insert(r);
    
    r.x=f[0].x+max(f[1].x,f[2].x+f[3].x);
    r.y=max(f[0].y,f[1].y+max(f[2].y,f[3].y));
    if(r.x>r.y)r=r.swap();
    s.insert(r);
    
    r.x=max(f[0].x,f[1].x)+f[2].x+f[3].x;
    r.y=fmax(f[0].y+f[1].y,f[2].y,f[3].y);
    if(r.x>r.y)r=r.swap();
    s.insert(r);
    
    r.x=f[0].x+f[1].x;
	r.y=max(f[0].y+f[2].y,f[1].y+f[3].y);
	if(f[0].y<f[1].y)r.x=max(r.x,f[2].x+f[1].x);
	if(f[0].y+f[2].y>f[1].y)r.x=max(r.x,f[2].x+f[3].x);
	if(f[1].y<f[0].y)r.x=max(r.x,f[0].x+f[3].x);
	r.x=max(r.x,f[2].x);
	r.x=max(r.x,f[3].x);
	if(r.x>r.y)r=r.swap();
    s.insert(r);
}

void DFS_2(int depth)
{
    if(depth==4){solve();return;}
    f[depth]=result[depth];
    DFS_2(depth+1);
    f[depth]=result[depth].swap();
    DFS_2(depth+1);
}

bool used[4];
void DFS(int depth)
{
    if(depth==4)DFS_2(0);
    else for(int i=0;i<4;i++)
        if(used[i]==false)
        {
            result[depth]=A[i];
            used[i]=true;
            DFS(depth+1);
            used[i]=false;
        }
}

int main()
{
    freopen("packrec.in","r",stdin);
    freopen("packrec.out","w",stdout);

    for(int i=0;i<4;i++)
        cin>>A[i].x>>A[i].y;
        
    DFS(0);

    int area=(*s.begin()).x*(*s.begin()).y;
    cout<<area<<endl;
    for(set<Rectangle>::iterator it=s.begin();it!=s.end();it++)
    {
        if((*it).x*(*it).y==area)cout<<(*it).x<<' '<<(*it).y<<endl;
        else break;
    }
}
