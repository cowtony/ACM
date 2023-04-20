/*
ID:cowtony1
PROG:rect1
LANG:C++

N����ͬ����ɫ�Ĳ�͸���ĳ�����(1 <= N <= 1000)��������һ�ź��ΪA����ΪB�İ�ֽ�ϡ�
��Щ�����α�����ʱ����֤�����ǵı����ֽ�ı�Եƽ�С����еĳ����ζ������ڰ�ֽ�ڣ��������ǻῴ����ͬ��״�ĸ�����ɫ��
����ϵͳ��ԭ��(0,0)�������Ű�ֽ�����½ǣ�����������ƽ���ڱ�Ե��

�����и�ӵݹ��ϸ��ķ���
��˳������ֽ����Ϣ������������ܿ������������������һ�ſ�ʼ���𽥼�ֽ�ϸ��������ϵ����о����е���ʣ�µľ��Ǳ����ܿ�������ɫ 
ÿ���ϸ������������ֽ�ǵ����ͽ��þ����и��4�飬���Ŀ�����ݹ��ϸ�
�и����USACO�еĽ��� 

�ؼ��ʣ����⣡�������⣡����˼��
*/
#include<iostream>
#include<fstream>
using namespace std;

int limx,limy,limc;
int x1[1001],x2[1001],y1[1001],y2[1001];
int color[2501]={1},area[2501]={0};

void cover(int dx,int dy,int ux,int uy,int floor,int c)
{
    while(floor<=limc && (dx>=x2[floor] || ux<=x1[floor] || dy>=y2[floor] || uy<=y1[floor]))floor++;//if the two rectangles are not overlap,come-up~
    if(floor>limc){area[c]+=(ux-dx)*(uy-dy);return;}//when it comes to the topside,add its acreage
    if(dx<x1[floor]){cover(dx,dy,x1[floor],uy,floor+1,c);dx=x1[floor];}
    if(ux>x2[floor]){cover(x2[floor],dy,ux,uy,floor+1,c);ux=x2[floor];}
    if(dy<y1[floor]){cover(dx,dy,ux,y1[floor],floor+1,c);dy=y1[floor];}
    if(uy>y2[floor]){cover(dx,y2[floor],ux,uy,floor+1,c);uy=y2[floor];}
}

int main()
{
    freopen("rect1.in","r",stdin);
    freopen("rect1.out","w",stdout);
    
    x1[0]=y1[0]=0;
    cin>>x2[0]>>y2[0]>>limc;

    for(int i=1;i<=limc;i++)
        cin>>x1[i]>>y1[i]>>x2[i]>>y2[i]>>color[i];
    for(int i=limc;i>=0;i--)
        cover(x1[i],y1[i],x2[i],y2[i],i+1,color[i]);
    for(int i=1;i<=2500;i++)
        if(area[i]>0)cout<<i<<' '<<area[i]<<endl;
}
