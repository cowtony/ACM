/*
已知一些虫子的重量，两个虫子碰在一起形成一个新的虫子质量为2*sqrt(m1*m2)，求全碰完后的最少质量

2*sqrt(2*sqrt(2*sqrt(m1*m2)*m3)*m4)展开 
=2*sqrt(2*sqrt(2))*m1^(1/8)*m2^(1/8)*m3^(1/4))*m4^(1/2)
其中前面是系数，所以当m1到m4递减时结果最小 
读入数据，从最重的开始结合就可以了 

关键词：贪心 
*/
#include<iostream>
#include<algorithm>
#include<cmath>
#include<iomanip>
using namespace std;

int main()
{
    int n;
    while(cin>>n)
    {
        double weight[100];
        for(int i=0;i<n;i++)
            cin>>weight[i];
        
        sort(weight,weight+n);
        reverse(weight,weight+n);
        for(int i=0;i<n-1;i++)
            weight[i+1]=2*sqrt(weight[i]*weight[i+1]);
        
        cout.precision(3);
        cout<<fixed<<weight[n-1]<<endl;
    }
} 
