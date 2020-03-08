/*
输入一个数列，输出数列的最长升序子串的长度

用动态规划，假定以第k个元素结尾的最长上升子串的长度为maxlen[k]
则第一个元素maxlen[0]=1
maxlen[k]=max{maxlen[i]}+1其中i<k，且s[i]<s[k] 
递推即可算出所有的maxlen
找出最大的输出即可
LIS是啥？ 

关键词：动态规划 
*/
#include<iostream>
using namespace std;

int main()
{
    int t;
    cin>>t;
    for(int i=0;i<t;i++)
    {
        if(i>0)cout<<endl;
        
        int n;
        cin>>n;
        int sequence[1000],maxlen[1000]={1};
        for(int j=0;j<n;j++)
        {
            cin>>sequence[j];
            int max=0;
            for(int k=0;k<j;k++)
            {
                
                if(sequence[k]<sequence[j] && maxlen[k]>max)
                    max=maxlen[k];
            }
            maxlen[j]=max+1;
        }//制作状态转移方程的数据 
        
        int max=0;
        for(int j=0;j<n;j++)
            if(maxlen[j]>max)max=maxlen[j];
        cout<<max<<endl;
    }
} 
