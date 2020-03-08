/*
输入n，输出sum[0.5/x] x=1 to n

输出格式很严

关键词：简单题
*/
#include <iostream>
using namespace std;

int main()
{
    int n,i,m,t;
    double sum;
 
    cout<<"# Cards  Overhang\n";
 
    while(cin>>n)
    {
        sum=0;
        
        for(i=1;i<=n;i++)
            sum+=0.5/i;
   
        printf("%5d     %.3f\n",n,sum);
    }

    return 0;
}
