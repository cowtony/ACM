/*
ID:cowtony1
PROG:clocks
LANG:C++
�Ÿ���3*3����һ��Ҫ��ͨ��ָ������������ȫ����ʮ����ģ�������Ž�

�����������ǿ����������
��Ϊ�����˳����Դ��ң�����һ�����������Ĵε���û��
������Ҫ���е��Ż��ǣ�ÿ��������������Σ����Ҳ���˳������ǵ�����
��Ȼ����⻹������ѧ�����Ż������Ľⷨ 

�ؼ��ʣ������������ 
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
