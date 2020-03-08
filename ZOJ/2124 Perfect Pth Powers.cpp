/*
x=b^p，输入整数x（绝对值大于一），要求输出p的最大值，其中b为整数

因为2^32为unsigned long上限，所以p最大值为32
从32开始一次一次开方往下找即可
注意pow函数返回值如4.9999999取整后为4，所以要四舍五入
而且x有可能为负值，实际x值超出了2^32，与题意不符，所以要用long long定义

关键词：数学题 
*/ 
#include<iostream>
#include<cmath>
using namespace std;

long long pow_int(int b,int p)
{
    int i;
    long long sum=1;
    for(i=0;i<p;i++)
        sum*=b;
    return sum;
}

int main()
{
    long long x,n;
    int i,y;
    
    while(cin>>x)
    {
        if(x==0)break;             
    
        if(x>0)
        {
            for(i=32;i>0;i--)
            {
                y=(int)(pow((double)x,1.0/i)+0.5);
                if(pow_int(y,i)==x){cout<<i<<endl;break;}
            }//正数 
        }
        else
        {
            x=-x;
            for(i=31;i>0;i-=2)
            {
                y=(int)(pow((double)x,1.0/i)+0.5);
                if(pow_int(y,i)==x){cout<<i<<endl;break;}
            }//负数 
        } 
    }
    
    return 0;
}
