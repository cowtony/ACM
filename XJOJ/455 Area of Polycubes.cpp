/*
有一种立体，它是由一个cube的基础上一块一块粘上去的，所以新增的一块必须和以前的立体有面的接触
求最后立体的表面积

直接模拟做，用数组存下每一块的位置
除了第一块，每一块都应该至少和前面的某一块相邻
判断相邻是abs(point[j][0]-point[k][0])+abs(point[j][1]-point[k][1])+abs(point[j][2]-point[k][2])==1
计算表面积是每增加一块表面积加6
但是每多一个接触面，表面积减2

注意！！不知道为什么要先读入数据，然后sort一下才能过。。。恶心得很，还是我没理解对题的意思 

关键词：几何，模拟 
*/
#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;

struct Point
{
     int x,y,z;
     int number;
     
     friend istream& operator >>(istream& input,Point& p)
     {
         scanf("%d,%d,%d",&p.x,&p.y,&p.z);
         return input;
     }
     bool operator <(const Point p)const
     {
         if(x==p.x && y==p.y) return z<p.z;
         else if(x==p.x) return y<p.y;
         return x<p.x;
     }
};

int main()
{
    //freopen("aaa.txt","r",stdin);
    
    int T;
    cin>>T;
    for(int t=1;t<=T;t++)
    {
        int p;
        cin>>p;
        Point a[102];
        
        for(int i=0;i<p;i++)
        {
            cin>>a[i];
            a[i].number=i+1;
        }
        sort(a,a+p);
        
        int surface=6*p;
        for(int i=1;i<p;i++)
        {
            bool flag=false;
            for(int j=0;j<i;++j)
                if(abs(a[i].x-a[j].x)+abs(a[i].y-a[j].y)+abs(a[i].z-a[j].z)==1)
                {
                    flag=true;
                    surface-=2;
                }
            if(flag==false)
            {
                cout<<t<<" NO "<<a[i].number<<endl;
                goto end;
            }
        }
        cout<<t<<" "<<surface<<endl;
        end:;
    }
    //while(1);
}
