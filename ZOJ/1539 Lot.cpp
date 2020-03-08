/*
有n个士兵，每次删掉奇数号的人或偶数号的人，直到剩三人，问最后会有多少组可能

n个人删除奇数和偶数分别会剩下n/2和n-n/2个人
这两组人是完全不同的
所以可以用递归继续往下算直到n=3或n<3

关键词：递归 
*/
#include<iostream>
using namespace std;

int count(int n)
{
    if(n==3)return 1;
    if(n<3)return 0;
    
    return count(n/2)+count(n-n/2);
}

int main()
{
    int n;
    while(cin>>n)
        cout<<count(n)<<endl;
}
