/*
给一个数，从个位开始一位一位的四舍五入，例如23456:23460-23500-24000-20000

用递归算出最后的高位数字，再用全局变量记下递归了几次，即数字后要跟几个零

关键词：递归
*/
#include<iostream>
using namespace std;

int k;    //记录0的个数

int main()
{
    
    int n;
    int niu(int);
    
    //freopen("aaa.txt","r",stdin);
    
    cin>>n;
    while(cin>>n)
    {
        k=0;         
        cout<<niu(n);
        for(int i=0;i<k;i++)cout<<'0';
        cout<<endl;
    }
    
    //while(1);
    return 0;
}

int niu(int n)  //递归函数
{
    if(n<10)return n;
    int i;
    i=n%10;
    if(i>4)n+=10-i;
        else n-=i;
    n/=10;
    k++;            //调用一次多打印一个零
    return niu(n);
}
