/*
转换3进制的问题，但是权值不是0,1,2而是-1,0,1

下面是一些例子，与012的三进制相比原理一样，取模和整除不同了
012：对x取模得到0~x-1的值
-01：对x取模得到不大于-x/2~x/2的值 
012：整除是靠近零取整
-01：整除是远离零取整 
-10=-0- -101
-9=-00  -100
-8=-01  -22
-7=-1-  -21
-6=-10  -20
-5=-11  -12
-4=--   -11
-3=-0   -10
-2=-1   -2
-1=-    -1
0=0     0
1=1     1
2=1-    2
3=10    10
4=11    11
5=1--   12
6=1-0   20
7=1-1   21
8=10-   22
9=100   100
10=101  101

关键词：转换进制 
*/
#include<iostream>
using namespace std;

int mod(int a,int m)
{
    int t=a%m;
    if(t>m/2)t-=m;
    if(t<-m/2)t+=m;
    return t;
}//取模，得到绝对值不大于m一半的模 

int divide(int a,int b)
{
    double t=double(a)/double(b);
    if(t>0)return int(t+0.5);
    else if(t<0)return int(t-0.5);
}//整数除法，向远离零的方向取整 


int main()
{
    int n,point;
    char result[50];
    
    while(cin>>n)
    {
        if(n==0){cout<<0<<endl;continue;}
        
        point=0;
        while(n!=0)
        {
            result[point++]=mod(n,3);
            n=divide(n,3);
        }
        
        for(int i=point-1;i>=0;i--)
            switch(result[i])
            {
                case -1:cout<<'-';break;
                case 0:cout<<'0';break;
                case 1:cout<<'1';break;
            }
        cout<<endl;
    }
    return 0;
}
