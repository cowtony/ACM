/*
找一个分界线使得数组在分界线左边的和等于右边的

先读入数据，同时求出数组元素总和
然后便利出前i项的和小于等于sum/2
最后判断前i项和是否等于sum/2
注意如果丸子数是奇数直接就不可能，否则会出错

关键词：模拟，简单题 
*/
#include<iostream>
using namespace std;

int main()
{
    int n;
    while(cin>>n)
    {
        if(n==0)break;
        
        int guest[30],sum=0;
        for(int i=0;i<n;i++)
        {
            cin>>guest[i];
            sum+=guest[i];
        }
        
        int left=0,i;
        for(i=0;left<sum/2;i++)
            left+=guest[i];
        
        if(left==sum/2.0)//注意是2.0 
            cout<<"Sam stops at position "<<i<<" and Ella stops at position "<<i+1<<"."<<endl;
        else cout<<"No equal partitioning."<<endl;
    }
}
