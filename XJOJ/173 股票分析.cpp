/*
从给出的一列数里找出最长的连续一串，使得这里面的最大值与最小值的差不大于C

遍历这一列数的开头，要求后面的数相差不能超过C
如果超过了C就从当前列的末尾向前找到新的开头
记录长度的最大值

关键词：模拟，直接做 
*/
#include<iostream>
using namespace std;

int arr[1000000]; 

int main()
{
    int C,N; 
    cin>>C>>N;
    for(int i=0;i<N;i++)cin>>arr[i];
    
    int ans=0;
    for(int i=0;i<N;i++)
    { 
        int length=1;
        int minimum=arr[i];
        int maximum=arr[i];
        for(int j=i+1;j<N;j++)
        { 
            if(arr[j]<minimum)
            { 
                minimum=arr[j]; 
                if(maximum-minimum>C)
                {                 
                    for(int k=j-1;k>=0;k--)
                        if(arr[k]==maximum){i=k;break;}
                    break; 
                } 
            } 
            else if(arr[j]>maximum)
            { 
                maximum=arr[j]; 
                if(maximum-minimum>C)
                { 
                    for(int k=j-1;k>=0;k--)
                        if(arr[k]==minimum){i=k;break;}
                    break; 
                } 
            } 
            length++; 
        } 
        ans=max(ans,length); 
    } 
    cout<<ans;
    //while(1);
}
