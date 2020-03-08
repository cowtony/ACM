/*
给出十二个实数，求平均数，精确到小数点后两位

没话说

关键词：简单题
*/
#include <iostream>
using namespace std;

int main()
{
     double sum=0,b;
     
     for(int i=0;i<12;i++)
     {
          cin>>b;
          sum+=b;
     }

     printf("$%.2f",sum/12);

     return 0;
}
