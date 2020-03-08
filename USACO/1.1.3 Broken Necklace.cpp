/*
ID: cowtony1
PROG: beads
LANG: C++

从一点打断一个项链，往左往右分别取珠子，但每边只能取一种颜色，白色除外。求最多可以取多少个

枚举打断的点，然后模拟进行，找到最大值
题意简单，还有线性做法

关键词：模拟 
*/
#include<iostream>
#include<fstream>
using namespace std;

int main()
{
    ofstream cout("beads.out");
    ifstream cin("beads.in");
    
    int N;
    cin>>N;
    char color[350];
    for(int i=0;i<N;i++)
        cin>>color[i];
    
    int maxn=0;
    for(int i=0;i<N;i++)
    {
        int count=0;
        char c='w';
        for(int j=i;j!=(i-1+N)%N;j=(j+1)%N,count++)
        {
            if(color[j]=='w')continue;
            else if(c=='w'){c=color[j];continue;}
            else if(c!=color[j])break;
        }
        c='w';
        for(int k=(i-1+N)%N;k!=i;k=(k-1+N)%N,count++)
        {
            if(color[k]=='w')continue;
            else if(c=='w'){c=color[k];continue;}
            else if(c!=color[k])break;
        }
        maxn=max(maxn,count);
    }
    cout<<min(maxn,N)<<endl;
    //while(1);
}
