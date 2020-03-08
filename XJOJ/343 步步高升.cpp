/*
输入钱数和A,B两值，每次减A或B，求减所给钱数总方法数

以256,88,5,9为例，差值为168
5和9的最小公倍数为45（表示45只能用5个9或9个5组成） 
所以把168可以分成45+45+45+33
其中33这个余数最多只有一种组合（不证明了）33=3*5+2*9
前面的三个45可以有3+1=4种组合（都是5，一组9，两组9，三组9） 
最终结果:
168=17*9+3*5;
168=12*9+12*5;
168=7*9+21*5;
168=2*9+30*5;
每一组的排列情况为C(a+b,a)，比如第一行是C(21,3)

关键词：数论 
*/
#include<iostream>
using namespace std;

int C(int a,int b)
{
    if(a<b)return C(b,a);
    if(b>a/2)return C(a,a-b);
    
    if(a==0 || b==0)return 1;
    else return C(a-1,b-1)+C(a-1,b);
}

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

int main()
{
    int W1,Z,A,B;
    cin>>W1>>Z>>A>>B;
    
    int dw=W1-Z;//钱的差值 
    int g=lcm(A,B);//最小公倍数 
    
    int cA=0,cB=0,f=dw%g;//f是钱的余数 

    while(f>0)
    {
        if(f%B==0){cB=f/B;break;}
        else {cA++;f-=A;}
    }

    if(f<0){cout<<0<<endl;return 0;}
    
    int sum=0;
    for(int i=0;i<=dw/g;i++)
    {
        int a=i*g/A+cA;
        int b=(dw/g-i)*g/B+cB;
        sum+=C(a+b,b);
    }
    
    cout<<sum;
    //while(1);
}
