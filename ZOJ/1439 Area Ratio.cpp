/*
给出三维坐标系中三角形顶点坐标，求该三角形内切圆与外接圆面积之比

a,b,c是三角形三边长，p为三角形周长的一半，s是三角形面积，r1是内接圆半径，r2是外接圆半径
p=(a+b+c)/2
s=sqrt(p*(p-a)*(p-b)*(p-c))
r1=2*s/(a+b+c)=s/p
r2=a*b*c/(4*s)

关键词：数学题
*/
#include<iostream>
#include<cmath>
using namespace std;

int main()
{
    double x1,y1,z1,x2,y2,z2,x3,y3,z3;
    double s,p,a,b,c,ratio,r1,r2;

    while(cin>>x1>>y1>>z1>>x2>>y2>>z2>>x3>>y3>>z3)
    {
        a=sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2)+(z1-z2)*(z1-z2));
        b=sqrt((x2-x3)*(x2-x3)+(y2-y3)*(y2-y3)+(z2-z3)*(z2-z3));
        c=sqrt((x3-x1)*(x3-x1)+(y3-y1)*(y3-y1)+(z3-z1)*(z3-z1));//计算三边长

        p=(a+b+c)/2;                       //周长一半
        s=sqrt(p*(p-a)*(p-b)*(p-c));       //三角形面积
        r1=s/p;                            //内切圆半径
        r2=a*b*c/(4.0*s);                  //外接圆半径
        ratio=r1/r2;                       //两圆半径比
        ratio*=ratio;                      //两圆面积比
        
        printf("%.3f\n",ratio);
    }  

    return 0;
}
