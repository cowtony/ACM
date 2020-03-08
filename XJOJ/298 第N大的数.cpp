/*
输入数组，输出该数组第K大的数

用了一次快排，注意比较函数，快排的用法

关键词：简单题 
*/
#include<iostream>
#include<algorithm>
using namespace std;

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,k,a[100];
        cin>>n>>k;
        for(int i=0;i<n;i++)cin>>a[i];
        
        sort(a,a+n,greater<int>());//快排
        cout<<a[k-1]<<endl; 
    }
    return 0;
}
