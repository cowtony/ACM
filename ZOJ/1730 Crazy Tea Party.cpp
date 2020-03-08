/*
n个人坐一圈，每次让相邻两人换座位，最少多少次可以把座次调成与初始相反？

画一画，找规律，偶数对称换，奇数多半圈次

关键词：巧算法 
*/
#include<iostream>
using namespace std;

int main()
{
    int case_num;
    cin>>case_num;
    
    while(case_num--)
    {
        int n;
        cin>>n;
        int result=0;
        result=(n/2)*(n/2-1);
        if(n%2==1)result+=(n/2);
        cout<<result<<endl;
    }
    
    return 0;
}
