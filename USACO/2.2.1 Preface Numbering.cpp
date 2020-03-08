/*
ID:cowtony1
PROB:preface
LANG:C++
1到n的罗马数字分别共有多少个字母？

先研究清楚罗马数字的规则，然后枚举即可

关键词：枚举 
*/ 
#include<iostream>
#include<fstream>
using namespace std;
 
int main()
{
    freopen("preface.in","r",stdin);
    freopen("preface.out","w",stdout);
    
    int n;cin>>n;
    
    int I=0,V=0,X=0,L=0,C=0,D=0,M=0;
    for(int j=1;j<=n;j++)
    {
        int k=j;
        while(k>0)
            if(k>=1000){k-=1000;M++;}
            else if(k>=900 && k<1000){k-=900;C++;M++;}
            else if(k>=500 && k<900){k-=500;D++;}
            else if(k>=400 && k<500){k-=400;C++;D++;}
            else if(k>=100 && k<400){k-=100;C++;}
            else if(k>=90 && k<100){k-=90;X++;C++;}
            else if(k>=50 && k<90){k-=50;L++;}
            else if(k>=40 && k<50){k-=40;X++;L++;}
            else if(k>=10 && k<40){k-=10;X++;}
            else if(k>=9 && k<10){k-=9;I++;X++;}
            else if(k>=5 && k<9){k-=5;V++;}
            else if(k>=4 && k<5){k-=4;I++;V++;}
            else if(k>=1 && k<4){k-=1;I++;}
    }
    
    if(I!=0)cout<<"I "<<I<<endl;
    if(V!=0)cout<<"V "<<V<<endl;
    if(X!=0)cout<<"X "<<X<<endl;
    if(L!=0)cout<<"L "<<L<<endl;
    if(C!=0)cout<<"C "<<C<<endl;
    if(D!=0)cout<<"D "<<D<<endl;
    if(M!=0)cout<<"M "<<M<<endl;
}
