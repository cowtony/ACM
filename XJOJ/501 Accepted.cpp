/*
输入两个字符串，判断他们是否相同

用string类型很方便，直接用==判断就可以了

关键词：字符串，简单题，水题 
*/
#include<iostream>
using namespace std;

int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        string a,b;
        cin>>a>>b;
        if(a==b)cout<<"Accepted"<<endl;
        else cout<<"Wrong Answer"<<endl;
    }
}
