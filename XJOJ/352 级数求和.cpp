/*
求不大于所给数的sum(1/x) x strat from 2的最大项数

直接做,级数求和 

关键词：数学题，简单题
*/
#include<iostream>
using namespace std;

int main()
{
    double s,i,n;
    
    cin>>n;
    
    for(s=0,i=1;s<=n;i++)
        s+=1/i;

    cout<<i-1<<endl;
    
    return 0;
}
