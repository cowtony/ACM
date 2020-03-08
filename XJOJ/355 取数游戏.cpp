/*
输入数n，表示n个不同的东西一排，从中任取，要求取的不能相邻，求有多少取法 

可以用插板，设取x个，相当于把这x个东西插入剩下n-x个东西的缝中，也就是C(n-x+1,x)
但是有一种更巧的办法
根据题意，所求的值正好是第n+2项斐波那契数列的值，不知道为什么

关键词：排列组合，巧算法 
*/
#include<iostream>
using namespace std;

int main()
{
    int n;
    cin>>n;
   
    long long a1=1,a2=1,a3=1;
    
    for(int i=0;i<n;i++)
    {
        a3=a1+a2;
        a1=a2;
        a2=a3;
    }
    cout<<a3;

    //while(1);
    return 0;
}
