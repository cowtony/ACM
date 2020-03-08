/*
给出n个整数，共可以组成a对2个整数组合，其中有b对互质，b/a近似为圆周率，根据所给数列求该近似值

a=n*(n+1)/2
穷举法求出互质的组合数b即可

关键词：数学题
*/
#include<iostream>
#include<cmath>
using namespace std;

int main()
{
    int n,s,m,a[50];
    int gcd(int n,int m);
    
    while(cin>>n,n!=0)
    {
        s=0;
        m=n*(n-1)/2;         //pai的分母
        
        for(int i=0;i<n;i++)
            cin>>a[i];
            
        for(int i=0;i<n-1;i++)
            for(int j=i+1;j<n;j++)
                if(gcd(a[i],a[j])==1)s++;      //pai的分子
    
        if(s>0)printf("%.6f\n",sqrt(6.0/double(s)*m));
            else cout<<"No estimate for this data set."<<endl;
    }
    
    return 0;
}

int gcd(int n,int m)       //求最大公约数的函数
{
    int r;
    while(m)
    {
        r=n%m;
        n=m;
        m=r;
    }
    return n;
}
