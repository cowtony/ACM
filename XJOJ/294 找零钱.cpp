/*
有100,50,20,10,5,1,0.5,0.1元钱无限张，输入钱数，输出最少组成的张数

题很简单，但是由于系统原因对于浮点数的判断会很奇怪
比如让整型的i=10*16.4，会得到i=163
再比如t=0.4，t==0.4会得到false，所以这道题对小数采取四舍五入，即再加五分钱

关键词：简单题 
*/
#include<iostream>
using namespace std;

int main()
{
    double y;
    double money[]={100,50,20,10,5,1,0.5,0.1};//以一角钱为单位 
    int count;
    
    while(cin>>y)
    {
        count=0;
        y+=0.05;//没有这一步的话下面的判断有可能出现(0.1>=0.1)=false的现象 
        
        for(int i=0;i<8;i++)
            while(y>=money[i])
            {
                count++;
                y-=money[i];
            }

        cout<<count<<endl;
    }
    return 0;
}
