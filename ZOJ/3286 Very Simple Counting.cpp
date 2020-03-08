/*
定义f(x)为x因数的个数，f(1)=1,f(2)=2,f(3)=2,f(4)=3。要求输入1<n<=1000000，输出所有n以内因数个数与n相同的数的个数

定义factor数组来存下每个数字的因数个数（筛法）
再用a数组来存每个“个数”出现是第几次
因为1000000内因数个数最大值为240，所以a的容量为241即可
最后直接输出

关键词：数学题 
*/
#include<iostream>
using namespace std;
    
int main()
{   
    int a[241]={0};
    int factor[1000001];
    int n;

    for(int i=1;i<=1000000;i++)factor[i]=1;
    
    for(int i=2;i<=1000000;i++)
        for(int j=i;j<=1000000;j+=i)
            factor[j]++;//存下每个数因数的个数 

    for(int i=1;i<=1000000;i++)
        factor[i]=a[factor[i]]++;//将该数组的意义改为“该数字是第几次出现” 
    
    while(cin>>n)
    {
        cout<<factor[n]<<endl; 
    }
    
    return 0;
} 
