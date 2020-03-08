/*
质数缺口的长度被定义为两相邻质数的差，输入一个数，输出包含这个数的质数缺口长度

筛法算出范围内的质数
保留这个筛，直接找。

关键词：筛法，数论，简单题 
*/
#include<iostream>
using namespace std;

bool prime[1299710];

int main()
{
    for(int i=2;i<1299710;i++)
        prime[i]=true;
    for(int i=2;i*i<=1299719;i++)
        if(prime[i]==true)
            for(int j=2*i;j<1299710;j+=i)
                prime[j]=false;
                
    int k;
    while(cin>>k && k)
    {
        int left,right;
        for(left=k;prime[left]==false;left--);
        for(right=k;prime[right]==false;right++);
        cout<<right-left<<endl;
    }
}
