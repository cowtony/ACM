/*
用火柴棍摆数字，给你n个火柴棍，要求摆出恰好n个棍的最小数字及最大数字

1 2 3 4 5 6 7 8 9 0
2 5 5 4 5 6 3 7 6 6
先看最大数字，首先数位要尽可能得多，于是考虑到1和7这两个数字
当n为偶数时，肯定全摆1数位最多，数字也就最大
当n为奇数时，摆一个711111111这样的数

再看最小数字，要求数位尽可能的少，所以有8
如果n是7的倍数，肯定全摆8最好，888 
如果n=7k+1，把其中一个8换成0，再加一个1，形如1088
如果n=7k+2，1888
如果n=7k+3，k=0:7 , k=1:22 , k=2:200 ,k>2:20088888
如果n=7k+4，k=0:4 , k=1:20 ,k>1:2088888
如果n=7k+5，2888888
如果n=7k+6，6888888

关键词：构造，找规律 
*/ 
#include<iostream>
using namespace std;

int main()
{
    int t;
    cin>>t;
    
    while(t--)
    {
        int n;
        cin>>n;
        
        switch(n%7)
        {
            case 0:
                for(int i=0;i<n/7;i++)cout<<8;
                break;
            case 1:
                cout<<10;
                for(int i=1;i<n/7;i++)cout<<8;
                break;
            case 2:
                cout<<1;
                for(int i=0;i<n/7;i++)cout<<8;
                break;
            case 3:
                switch(n/7)
                {
                    case 0:
                        cout<<7;break;
                    case 1:
                        cout<<22;break;
                    default:
                        cout<<200;
                        for(int i=2;i<n/7;i++)cout<<8;
                }
                break;
            case 4:
                if(n<7)cout<<4;
                else
                {
                    cout<<20;
                    for(int i=1;i<n/7;i++)cout<<8;
                }
                break;
            case 5:
                cout<<2;
                for(int i=0;i<n/7;i++)cout<<8;
                break;
            case 6:
                cout<<6;
                for(int i=0;i<n/7;i++)cout<<8;
        }
        
        cout<<' ';
        if(n%2==0)
            for(int i=0;i<n/2;i++)
                cout<<1;
        else
        {
            cout<<7;
            for(int i=1;i<n/2;i++)
                cout<<1;
        }
        cout<<endl;
    }
} 
