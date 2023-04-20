/*
ID : cowtony1
PROG : transform
LANG : C++

判断一个黑白方阵可不可以通过题中给的操作转化成另一个方阵，要求输出最小的数字

写一个类，里面放上所有操作的函数，然后直接枚举一遍

关键词：简单题 
*/
#include<iostream>
#include<fstream>
using namespace std;

int N;

struct Square
{
    char data[10][10];
    void input()
    {
        for(int i=0;i<N;i++)
            for(int j=0;j<N;j++)
                cin>>data[i][j];
    }
    bool operator ==(Square s)
    {
        for(int i=0;i<N;i++)
            for(int j=0;j<N;j++)
                if(data[i][j]!=s.data[i][j])return false;
        return true;
    }
    Square Rotation_90_Degree()
    {
        Square s;
        for(int i=0;i<N;i++)
            for(int j=0;j<N;j++)
                s.data[j][N-i-1]=data[i][j];
        return s;
    }
    Square Rotation_180_Degree()
    {
        return Rotation_90_Degree().Rotation_90_Degree();
    }
    Square Rotation_270_Degree()
    {
        return Rotation_180_Degree().Rotation_90_Degree();
    }
    Square Reflection()
    {
        Square s;
        for(int i=0;i<N;i++)
            for(int j=0;j<N;j++)
                s.data[i][N-j-1]=data[i][j];
        return s;
    }
};

int main()
{
    freopen("transform.in","r",stdin);
    freopen("transform.out","w",stdout);
    
    cin>>N;
    Square a,b;
    a.input();
    b.input();
    
    Square t=a.Reflection();

    if(a.Rotation_90_Degree()==b)cout<<1<<endl;
    else if(a.Rotation_180_Degree()==b)cout<<2<<endl;
    else if(a.Rotation_270_Degree()==b)cout<<3<<endl;
    else if((a=a.Reflection())==b)cout<<4<<endl;
    else if(t.Rotation_90_Degree()==b || t.Rotation_180_Degree()==b || t.Rotation_270_Degree()==b)cout<<5<<endl;
    else if(a==b)cout<<6<<endl;
    else cout<<7<<endl;
    
    //while(1);
}
