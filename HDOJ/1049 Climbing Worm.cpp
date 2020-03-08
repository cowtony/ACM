/*
1英尺长的一个虫子从n英尺深的井底向上爬，每分钟爬u英尺下一分钟下滑d英尺，n<100,u>d，求用多长时间爬出

注意最后一下爬到顶就不往下掉了 

关键词：数学题，简单题
*/
#include<iostream>
using namespace std;

int main()
{
    int n,u,d;
    while(cin>>n>>u>>d && (n!=0 || u!=0 || d!=0))
    {
	    if(u>=n)cout<<1<<endl;
		else cout<<2*((n-u-1)/(u-d)+1)+1<<endl;
	}
}
