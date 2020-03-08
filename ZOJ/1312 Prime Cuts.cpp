/*
输入1<=n<=1000,1<=c<n，在不小于n的质数表中，
如果有奇数个质数，就输出中间2*c-1个质数，如果有偶数个，则输出中间2*c个

据题意1也被认为是质数
定义一个数组用来存1000内的质数，另一个数组用来存第n个数内有几个质数
用left和right变量算出需要输出的左边序号和右边质数的序号
注意n=c=1的情况以及2*c>p(n)的情况
格式输出也很严

关键词：数学题 
*/
#include<iostream>
using namespace std;

int main()
{
    int prime[169]={1,2};
    int save[1001]={0,1}; 
    int n=2,c;
    int left,right;
    
    for(int i=3;i<1000;i+=2)
    {
        for(int k=1;prime[k]*prime[k]<=i;k++)
        {
            if(i%prime[k]==0)goto end;
        }
        prime[n++]=i;
        end:;
    }//存下1000内的168个质数 

    n=1;
    for(int i=2;i<=1000;i++)
    {
        if(i==prime[n])n++;
        save[i]=n;
    }//prime[n]表示第n个数内有多少质数，包括n 

    while(cin>>n>>c)
    {
        cout<<n<<' '<<c<<':';
        if(n==1){cout<<' '<<1<<endl<<endl;continue;}
        
        left=(save[n]+1)/2-c;
        if(left<0)left=0;
        right=save[n]-left;
        
        for(int i=left;i<right;i++)
            cout<<' '<<prime[i];
        cout<<endl<<endl; 
    }

    return 0;
} 
