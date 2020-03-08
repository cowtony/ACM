/*
输入一系列数据，输出他的中位数

用sort对数据排序，输出中间的数字或中间两数的平均数

关键词：简单题 
*/
#include<iostream>
#include<algorithm>
#include<stdio.h>
using namespace std;

int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        int n;
        cin>>n;
        
        double arr[1000];
        for(int i=0;i<n;i++)
            cin>>arr[i];
            
        sort(arr,arr+n);
        if(n%2==1)printf("%.3lf\n",arr[n/2]);
        else printf("%.3lf\n",(arr[n/2]+arr[n/2-1])/2);
    }
}
