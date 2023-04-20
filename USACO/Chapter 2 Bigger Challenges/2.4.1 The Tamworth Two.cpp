/*
ID:cowtony1
PROG:ttwo
LANG:C++

����10*10�ĵ�ͼ��������ũ�����ţ��λ�ã����ǵ����߹�����ÿ������ǰ��һ�������ϰ���ͻ�һ����˳ʱ��תһ��
��ũ��׷����ţ��ʱ�䣬�����������

ֱ��ģ����������sth�ڵ�ͼ�������10*10*4=400��״̬������ũ���ţ�����160000�֣���ʱ�䳬��160000�����ѭ���������
���߿��Լ�¼��ǰ��״̬

�ؼ��ʣ����⣬ģ�� 
*/
#include<iostream>
#include<fstream>
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
    freopen("ttwo.in","r",stdin);
    freopen("ttwo.out","w",stdout);
    
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
