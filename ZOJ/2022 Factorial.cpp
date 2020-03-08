/*
求n!末尾有多少个零

有多少个零就有多少个因数10
也就有多少个2*5
因为因数2肯定多于因数5
所以有几个因数5就有几个零
首先肯定是每5个数一个因数5
所以至少有n/5个
但是像25，50这样的数一个数中有两个5
所以还要再加上n/25
以此类推
实现起来可以用以下方法

关键词：巧方法，数学题 
*/
#include<iostream>
using namespace std;

int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int n,total=0;
        scanf("%d",&n);
        while(n>0)
        {
            total+=n/5;
            n/=5;
        }
        printf("%d\n",total);
    }
}
