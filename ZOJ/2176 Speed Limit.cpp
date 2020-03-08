/*
给出汽车各个时间的速度，求行驶路程

先算出每个速度单独用了多长时间，再相乘后求和

关键词：简单题
*/
#include<iostream>
using namespace std;

int main()
{
   
    int sum,n,s,t,x;
   
    //freopen("aaa.txt","r",stdin);
    
    while(cin>>n)
    {
        if(n==-1)break;
        sum=0;x=0;
        
        while(n--)
        {
            cin>>s>>t;
            
            sum+=s*(t-x);   //t-x是时间差
            x=t;
        }
        cout<<sum<<" miles"<<endl;
    }
   
    //while(1);
    return 0;
}

