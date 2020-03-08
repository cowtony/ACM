/*
看原题图上，已知D和咬掉的体积V，求d 

V=总圆柱体积-两个圆台体积-中间小圆柱体积
总圆柱体积:pi*(D/2)^2*D
中间小圆柱体积: pi*(d/2)^2*d
圆台体积=大椎体-小椎体
大椎体:(1/6)*总圆柱体积
小椎体:(1/6)*中间小圆柱体积
V=pi/6*(D^3-d^3)
d=(D^3-6V/pi)^(1/3)

关键词：数学题，简单题 
*/
#include<iostream>
#include<iomanip>
#include<cmath>
#define PI 3.1415926535
using namespace std;

int main()
{
    double D,V,d;
    while(cin>>D>>V)
    {
        if(D==0 && V==0)break;
        
        d=pow((D*D*D-6*V/PI),1/3.0);
        cout.precision(3);
        cout<<fixed<<d<<endl;
    }
}
