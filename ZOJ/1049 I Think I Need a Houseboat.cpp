/*
告诉你你的坐标，并且从原点开始呈半圆形每年腐蚀50平方英里，问多少年腐蚀到你

求腐蚀到你时共腐蚀的面积再除以五十就行了

关键词：简单题 
*/
#include<iostream>
#define pi 3.1415926535897932384626
using namespace std;

int main()
{
    int n;
    double x,y;
    double area;
    int year;
    
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>x>>y;
        area=pi*(x*x+y*y)/2;
        year=(area/50)+1;
        cout<<"Property "<<i<<": This property will begin eroding in year "<<year<<"."<<endl;
    }
    cout<<"END OF OUTPUT."<<endl;
    
    return 0;
} 
