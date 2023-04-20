/*
ID:cowtony1
PROG:cowtour
LANG:C++

����n���ڵ�����꣬�Լ�һ�������ʾ����֮�����ߵĹ�ϵ����Щ�ڵ��������������ͨ����
��һ����ͨ�������ı�ʹ�����γɵ���ͨ����ֱ��������С�������Сֱ��

�ȶ������ݣ���ͼ��map[i][j]��ʾi�ڵ㵽j�ڵ�ľ��룬������ʾû�б�����
Ȼ����floyd����ѭ�������ͬһ��ͨ����ȴû��ֱ�ӱ������ľ���
Ȼ��mmax[i]��ʾi�ڵ�������ͨ�������ܳ�
�������в�����ͬһ��ͨ���������ڵ㣬�ҵ���Сֱ��
���һ��ѭ��û����

�ؼ��ʣ�ͼ�� 
*/
#include<iostream>
#include<fstream>
#include<cmath>
using namespace std;

const double MAXN=1e20;
double distance(double x1,double y1,double x2,double y2)
{
    return sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
}

int main()
{
    freopen("cowtour.in","r",stdin);
    freopen("cowtour.out","w",stdout);
    
    int n;
    cin>>n;
    int x[150],y[150];
    for(int i=0;i<n;i++)
        cin>>x[i]>>y[i];
        
    double map[150][150];    
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
        {
            char c;
            cin>>c;
            if(c=='1')map[i][j]=distance(x[i],y[i],x[j],y[j]);
            else map[i][j]=MAXN;
            if(i==j)map[i][j]=0;
        }

    for(int k=0;k<n;k++)
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
                map[i][j]=min(map[i][j],map[i][k]+map[k][j]);

    double mmax[150]={0};
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            if(map[i][j]!=MAXN)
                mmax[i]=max(mmax[i],map[i][j]);
                
    double result=MAXN;
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            if(map[i][j]==MAXN)
                result=min(result,distance(x[i],y[i],x[j],y[j])+mmax[i]+mmax[j]);
            
    for(int i=0;i<n;i++)
        result=max(result,mmax[i]);
        
    printf("%.6f\n",result);
}
