/*
Recaman's Sequence数列定义a(0)=0,a(n)=a(n-1)-n，若a(n)不是正数或以前出现过，则a(n)=a(n-1)+n
输入0<=k<=500000，输出a(k)

用一个数组存下该数列的前500000项
另一个布尔数组来判断某一项以前是否出现过

关键词：数学题，简单题 
*/
#include<iostream>
using namespace std;

int data[500001];
bool judge[5000000]={false};

int main()
{
    int k;
    
    data[0]=0;
    for(int i=1;i<=500000;i++)
    {
        data[i]=data[i-1]-i;
        if(data[i]<=0||judge[data[i]]==true)data[i]=data[i-1]+i;
        judge[data[i]]=true;
    }
    
    while(cin>>k)
    {
        if(k==-1)return 0;
        
        cout<<data[k]<<endl;
    }
} 
