/*
输入一堆板的坐标和一堆雨滴的坐标，求每个雨滴最终落到x轴上的位置

用类做方便一些
就是先找到雨滴目前最先碰到哪块板
然后把雨滴的坐标改为这块板上最低的坐标
重复操作直到找不到雨滴最先碰到的板为止
需要注意的是如果雨滴从一块板的最高点位置落下，则算为碰到这块板
但如果从最低点的x位置落下则不能算为碰到这块板，否则会在此处死循环

关键词：模拟，几何 
*/
#include<iostream>
using namespace std;

struct Point
{
    int x,y;
};

class Drop
{
    Point one,two;
public:
    void input()
    {
        cin>>one.x>>one.y>>two.x>>two.y;
        if(one.x>two.x)
        {
            Point temp=one;
            one=two;
            two=temp;
        }
    }
    double getY(Point p)
    {
        if(p.x<one.x || p.x>two.x)return 0;
        Point min=one.y>two.y?two:one;//min为板上较低的那个端点 
        if(p.x==min.x)return 0;

        double t=(p.x-one.x)*(two.y-one.y)/double(two.x-one.x)+one.y;
        if(p.y<t)return 0;
        else return t;
    }
    Point drop(Point p)
    {
        if(one.y>two.y)return two;
        else return one;
    }
    
};

Drop getMax(Point p,Drop b[],int n)
{
    double max=0;
    int num=0;
    for(int i=0;i<n;i++)
    {
        if(b[i].getY(p)>max)
        {
            max=b[i].getY(p);
            num=i;
        }
    }
    return b[num];
}

int main()
{
    int n;
    Drop broad[100];
    cin>>n;
    
    for(int i=0;i<n;i++)
        broad[i].input();
    
    int m;
    cin>>m;
    while(m--)
    {
        Point p;
        cin>>p.x>>p.y;
        
        while(1)
        {
            Drop t=getMax(p,broad,n);
            if(t.getY(p)>0)
                p=t.drop(p);
            else break;
        }
        cout<<p.x<<endl;
    }
    
    //while(1);
}
