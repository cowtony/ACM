/*
输入两正整数的和与差，求两数，大数在前

就那样做，判断一下和比差小的情况，以及不是整数的情况 

关键词：简单题，数学题 
*/
#include<iostream>
using namespace std;

int main()
{
    int n;
    cin>>n;
    while(n--)
    {
        int s,d;
        cin>>s>>d;
        if(s<d){cout<<"impossible"<<endl;continue;}
        if((s+d)%2!=0 || (s-d)%2!=0){cout<<"impossible"<<endl;continue;}
        
        int a=(s+d)/2;
        int b=(s-d)/2;
        
        cout<<a<<' '<<b<<endl; 
    }
} 
