/*
找出N个数，他们两两之间的海明距离不小于D，并且每个数小于2^B
海明距离就是两个数的异或值二进制表示里有多少个1 

0是第一个数，一旦找到和前面已存答案距离都不小于海明距离的就记下这个新答案，直到有N个答案

关键词：搜索 
*/
#include<iostream>
using namespace std;

int hamming(int a,int b)
{
    int count=0;
    int c=a^b;
    while(c)
    {
        if(c%2==1)count++;
        c/=2;
    }
    return count;
}//求a,b的海明距离 

int main()
{
    int N,B,D;
    cin>>N>>B>>D;
    
    int result[64]={0};
    int n=1;//存答案的 
    
    int max=1<<B;
    for(int i=1;i<max;i++)
    {
        for(int j=0;j<n;j++)
            if(hamming(i,result[j])<D)goto end;
        result[n++]=i;
        if(n==N)break;
        end:;
    }
    
    for(int i=0;i<n;i++)
    {
        cout<<result[i];
        if((i+1)%10==0)cout<<endl;
        else if(i<n-1)cout<<' ';
    }//输出 
    //while(1);
}
