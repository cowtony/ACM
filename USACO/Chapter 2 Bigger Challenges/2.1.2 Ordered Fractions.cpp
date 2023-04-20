/*
ID:cowtony1
PROG:frac1
LANG:C++
����n�����������ĸС�ڵ���n�����м�Լ�����

������ҳ��������з�����Ȼ���������
ע�����0/1��1/1

�ؼ��ʣ�ö�٣�����
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
