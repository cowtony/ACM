/*
当x从0.000到2.000时输出2001个fai(x)=sum[1/(k*(k+x))]的值,k从1到正无穷
精确到小数点后十二位

fai(1)=sum[1/(k*(k+1))]=sum[1/k-1/(k+1)]=1
fai(x)-fai(1)=sum[1/(k*(k+x))-1/(k*(k+1))]=(1-x)*sum[1/(k*(k+x)*(k+1))]
对于fai(x)-fai(1)，前MAX项用求和公式累加，后无穷项利用微积分：
sum[1/(k*(k+x)*(k+1))]<inf[1/k^3]=1/(2*MAX*MAX)      k=MAX to 正无穷 

关键词：数学
*/
#include <iostream>
#define MAX 10000                         //k为1至MAX用单项算，MAX以后用微积分计算，误差较小
using namespace std;

int main( )
{
    double sum;
  
    for (double x=0;x<=2.000;x+=0.001)   //2001个x的值 
    {
        sum=0;
        
        for(int k=1;k<MAX;k++)               
            sum+=1/(k*(k+1)*(k+x));      //求出sum[1/(k*(k+x)*(k+1))]   k=1 to MAX 
            
        sum*=1-x;                        //求出fai(x)-fai(1)            k=1 to MAX
        sum+=(1-x)/(2*MAX*MAX)+1;        //加上MAX以后的余项（微积分计算），再加fai(1)            
                                       
        printf("%5.3f %16.12f\n",x,sum);
    }

    return 0;
} 
