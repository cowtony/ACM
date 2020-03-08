/*
已知圆的半径，燃料数量以及出发点与目的地的角度，求能否往返一次。一加仑5mile

模拟直接做
注意角度大于180的情况
以及double和int的转化

关键词：简单题 
*/
#include<iostream>
#include<string>
#define PI 3.14159
using namespace std;

int main()
{
    string s;
    while(cin>>s)
    {
        if(s=="END")continue;
        if(s=="ENDOFINPUT")break;
        
        int r,fuel,angle;
        cin>>r>>fuel>>angle;
        
        if(angle>180)angle=360-angle;
        double need=2*(2*PI*r)*(angle/360.0)/5.0;
        
        if(fuel>=need)cout<<"YES "<<int(double(fuel)-need)<<endl;
        else cout<<"NO "<<5*fuel<<endl;
    }
}
