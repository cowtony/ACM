/*
看原题图，输入坐标(0<x,y<5000)，输出该位置的数字，没有则输出No Number

找出两条线的规律就可以了

关键词：巧算法 
*/
#include<iostream>
using namespace std;

int main()
{
    int n,a,b;    
    //freopen("aaa.txt","r",stdin);
    cin>>n;
    while(cin>>a>>b)
    {
        if(a==b)
        {
            if(a%2==0)cout<<a+b<<endl;
            else cout<<a+b-1<<endl;
        }
        else if(a==b+2)
        {
            if(a%2==0)cout<<a+b<<endl;
            else cout<<a+b-1<<endl;
        }
        else cout<<"No Number"<<endl;                     
    }

    //while(1);  
    return 0;
}

