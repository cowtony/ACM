/*
14C（碳14）的半衰期是5730年，每克每小时吸收810个单位的放射物，给出一个物质的放射物含量，求它的年龄

year=log(1/2,x/810)*5730，其中1/2是底数，x是现在的放射物含量，化简就是：year=log(810*w/d)/log(2)*5730。这道题对输出的数据还有一点要求

关键词：简单题
*/
#include<iostream> 
#include<cmath> 
using namespace std;

int main()
{ 
    double w,d;
    int count=1,year;
    
    while(cin>>w>>d,w!=0)
    { 
        year=log10(810*w/d)/log10(2)*5730;   //套公式计算即可
        
        if (year<10000)year=(year+50)/100*100; 
                  else year=(year+500)/1000*1000;  //对输出数据的“四舍五入”
            
        printf("Sample #%d\nThe approximate age is %d years.\n\n",count++,year);
    }
    
    return 0; 
}
