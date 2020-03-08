/*
求n！有几位数

n!的位数即log10(n!)+1
化简得sum[log10(x)]+1 x=1 to n
然后用for循环算

关键词：数学题，巧方法
*/
#include<iostream>
#include<cmath>
using namespace std;

int main()
{
    int n,a;
    double t;
    //freopen("aaa.txt","r",stdin);
    cin>>n;

    while(cin>>a)
    {
        t=0;
        for(int i=1;i<=a;i++)
            t+=log10(double(i));
        cout<<int(t)+1<<endl;
    }


    //while(1);  
    return 0;
}

