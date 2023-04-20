/*
ID:cowtony1
PROG:clocks
LANG:C++
九个表3*3放在一起，要求通过指定步骤把它变成全部是十二点的，输出最优解

这道题的正解是宽度优先搜索
因为步骤的顺序可以打乱，并且一个步骤做了四次等于没做
所以需要进行的优化是：每个步骤最多做三次，并且步骤顺序必须是递增的
当然这道题还有用数学方法优化后更快的解法 

关键词：宽度优先搜索 
*/
#include<iostream>
#include<fstream>
#include<queue>
using namespace std;

struct Clock
{
    int time[3][3];
    int path[10];
    int big;
    void input()
    {
        for(int i=0;i<3;i++)
            for(int j=0;j<3;j++)
            {
                cin>>time[i][j];
                time[i][j]%=12;
            }
        for(int i=0;i<10;i++)path[i]=0;
        big=1;
    }
    void plus(int i,int j)
    {time[i][j]=(time[i][j]+3)%12;}
    Clock way(int n)
    {
        Clock temp=*this;
        switch(n)
        {
            case 1:temp.plus(0,0);temp.plus(0,1);temp.plus(1,0);temp.plus(1,1);
                   temp.path[1]++;break;
            case 2:temp.plus(0,0);temp.plus(0,1);temp.plus(0,2);
                   temp.path[2]++;break;
            case 3:temp.plus(0,1);temp.plus(0,2);temp.plus(1,1);temp.plus(1,2);
                   temp.path[3]++;break;
            case 4:temp.plus(0,0);temp.plus(1,0);temp.plus(2,0);
                   temp.path[4]++;break;
            case 5:temp.plus(0,1);temp.plus(1,0);temp.plus(1,1);temp.plus(1,2);temp.plus(2,1);
                   temp.path[5]++;break;
            case 6:temp.plus(0,2);temp.plus(1,2);temp.plus(2,2);
                   temp.path[6]++;break;
            case 7:temp.plus(1,0);temp.plus(1,1);temp.plus(2,0);temp.plus(2,1);
                   temp.path[7]++;break;
            case 8:temp.plus(2,0);temp.plus(2,1);temp.plus(2,2);
                   temp.path[8]++;break;
            case 9:temp.plus(1,1);temp.plus(1,2);temp.plus(2,1);temp.plus(2,2);
                   temp.path[9]++;break;
        }
        return temp;
    }
    bool equal()
    {
        for(int i=0;i<3;i++)
            for(int j=0;j<3;j++)
                if(time[i][j]!=0)return false;
        return true;
    }
    void output()
    {
        int total=0,count=0;
        for(int i=0;i<10;i++)
        total+=path[i];
        for(int i=1;i<10;i++)
            for(int j=0;j<path[i];j++)
            {
                cout<<i;
                count++;
                if(count<total)cout<<' ';
            }
        cout<<endl;
    }
};

int main()
{
    freopen("clocks.in","r",stdin);
    freopen("clocks.out","w",stdout);
    
    Clock clock;
    clock.input();
    queue<Clock> q;
    q.push(clock);
    while(q.empty()==false)
    {
        clock=q.front();
        for(int i=clock.big;i<=9;i++)
            if(clock.path[i]<3)
            {
                Clock temp=clock.way(i);
                temp.big=i;
                q.push(temp);
                if(temp.equal()==true)
                {
                    temp.output();
                    return 0;
                }
            }
        q.pop();
    }
}
