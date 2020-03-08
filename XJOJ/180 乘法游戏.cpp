/*
从1开始，每人乘2-9的一个数，谁先乘到大于n谁就赢了，问Stan有没有必胜的策略

我写了一个很美的递归判断Stan有没有必胜策略（在最后） 
但是对于大数据明显超时
不过利用那个函数列举前面可以发现一些规律：
Stan:1-9                     9=2^0 * 9^1
Ollie:10-18                 18=2^1 * 9^1
Stan:19-162                162=2^1 * 9^2
Ollie:163-324              324=2^2 * 9^2
Stan:325-2916             2916=2^2 * 9^3
Ollie:2917-5832           5832=2^3 * 9^3
Stan:5833-52488          52488=2^3 * 9^4
看到规律以后直接做
其实好好想想也应该能明白为什么会是这个规律 

关键词：递归，找规律，巧算法 
*/
#include<iostream>
using namespace std;

int main()
{
    int n;
    while(cin>>n)
    {
        n--;
        while(1)
        {
            n/=9;
            if(n==0){cout<<"Stan wins."<<endl;break;}
            n/=2;
            if(n==0){cout<<"Ollie wins."<<endl;break;}
        }
    }
}

/* 
bool f(int present,bool name)
{
    if(n==1)return true;
    if(present>=n)
    {
        if(name==Ollie)return true;
        else return false;
    }
    
    switch(name)
    {
        case Stan:
            for(int i=2;i<=9;i++)
                if(f(present*i,!name)==true)return true;
            return false; 
        case Ollie:
            for(int i=2;i<=9;i++)
                if(f(present*i,!name)==false)return false;
            return true; 
    }
}
*/
