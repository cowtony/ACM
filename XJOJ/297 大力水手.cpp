/*
一串数，求连续的一段数和为最大值

设S[i]表示前i个数的总和，（构造S[0]=0）
则题目要求找i到j的和使之最大即为S[j]-S[i-1](j>i) 
以j结尾的最大值是S[j]-s[i]，其中i为S[0]到S[j-1]中的最小值
遍历一遍就可以了

还有另外一个更简单的动态规划方法在最后 
dp[i]表示以i结尾的最大值，题目既要求max{dp[i]}
dp[i+1]=max(dp[i],0)+value[i+1] 

关键词：动态规划 
*/
#include<iostream>
using namespace std;

int energy[1000001]={0};

int main()
{
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>energy[i];
        energy[i]+=energy[i-1];
    }    
    
    int min=energy[0],max=energy[1]-energy[0];
    for(int i=1;i<=n;i++)
    {
        if(energy[i]-min>max)max=energy[i]-min;
        if(energy[i]<min)min=energy[i];
    }
    
    cout<<max;
    
    //while(1);
}

/*
#include<iostream>
using namespace std;

int main()
{
    int n;
    cin>>n;
    
    int max=0;
    int b=0;
    int energy;
    for(int i=0;i<n;i++)
    {
        cin>>energy;
        if(b>0)b+=energy;
        else b=energy;
        if(b>max)max=b;
    }
    
    cout<<max;
}
*/
