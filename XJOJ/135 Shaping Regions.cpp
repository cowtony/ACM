/*
N个不同的颜色的不透明的长方形(1 <= N <= 1000)被放置在一张横宽为A竖长为B的白纸上。
这些长方形被放置时，保证了它们的边与白纸的边缘平行。所有的长方形都放置在白纸内，所以我们会看到不同形状的各种颜色。
坐标系统的原点(0,0)设在这张白纸的左下角，而坐标轴则平行于边缘。

矩形切割加递归上浮的方法
先顺序读入放纸的信息，再逆序计算能看见的面积，从最上面一张开始，逐渐加纸上浮，被其上的所有矩形切掉后剩下的就是表面能看到的颜色 
每次上浮，如果被其他纸盖到，就将该矩形切割成4块，这四块继续递归上浮
切割方法看USACO中的解释 

关键词：难题！！！好题！！有思想
*/
#include<iostream>
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
    x1[0]=y1[0]=0;
    cin>>x2[0]>>y2[0]>>limc;

    for(int i=1;i<=limc;i++)
        cin>>x1[i]>>y1[i]>>x2[i]>>y2[i]>>color[i];
    for(int i=limc;i>=0;i--)
        cover(x1[i],y1[i],x2[i],y2[i],i+1,color[i]);
    for(int i=1;i<=2500;i++)
        if(area[i]>0)cout<<i<<' '<<area[i]<<endl;
}
