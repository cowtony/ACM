/*
给俩数，求最小公倍数和最大公约数

直接做

关键词：简单题，数论 
*/
#include<iostream>
using namespace std;

int GCD(int a,int b)
{
    if(a%b==0)return b;
    else return GCD(b,a%b);
}

int LCM(int a,int b)
{
    return a/GCD(a,b)*b;
}

int main()
{
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        int a,b;
        cin>>a>>b;
        
        cout<<i<<' '<<LCM(a,b)<<' '<<GCD(a,b)<<endl;
    }
}
