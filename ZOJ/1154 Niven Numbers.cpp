/*
判断所给的2<=b<=10进制数是否能被它的各位和整除 

一个变量用来存base b
另用一个字符指针存该数字，分别求出十进制的值和各位和，判断能否整除即可 

关键词：进制转换，数学题，简单题 
*/
#include<iostream>
#include<cstring>
using namespace std;

int main()
{
    int cases;
    cin>>cases;
    
    while(cases--)
    {
        int base;
        while(cin>>base)
        {
            if(base==0)break;
            
            string num;
            cin>>num;
            
            int sum=0;//各位数字和 
            int convert=0;//转化为十进制后的值 
            
            for(int i=num.length()-1,p=1;i>=0;i--)
            {
                sum+=(num[i]-'0');
                convert+=(num[i]-'0')*p;
                p*=base;
            }
            if(convert%sum==0)cout<<"yes"<<endl;
            else cout<<"no"<<endl;

        }
        if(cases>0)cout<<endl;
    }
    
    return 0;
}
