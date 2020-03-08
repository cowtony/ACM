/*
已知弱酸的酸度常数Ka=[H+]*[acid ions]/[acid]
其中[H+]是溶液中氢离子浓度，[acid ions]是溶液中酸根离子浓度，[acid]是未电离的酸浓度
还知道所给弱酸的摩尔数nole及弱酸分子的结构为H(m)[acid ions](n)，求pH值

设电离了x*mole的弱酸，则[H+]=x*mole*m
[acid ions]=x*mole*n
[acid]=(1-x)*mole
因为Ka=[H+]*[acid ions]/[acid] 
所以Ka=x*mole*m*x*n/(1-x)，即(m*n*mole)x^2+Ka*x-Ka=0
解此二元一次方程得：x=(sqrt(Ka^2+4*m*n*mole*Ka)-Ka)/(2*m*n*mole)
[H+]=(sqrt(Ka^2+4*m*n*mole*Ka)-Ka)/(2*n)
最后用公式pH=-log10[H+]求得pH值
题意很难搞懂，英语差。。

关键词：化学题 
*/
#include<iostream>
#include<cmath>
using namespace std;

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        double Ka,mole;
        int m,n;
        while(cin>>Ka>>mole>>m>>n)
        {
            if(Ka==0 && mole==0 && m==0 && n==0)break;
            
            double H=(sqrt(Ka*Ka+4*m*n*mole*Ka)-Ka)/(2*n);
            double pH=-log10(H);
            printf("%.3f\n",pH);
        }
        if(t>0)cout<<endl;
    }
}

