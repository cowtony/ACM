/*
先从小到大一排，再一对一的找

关键词：简单题 
*/ 
#include<iostream>
#include<algorithm>
using namespace std;

int main()
{
    int a[1000],b[1000];//存齐王和田忌的马 
    int m,n;//存他们马的个数 
    
    //freopen("aaa.txt","r",stdin);
    
    cin>>m;
    for(int i=0;i<m;i++)cin>>a[i];
    cin>>n;
    for(int i=0;i<n;i++)cin>>b[i];//输入 
    
    sort(a,a+m);
    sort(b,b+n);//将他们的马升序排列 
    
    int point=0;//指向齐王的第一匹马 
    for(int i=0;i<n && point<m;i++)//遍历田忌的马
        if(b[i]>a[point]){point++;continue;}//point就是齐王被打败的马的个数 
        
    cout<<point;
    
    //while(1);
    return 0;
}
