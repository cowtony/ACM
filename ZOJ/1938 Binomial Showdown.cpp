/*
输入n,k，计算C(n,k)

C(n,k)=n!/[(n-k)!k!]分子分母都是n个数相乘
利用公式计算时为了不使数据溢出，每乘一个分子除一个分母
不能用long long类型的话也可以用double 

关键词：数学题，简单题
*/
#include<iostream>
using namespace std;

int main()
{
    long long n,k,result;
   
    //freopen("aaa.txt","r",stdin);
    
    
    while(cin>>n>>k)
    {
        if(n==0)return 0;
        if(n==k||k==0){cout<<1<<endl;continue;}
        if(k<n/2)k=n-k;
        
        result=n;
        for(int i=n-1;i>k;i--)
        {
            result*=i;
            result/=(n+1-i);
        }
        
        cout<<result<<endl;
    }
    
    
    return 0;
}

