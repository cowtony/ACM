/*
输入多边形的顶点坐标，输出多边形的面积

主要是计算多边形的算法，
在纸上画一画就理解了

关键词：几何 
*/
#include<iostream>
#include<cmath>
#include<iomanip>
using namespace std;

double area_of_polygon(int vcount,double x[],double y[])
{ 
    if(vcount<3)return 0; 
    
    double s=y[0]*(x[vcount-1]-x[1]);
    for(int i=1;i<vcount;i++)
        s+=y[i]*(x[(i-1)]-x[(i+1)%vcount]); 

    return fabs(s/2); 
}

int main()
{
    int T,n;
    cin>>T;
    double x[10000],y[10000];
    
    while(T--)
    {
        cin>>n;
        for(int i=0;i<n;i++)
            cin>>x[i]>>y[i];
        cout<<setiosflags(ios::fixed)<<setprecision(2)<<area_of_polygon(n,x,y)<<endl;
    }
}
