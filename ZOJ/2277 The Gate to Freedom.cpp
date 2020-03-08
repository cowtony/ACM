/*
输出n^n(n<1000000000)的第一位数

设a=n^n取10的对数，a=10^(n*log10(n))
取n*log10(n)的小数部分为j，整数部分为k
a=10^(j+k)=10^k*10^j
所以最左位就是int(10^j)

关键词：数学题，巧方法
*/
#include<iostream>
#include<cmath>
using namespace std;

int main()
{
    double j,k;
    long n;
    
    while(cin>>n)
    {
        j=n*log10(n);
        j-=int(j);
        k=pow10(j);
        cout<<int(k)<<endl;
    }
  
    return 0;
}