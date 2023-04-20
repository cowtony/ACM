/*
ID:cowtony1
PROG:frac1
LANG:C++
输入n，升序输出分母小于等于n的所有既约真分数

先穷举找出它的所有分数，然后排序输出
注意输出0/1和1/1

关键词：枚举，简单题
*/
#include<iostream>
#include<fstream>
using namespace std;

struct Fraction
{
    int numerator;
    int denominator;
    double value;
};

int gcd(int a,int b)
{
    if(a%b==0)return b;
    else return gcd(b,a%b);
}

void swap(Fraction &a,Fraction &b)
{
    Fraction temp=a;
    a=b;
    b=temp;
}

int main()
{
    freopen("frac1.in","r",stdin);
    freopen("frac1.out","w",stdout);
    int n;
    cin>>n;
    
    Fraction fraction[100000];
    int count=0;
    for(int d=2;d<=n;d++)
        for(int f=1;f<d;f++)
            if(gcd(d,f)==1)
            {
                fraction[count].numerator=f;
                fraction[count].denominator=d;
                fraction[count].value=f/double(d);
                count++;
            }
    
    for(int i=0;i<count-1;i++)
        for(int j=i+1;j<count;j++)
            if(fraction[i].value>fraction[j].value)swap(fraction[i],fraction[j]);
            
    cout<<"0/1"<<endl;
    for(int i=0;i<count;i++)
        cout<<fraction[i].numerator<<'/'<<fraction[i].denominator<<endl;
    cout<<"1/1"<<endl;
}
