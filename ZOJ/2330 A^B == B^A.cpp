/*
输入实数a>=1.1，求满足a^b==b^a的b值，且b>a。输出保持五位小数，若不存在b则输出-1

对等式取对数得b*ln(a)=a*ln(b)，即ln(a)/a=ln(b)/b
设f(x)=ln(x)/x，x=e为f(x)极大值，所以a的范围是[1.1,e)
因为f(44)<f(1.1)<f(43)，所以b的范围是(e,44)
二分法就可以求出b的值
 
关键词：数学题，二分法 
*/
#include<iostream>
#include<cmath>
#define E 2.7182818284590452354
using namespace std;

double f(double x)
{
    return log(x)/x;
}

int main()
{
    double a,b;
    double max,min;
    
    while(cin>>a)
    {
        if(a==0)break;
        if(a>=E){cout<<-1<<endl;continue;}
        
        min=E;max=44;
        
        do
        {
            b=(min+max)/2;
            if(f(b)>f(a))min=b;
                else max=b;
        }while(fabs(f(b)-f(a))>1e-14);
        
        printf("%.5f\n",b);
    }
    
    return 0;
}
