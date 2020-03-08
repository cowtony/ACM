/*
找出一堆数中具有最大质因数的那个

就一个一个判断一个一个找，最大的记下来输出就行了
求最大质因数的函数也不难写，就像分解质因数差不多，质数本身就输出他自己

关键词：数学题，简单题，数论 
*/
#include<iostream>
using namespace std;

int max_factor(int test)
{
    int x=test;
    
    for(int i=2;i*i<=x;i++)
        while(x%i==0)x/=i;
    
    return x;
}

int main()
{
    int n;
    cin>>n;
 
    int max=0,max_result;
    while(n--)
    {
        int t,s;
        cin>>t;
        
        s=max_factor(t);
        if(s>max){max=s;max_result=t;}
    }
    cout<<max_result;
    
    //while(1);
    return 0;
}
