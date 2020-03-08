/*
n个数字排列组合成k个升序，求可能的组合数

找找规律，行为n，列为k：
1
1 1
1 4 1
1 11 11 1
1 26 66 26 1
像杨辉三角一样，关系是K(n,k)=(n+1-k)*K(n-1,k-1)+k*K(n-1,k)
不知道为什么

关键词：巧算法，递归 
*/
#include<iostream>
using namespace std;

long long K(int n,int k)
{
    if(k==1 || k==n)return 1;
    else return (n+1-k)*K(n-1,k-1)+k*K(n-1,k);
}

int main()
{
    int n,k;
    cin>>n>>k;
    cout<<K(n,k);
}
