/*
如题图，求左边列有几种布雷方案

枚举左边第一格（有雷，无雷）
根据第一格和第二行的数字可以确定第二格，以此类推，可以唯一确定一种布雷方案
所以答案只可能是0（第一格有雷或无雷都不成立），1（有一个成立），2（两种方案都成立）

关键词：模拟 
*/
#include<iostream>
using namespace std;

int main()
{
    int n;
    int number[10000];
    bool bomb[10000];
    
    cin>>n;
    for(int i=0;i<n;i++)
        cin>>number[i];
        
    int count=0;
    
    for(int j=0;j<=1;j++)
    {
        bomb[0]=j;
        
        if(number[0]-bomb[0]>1 || number[0]-bomb[0]<0)continue;
        else bomb[1]=number[0]-bomb[0];//前两格 
        
        for(int i=1;i<n-1;i++)
            if(number[i]-bomb[i]-bomb[i-1]>1 || number[i]-bomb[i]-bomb[i-1]<0)goto next;
            else bomb[i+1]=number[i]-bomb[i]-bomb[i-1];//中间 
            
        if(number[n-1]!=bomb[n-2]+bomb[n-1])continue;//后两格 
        
        count++;
        next:;
    }
    cout<<count;
    while(1);
}
