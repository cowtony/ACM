/*
输入a,b，求b%a，且取值为1~a，b数值超大！

高精度取模
假想把b安置好不动
a从b的左端开始让b减，减不成了a就右移一下接着减
最后剩下的就是余数了

关键词：高精度 
*/
#include<iostream>
#include<string>
using namespace std;

void minus_d(string &dividend,string &divisor)
{
    int start=divisor.length()-1;
    if(dividend[0]<=divisor[0])start++;
    
    for(int i=divisor.length()-1;i>=0;i--,start--)
    {
        dividend[start]-=divisor[i]-'0';//减 
        
        if(dividend[start]<'0')
        {
            dividend[start]+=10;
            dividend[start-1]--;//退位 
        }
    }
}

bool compare(string a,string b)
{
    if(a.length()>b.length())return true;
    else if(a.length()<b.length())return false;
    else return a>b;
}

int main()
{
    int i;
    string divisor;//除数 
    string dividend;//被除数 
    cin>>divisor>>dividend;
    
    while(compare(dividend,divisor)==true)
    {
        minus_d(dividend,divisor);
        while(dividend[0]=='0')dividend.erase(0,1);
    }

    cout<<dividend;
    
    //while(1);
    return 0;
}
