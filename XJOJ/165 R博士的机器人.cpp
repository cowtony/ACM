/*
一串数，求连续的一段数和为最大值，（这一串数最少长度为f） 

这道题和297的大力水手一样，多了一个限制条件是串的最少长度
相当于297那道题的最少长度是1
再遍历的时候，把min的最小值定义为当前元素往前推f个元素最小值 

关键词：动态规划 
*/
#include<iostream>
using namespace std;

int energy[1000001]={0};

int main()
{
    int n,f;
    cin>>n>>f;
    for(int i=1;i<=n;i++)
    {
        cin>>energy[i];
        energy[i]+=energy[i-1];
    }    
    
    int min=energy[0],max=energy[f]-energy[0];
    for(int i=f;i<=n;i++)
    {
        if(energy[i-f]<min)min=energy[i-f];
        if(energy[i]-min>max)max=energy[i]-min;
    }
    
    cout<<max<<endl;
    
    //while(1);
}
