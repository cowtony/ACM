/*
算画一个直方图需要的墨水 

直接模拟做，题简单但是英语不好看懂

关键词：模拟，简单题 
*/
#include<iostream>
using namespace std;

int main()
{
    int n,w;
    while(cin>>n>>w)
    {
        if(n==0 && w==0)break;
        
        int bar[11]={0};
        
        int width=0,height=0;
        for(int i=0;i<n;i++)
        {
            int x;
            cin>>x;
            bar[x/w]++;
            if(width<x)width=x;
            if(height<bar[x/w])height=bar[x/w];
        }
        width/=w;
            
        double ink=0;    
        for(int i=0;i<=width;i++)
            ink+=bar[i]*(width-i);
          
        cout<<ink/(height*width)+0.01<<endl;
    }
}
