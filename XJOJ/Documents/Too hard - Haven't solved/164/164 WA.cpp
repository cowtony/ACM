#include<iostream>
using namespace std;

int GCD(int a,int b)
{
    if(b==0)return a;
    else return GCD(b,a%b);
}

int LCM(int a,int b)
{
    return a/GCD(a,b)*b;
}

int Factor(int n,int k)
{
    int count=0;
    for(int i=2;i<=n/2;i++)
    {
        int lcm=LCM(i,i^k);
        if(lcm==0)lcm=99999999;
        
        count+=n/i-1-n/lcm;
    }
    return count;
}

int main()
{
    int a,b,n;
    while(cin>>a>>b>>n)
    {
        cout<<Factor(a+b,n)-Factor(a-1,n)<<endl;
    }
}
