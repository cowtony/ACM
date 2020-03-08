/*
1英尺长的一个虫子从n英尺深的井底向上爬，每分钟爬u英尺下一分钟下滑d英尺，n<100,u>d，求用多长时间爬出

关键词：数学题，简单题
*/
#include<iostream>
using namespace std;

int main()
{
    int n,u,d; 
    
    //freopen("aaa.txt","r",stdin);
    
    while(cin>>n>>u>>d)
    {
        if(n==0)break;
        
        if((n-u)%(u-d)==0)cout<<2*(n-u)/(u-d)+1<<endl;
        else cout<<2*int((n-u)/(u-d)+1)+1<<endl;
    }
    
    
    
    
    //while(1);
    return 0;
}

