/*
输入一个一个的小数，输出他们的差，要求小数点后保留两位

用到了标准输入输出流的知识
pricision和fixed

关键词：简单题，输出格式 
*/
#include<iostream>
using namespace std;

int main()
{
    double a,b;
    cin>>a;
    while(cin>>b)
    {
        if(b==999)break;
        
        cout.precision(2);
        cout<<fixed<<b-a<<endl;
        a=b;
    }
    cout<<"End of Output";
} 
