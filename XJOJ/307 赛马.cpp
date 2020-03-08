/*
田忌赛马题，344的简单版 

先从小到大一排，再一对一的找

关键词：简单题 
*/ 
#include<iostream>
#include<algorithm>
using namespace std;

int main()
{
    int a[100],b[100];//存齐王和田忌的马 
    int n;//存他们马的个数 
    
    //freopen("aaa.txt","r",stdin);
    
    while(cin>>n) 
    {
        if(n==0)break;

        for(int i=0;i<n;i++)cin>>b[i];
        for(int i=0;i<n;i++)cin>>a[i];//输入 
    
        sort(a,a+n);
        sort(b,b+n);//将他们的马升序排列 
    
        int point=0;//指向齐王的第一匹马 
        for(int i=0;i<n && point<n;i++)//遍历田忌的马
            if(b[i]>a[point])point++;//point就是齐王被打败的马的个数 
        
        cout<<point<<endl;
    }
    //return 0;
}
