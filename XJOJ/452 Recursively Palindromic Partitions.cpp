/*
一个数可以拆分成几个数的和，这几个数如果是回文的形式，并且左边n/2个和右边n/2个也都是回文，如此递归，则叫递归回文
输入一个数，输出他的递归回文的拆分数

如果直接用题中给出的定义用递归做的话会超时
所以定义一个数组，把递归改成递推

关键词：递推，回文，递归 
*/
#include<iostream>
using namespace std;

int main()
{
    unsigned long long palindromic[15726]={0};
    palindromic[0]=1;
    
    for(int i=1;i<15726;i++)
        for(int j=0;j<=i/2;j++)
            palindromic[i]+=palindromic[j];

    int t;
    cin>>t;
    for(int i=1;i<=t;i++)
    {
        int n;
        cin>>n;
        cout<<i<<' '<<palindromic[n]<<endl;
    }
}
