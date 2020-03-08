/*
判断第k大的由5,2,0组成的数中是否含有"520"片段

其实5,2,0可以替代为2,1,0，这样第k大的数就是把它转换成三进制即可
然后再搜索是否含有210子串

关键词：进制转换，巧算法，简单题 
*/
#include<iostream>
using namespace std;

int main()
{
    int k;
    cin>>k;
    char digit[10];
    
    int point=0;
    while(k>0)
    {
        digit[point++]=k%3;
        k/=3;
    }
    
    bool judge=false;
    for(int i=0;i<point-2;i++)
        if(digit[i]==0 && digit[i+1]==1 && digit[i+2]==2)judge=true;
        
    if(judge==true)cout<<"yes";
    else cout<<"no";
    
    //while(1);
    return 0;
}
