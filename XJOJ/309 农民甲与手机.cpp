/*
给出多边形的各点，判断一个点是否在多边形内

两种方法，一种是从该点做一条射线，穿过多边形的几条边
偶数边说明在外部，奇数说明在内部

另一种方法是连接多边形的一点和该点
然后逐步挪向下一个点，如果在内部转一圈后扫过的角度为360
在外部则为0度
这道题用第二种方法变得

关键词：几何 
*/
#include<iostream>
#include<cmath>
using namespace std;

struct Point
{
    double x,y;
};

double Angle(Point A,Point O,Point B)
{
    double a=sqrt((O.x-B.x)*(O.x-B.x)+(O.y-B.y)*(O.y-B.y));
    double b=sqrt((O.x-A.x)*(O.x-A.x)+(O.y-A.y)*(O.y-A.y));
    double o=sqrt((A.x-B.x)*(A.x-B.x)+(A.y-B.y)*(A.y-B.y));
    double angle=acos((a*a+b*b-o*o)/(2*a*b));
    
    if((A.x-O.x)*(B.y-O.y)>(B.x-O.x)*(A.y-O.y))return angle;
    else return -angle;
}

int main()
{
    int T,n;
    Point point;
    cin>>T;
    
    while(T--)
    {
        cin>>n>>point.x>>point.y;
        
        Point start,p1,p2;
        double angle=0;
        cin>>start.x>>start.y;
        p1=start;
        for(int i=1;i<n;i++)
        {
            cin>>p2.x>>p2.y;
            angle+=Angle(p1,point,p2);
            p1=p2;
        }
        angle+=Angle(p1,point,start);

        if(fabs(angle)<1e-3)
            cout<<"No."<<endl;
        else cout<<"Yes!"<<endl;
    }
}
