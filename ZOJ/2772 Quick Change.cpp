/*
输入一个钱数，输出用最少的硬币表示法。有25，10，5，1美分的硬币

从最大的硬币开始取余，就可以了

关键词：贪心，简单题 
*/
#include<iostream>
using namespace std;

int main()
{
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        int c;
        cin>>c;
        
        int quarter=c/25;
        c%=25;
        int dime=c/10;
        c%=10;
        int nickel=c/5;
        c%=5;
        int penny=c/1;
        
        printf("%d %d QUARTER(S), %d DIME(S), %d NICKEL(S), %d PENNY(S)\n",i,quarter,dime,nickel,penny);
    }
}
