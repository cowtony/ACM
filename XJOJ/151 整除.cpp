/*
五个数，找出最少能整除其中三个数的最小数字

C(5,3)=10
所以直接枚举，对十种组合求最小公倍数
取最小的一个

关键词：简单题，数论 
*/
#include<iostream>
using namespace std;

int gcd(int a,int b)
{
    if(a<b)return gcd(b,a);
    
    if(a%b==0)return b;
    else return gcd(b,a%b);
}

int lcm(int a,int b)
{
    return a*b/gcd(a,b);
}

int lcm_3(int a,int b,int c)
{
    return lcm(lcm(a,b),c);
}


int main()
{
    int a,b,c,d,e;
    cin>>a>>b>>c>>d>>e;
    
    int r[10],min;
    r[0]=lcm_3(a,b,c);
    r[1]=lcm_3(a,b,d);
    r[2]=lcm_3(a,b,e);
    r[3]=lcm_3(a,c,d);
    r[4]=lcm_3(a,c,e);
    r[5]=lcm_3(a,d,e);
    r[6]=lcm_3(b,c,d);
    r[7]=lcm_3(b,c,e);
    r[8]=lcm_3(b,d,e);
    r[9]=lcm_3(c,d,e);
    
    min=r[0];
    for(int i=1;i<10;i++)
        if(r[i]<min)min=r[i];

    cout<<min;
    //while(1);
    return 0;
}
