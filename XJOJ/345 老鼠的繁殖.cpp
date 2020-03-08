/*
求最少耗费连通所有的老鼠据点。点与点之间只走直线，路上还会穿过石头

先建立一个带权无向图，利用计算几何方法求图上两点之间的耗费
然后利用Prim算法计算最小生成树

关键词：计算几何，图论，最小生成树 
*/
#include<iostream> 
#include<cmath>
using namespace std; 

struct Point
{
    double x,y;
    Point(double a=0,double b=0):x(a),y(b){}
    Point operator -(Point p){return Point(x-p.x,y-p.y);}
};

double Distance(Point a,Point b)
{return sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));}//求两点间距

double Determinant(Point a,Point b)
{return a.x*b.y-b.x*a.y;}//求行列式

double Inner_product(Point a,Point b)
{return a.x*b.x+a.y*b.y;}//求向量内积 

bool cross(Point a,Point b,Point rock,double r)
{
    if(fabs(Determinant(rock-a,rock-b))/Distance(a,b)>=r)return false;//石头到直线的距离 
    if(Inner_product(rock-a,b-a)<=0)return false; 
    if(Inner_product(rock-b,a-b)<=0)return false;//判断圆心投影是否在线段上 
    return true;
}//判断线段是否经过岩石 

double MST(double map[][100],int n)
{
    bool used[100]={true};
    double min_cost;
    int node;
    
    double total_cost=0;
    for(int cnt=1;cnt<n;cnt++) 
    {   
        node=-1;
        for(int i=0;i<n;i++)if(used[i]==true)
            for(int j=0;j<n;j++)if(used[j]==false)
                if(node==-1||map[i][j]<min_cost)
                {
                    min_cost=map[i][j];
                    node=j;
                }
        used[node]=true;
        total_cost+=min_cost;
    }     
    return total_cost; 
}

int main() 
{
    int n,M;//洞的数量和石头的数量 
    double r;//石头的半径 
    Point cave[100];//存储洞的点
    Point rock[100];//存储石头的点 
    double map[100][100];//存储任意2点的消耗 

    cin>>n>>M>>r;
    for(int i=0;i<n;i++)
        cin>>cave[i].x>>cave[i].y;
    for(int i=0;i<M;i++)
        cin>>rock[i].x>>rock[i].y;
        
    for(int i=0;i<n;i++)
        for(int j=0;j<i;j++)
        {
            double p=Distance(cave[i],cave[j]);
            for(int k=0;k<M;k++)
                if(cross(cave[i],cave[j],rock[k],r)==true)p+=1;
            map[j][i]=map[i][j]=p;
        }

    printf("%.2f",MST(map,n));
    //while(1);
} 
