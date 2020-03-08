/*
给出n<=100，后面跟n个整数表示数组A，要求输出数组B满足：A的每个元素B中都有，B严格单调递增

将数组A快排，然后仅输出不同的数字
注意输出格式

关键词：简单题 
*/
#include<iostream>
#include<algorithm>
using namespace std;

int main()
{
    int a[100];
    int n,t;
    
    while(cin>>n)
    {
        if(n==0)return 0;
        
        for(int i=0;i<n;i++)cin>>a[i];
        
        sort(a,a+n);
        
        cout<<a[0];
        for(int i=1;i<n;i++)
        {
            if(a[i]!=a[i-1])cout<<' '<<a[i];
        }
        cout<<endl; 
    }
} 
