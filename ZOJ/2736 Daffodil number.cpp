/*
判断三位数是不是水仙花数

简单

关键词:简单题,数学题 
*/
#include<iostream>
using namespace std;

int main()
{
    int n;
    while(cin>>n)
    {
        int sum=0,t=n;
        sum+=(t%10)*(t%10)*(t%10);
        t/=10;
        sum+=(t%10)*(t%10)*(t%10);
        t/=10;
        sum+=(t%10)*(t%10)*(t%10);

        if(n==sum)cout<<"Yes"<<endl;
        else cout<<"No"<<endl;
    }
}
