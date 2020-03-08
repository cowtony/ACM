/*
约瑟夫环，n人一个圈，每隔k个人踢掉一个，先踢掉第m个人，问最后剩谁

百度百科搜一下，可以得到复杂度为n的递推（递归） 
但是这个默认是第0个人开始的
所以最后还要转换一下 

关键词：巧算法，约瑟夫环 
*/
#include<iostream>
using namespace std;

int Joe(int n,int k)
{
    if(n==1)return 0;
    return (Joe(n-1,k)+k)%n;
}

int main()
{
    int n,k,m;
    while(cin>>n>>k>>m)
    {
        if(n==0 && k==0 && m==0)break;
        cout<<(Joe(n,k)-(k%n-m)+n)%n+1<<endl;
    }
}
