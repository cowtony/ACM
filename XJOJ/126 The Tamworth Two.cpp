/*
输入10*10的地图，上面有农夫和奶牛的位置，他们的行走规律是每分钟向前走一格，遇到障碍物就花一分钟顺时针转一下
求农夫追上奶牛的时间，无穷则输出零

直接模拟做，由于sth在地图上最多有10*10*4=400种状态，所以农夫和牛最多有160000种，若时间超过160000则必有循环，输出零
或者可以记录以前的状态

关键词：简单题，模拟 
*/
#include<iostream>
using namespace std;

char map[12][12];

void walk(int sth[])
{
    switch(sth[2])
    {
        case 0:if(map[sth[0]-1][sth[1]]=='.'){sth[0]--;return;}
               else break;
        case 1:if(map[sth[0]][sth[1]+1]=='.'){sth[1]++;return;}
               else break;
        case 2:if(map[sth[0]+1][sth[1]]=='.'){sth[0]++;return;}
               else break;
        case 3:if(map[sth[0]][sth[1]-1]=='.'){sth[1]--;return;}
               else break;
    }
    sth[2]=(sth[2]+1)%4;
}

int main()
{
    for(int i=0;i<12;i++)
        for(int j=0;j<12;j++)
            map[i][j]='*';
    
    int john[3],cow[3];
    for(int i=1;i<=10;i++)
        for(int j=1;j<=10;j++)
        {
            cin>>map[i][j];
            if(map[i][j]=='F')
            {
                john[0]=i;
                john[1]=j;
                john[2]=0;
                map[i][j]='.';
            }
            if(map[i][j]=='C')
            {
                cow[0]=i;
                cow[1]=j;
                cow[2]=0;
                map[i][j]='.';
            }
        }

    int time=0;
    while(1)
    {
        walk(john);
        walk(cow);
        time++;
        if(john[0]==cow[0] && john[1]==cow[1])
        {cout<<time<<endl;return 0;}
        if(time>160000)
        {cout<<0<<endl;return 0;}
    }
}
