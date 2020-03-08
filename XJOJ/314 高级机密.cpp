/*
输出a^b%c的结果

把a每次乘a模c，如此反复b次即可

关键词：数论，简单题 
*/
#include<iostream>
using namespace std;

int main()
{
    int a,b,c;
    cin>>a>>b>>c;
    
    int result=1;
    for(int i=0;i<b;i++)
    {
        result=(result*a)%c;
    }
    
    cout<<result;
    
    //while(1);
    return 0;
}
