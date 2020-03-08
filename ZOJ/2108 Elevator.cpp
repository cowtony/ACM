/*
一个电梯上一层6秒，下一层4秒，停一次5秒，输入运行的任务列表，求总用时

模拟，注意开始时电梯在0层

关键词：简单题，模拟 
*/ 
#include<iostream>
using namespace std;

int main()
{
    int n;
    while(cin>>n)
    {
        if(n==0)break;
        
        int floor[101]={0};
        for(int i=1;i<=n;i++)
            cin>>floor[i];
            
        int time=0;
        for(int i=1;i<=n;i++)
        {
            if(floor[i]>floor[i-1])
                time+=6*(floor[i]-floor[i-1]);
            if(floor[i]<floor[i-1])
                time+=4*(floor[i-1]-floor[i]);
            time+=5;
        }
        cout<<time<<endl;
    }
}
