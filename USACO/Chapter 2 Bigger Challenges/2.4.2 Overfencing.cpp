/*
ID:cowtony1
PROG:maze1
LANG:C++

����һ����ͼ����ͼ���������ڣ����ܱ�֤ţ���Թ�������һ���߳��Թ�����С������

�ȶԵ�ͼ����ʼ����ע��ո��޷�����char���룬Ҫ��cin.get()
��ΰ�ǽ��ֵ��Ϊ0�������ߵĵط���ΪMAXN
���������ڵ�ֵ��Ϊ1����ʾһ���Ϳ����߳�ȥ
����������ǽ�Ļ���ÿ��������߳�ȥ����С����������Χ�ĸ������Сֵ��1�������Լ�ȡ��Сֵ
��˲���ѭ�����㣬ֱ��������ͼ���ٸĽ�
�����ҳ�������
���������2��ֵ����Ϊ��ͼ�Ķ������� 
�������Ҳ������ 

�ؼ��ʣ�������� 
*/
#include<iostream>
#include<fstream>
#include<queue>
using namespace std;

const int MAXN=10000000;

struct Point
{
    int x,y;
    Point(int a=0,int b=0):x(a),y(b){}
};

int main()
{
    freopen("maze1.in","r",stdin);
    freopen("maze1.out","w",stdout);
    
    int W,H;
    cin>>W>>H;
    
    int step[201][77];
    for(int i=0;i<2*H+1;i++)
    {
        cin.get();
        for(int j=0;j<2*W+1;j++)
            step[i][j]=cin.get()==' '?MAXN:0;
    }
    
    for(int i=0;i<2*H+1;i++)
    {
        if(step[i][0]==MAXN)step[i][0]=1;
        if(step[i][2*W]==MAXN)step[i][2*W]=1;
    }
    for(int j=0;j<2*W+1;j++)
    {
        if(step[0][j]==MAXN)step[0][j]=1;
        if(step[2*H][j]==MAXN)step[2*H][j]=1;
    }
    
    bool flag=true;
    while(flag==true)
    {
        flag=false;
        for(int i=1;i<2*H;i++)
            for(int j=1;j<2*W;j++)
            {
                int a=1000000;
                if(step[i][j+1]>0)a=min(a,step[i][j+1]);
                if(step[i][j-1]>0)a=min(a,step[i][j-1]);
                if(step[i+1][j]>0)a=min(a,step[i+1][j]);
                if(step[i-1][j]>0)a=min(a,step[i-1][j]);
                if(step[i][j]>a+1)
                {
                    step[i][j]=a+1;
                    flag=true;
                }
            }
    }
    
    int maxn=0;
    for(int i=0;i<2*H+1;i++)
        for(int j=0;j<2*W+1;j++)
            maxn=max(maxn,step[i][j]);
    
    cout<<maxn/2<<endl;
}
