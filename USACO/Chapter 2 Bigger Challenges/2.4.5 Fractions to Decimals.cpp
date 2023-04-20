/*
ID:cowtony1
PROG:fracdec
LANG:C++

输入a,b，输出a除以b的值，小数表示，循环节用括号打上

判断循环节是判断一次一次除的时候余数以前是否出现过
用布尔数组就可以实现
但是对于格式输出很麻烦，要判断是不是无限循环小数（看余数最后是不是零）
而且还要求每76个字符回车一下

关键词：高精度除法，数学题
*/
#include<iostream>
#include<fstream>
#include<cmath>
using namespace std;

int main()
{    
    freopen("fracdec.in","r",stdin);
    freopen("fracdec.out","w",stdout);
    
    int n,d;
    cin>>n>>d;
    
    int character=0;
    if(n>=d)character+=log(double(n)/d)/log(10)+2;
    else character+=2;
    
    cout<<n/d<<'.';
    n%=d;//输出整数部分和小数点,把原分数化为真分数 
    
    if(n==0){cout<<0<<endl;return 0;}
    
    int remainder[100001]={0};
    int result[100000],length=0;
    
    while(remainder[n]==0)
    {
        remainder[n]=length+1;
        n*=10;
        result[length++]=n/d;
        n%=d;
    }

    if(n!=0)
    {
        for(int i=0;i<length;i++)
        {
            if(i+1==remainder[n])
            {
                cout<<'(';
                character++;
                if(character%76==0)cout<<endl;
            }
            cout<<result[i];
            character++;
            if(character%76==0)cout<<endl;
        }
        cout<<')'<<endl;
        character++;
        if(character%76==0)cout<<endl;
    }
    else
    {
        for(int i=0;i<length-1;i++)
        {
            cout<<result[i];
            character++;
            if(character%76==0)cout<<endl;
        }
        if(result[length-1]!=0)cout<<result[length-1];
        cout<<endl;
    }
    //while(1);
    return 0;
}
