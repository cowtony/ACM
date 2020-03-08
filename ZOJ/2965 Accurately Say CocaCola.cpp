/*
从1开始报数，遇到7的倍数或含有7的数字喊CocaCola，输入1<=p<=99，输出连续喊p次时最早的起始数字

分析题意可直接发现p<100时的规律，直接输出就行了

关键词：巧算法 
*/
#include<iostream>
using namespace std;

int main()
{
    int t,p;
    
    cin>>t;
    while(t--)
    {
        cin>>p;
        
        if (p==1)cout<<7<<endl;
   else if (p==2)cout<<27<<endl;
   else if (p>=3 && p<=10)cout<<70<<endl;
   else if (p==11)cout<<270<<endl;
   else cout<<700<<endl;
    }
}
