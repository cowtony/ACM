/*
求不大于所给数的sum(1/x) x strat from 2的最大项数

直接做

关键词：数学题，简单题
*/
#include<iostream>
using namespace std;

int main()
{
    double s,i,n;
    
    while(cin>>n&&n!=0)
    {
        for(s=0,i=2;s<=n;i++)
            s+=1/i;

        cout<<i-2<<" card(s)"<<endl;
    }
    
    return 0;
}
