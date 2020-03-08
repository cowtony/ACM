/*
给出n<3000个整数，判断相邻两整数的差是否正好为1至n-1这n-1个数

用一个数组（筛）记下该列数的n-1个差，然后判断从1至n-1是否每个数都出现过

关键词：数学
*/
#include<iostream>
#include<cmath>
using namespace std;

int main()
{
    int a,b,n,t,i;
    bool niu[3001];   //筛
    
    while(cin>>n)
    {
        t=n;
        memset(niu,false,sizeof(niu));  //筛的初始化
        cin>>a;                         //该列数的第一个数
        
        while(--t)
        {
            cin>>b;                     //该列数的后几个
            niu[abs(b-a)]=true;
            a=b;
        }
        
        for(i=1;i<=n-1;i++)
            if(niu[i]==false)break;     //看是否有未出现的差值

        if(i==n)cout<<"Jolly"<<endl;
           else cout<<"Not jolly"<<endl;
    }
return 0;
}
