/*
给出B和N，求A^N=B，最接近的整数A

先算出N次根号下B，再比较它附近的两个整数哪个更接近

关键词：数学题，简单题
*/
#include<iostream>
#include<cmath>
using namespace std;

int main()
{
    int a;
    double b,n;
    
    //freopen("aaa.txt","r",stdin);
    
    while(cin>>b>>n)
    {
        if(b==0)break;
        
        a=pow(b,1/n);   //b的1/n次方
        
        if(pow(a+1,n)-b>b-pow(a,n))cout<<a<<endl;
                              else cout<<a+1<<endl;
    }
   
    //while(1);
    return 0;
}

