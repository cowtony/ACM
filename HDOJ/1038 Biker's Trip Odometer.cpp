/*
已知轮子的直径和转的圈数及时间，求走的路程和平均速度

简单的模拟题，还有单位转换 

关键词：简单题 
*/
#include<iostream>
using namespace std;

const double PI=3.1415927;

int main()
{
    int cases=0;
    double diameter,time;
    int revolution;
    while(cin>>diameter>>revolution>>time && revolution!=0)
    {
	    double distance=diameter*PI*revolution/12/5280;
	    double average_speed=distance/(time/3600);
	    printf("Trip #%d: %.2lf %.2lf\n",++cases,distance,average_speed);
	}
}
