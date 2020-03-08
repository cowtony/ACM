/*
输入自行车前轮直径(inch)，转的圈数，所用时间(s)，输出路程(mile)和速度(MPH) 

先转化单位，再计算

关键词：数学题，简单题 
*/
#include<iostream>
#define PI 3.1415927
using namespace std;

int main()
{
    double diameter;
    int revolutions;
    double time;
    int N=1;
    while(cin>>diameter>>revolutions>>time)
    {
        if(revolutions==0)break;
        
        diameter/=12*5280;
        time/=3600;
        double distance=PI*diameter*revolutions;
        double MPH=distance/time;
        
        printf("Trip #%d: %.2f %.2f\n",N++,distance,MPH);
    }
}
