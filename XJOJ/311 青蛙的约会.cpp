/*
长为L的环，两只青蛙起点为x和y，速度为m和n，方向相同一起开始跳，问多长时间后可以相遇

设相遇时间为t，则mt+x=nt+y(mod L) 
即是求关于t的一次同余方程(m-n)t=y-x(mod L)的最小非负解 
但是求一次同余方程的函数总出错
用普通方法做也可以
遍历t从0到L，如果t>=L肯定无解

关键词：数论 
*/
#include<iostream>
using namespace std;

int main()
{
    int x,y,m,n,L;
    while(cin>>x>>y>>m>>n>>L)
    {
        for(int t=0;t<L;t++)
            if((m*t+x-n*t-y)%L==0)
            {
                cout<<t<<endl;
                goto end;
            }

        cout<<"Impossible"<<endl;
        end:;
    }
}
