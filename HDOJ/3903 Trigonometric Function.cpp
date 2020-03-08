/*
已知三角形三边长a,b,c，求题中式子是否为有理数

cos(A),cos(B),cos(C)均为有理数，由正弦定理
所以该题为了判断sin(A),sin(B),sin(C)是否为有理数
求sin的公式在下面，其为完全平方数即可

关键词：数学题 
*/
#include<iostream>
#include<cmath>
using namespace std;

bool square(long long X)
{
    long long ans=sqrt(X*1.0);
    return ans*ans==X;
}

int main()
{
    int cases;
    cin>>cases;
    while(cases--)
    {
        long long a,b,c,n,m,k;
        cin>>a>>b>>c>>n>>m>>k;
        
        long long A=4*b*b*c*c-(b*b+c*c-a*a)*(b*b+c*c-a*a);
        long long B=4*a*a*c*c-(a*a+c*c-b*b)*(a*a+c*c-b*b);
        long long C=4*a*a*b*b-(a*a+b*b-c*c)*(a*a+b*b-c*c);
        
        if(square(A)==true && square(B)==true && square(C)==true)cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
}
