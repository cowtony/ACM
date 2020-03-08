/*
有N<=100张海报，坐标均在-2000到2000，求重叠最多的地方最多重叠了多少层

递归上浮加矩形切割的思路
具体见USACO 3.1.4题

关键词：递归，有思想 
*/
#include<iostream>
using namespace std;

int N;
int x1[100],x2[100],y1[100],y2[100];
int maxn;

void cover(int dx,int dy,int ux,int uy,int f,int c)
{
    //cout<<dx<<','<<dy<<' '<<ux<<','<<uy<<endl;
    while(f<N && (dx>=x2[f] || ux<=x1[f] || dy<=y2[f] || uy>=y1[f]))f++;//if the two rectangles are not overlap,come-up~
    if(f==N){maxn=max(maxn,c);return;}//when it comes to the topside,add its acreage
    
    if(dx<x1[f]){cover(dx,dy,x1[f],uy,f+1,c);dx=x1[f];}
    if(ux>x2[f]){cover(x2[f],dy,ux,uy,f+1,c);ux=x2[f];}
    if(dy>y1[f]){cover(dx,dy,ux,y1[f],f+1,c);dy=y1[f];}
    if(uy<y2[f]){cover(dx,y2[f],ux,uy,f+1,c);uy=y2[f];}
    if(dx<ux && dy>uy)cover(dx,dy,ux,uy,f+1,c+1);
}

int main()
{
    //freopen("aaa.txt","r",stdin);
    int T;
    cin>>T;
    while(T--)
    {
        cin>>N;
        int final_max=1;
        
        for(int i=0;i<N;i++)
            cin>>x1[i]>>y1[i]>>x2[i]>>y2[i];
            
        for(int i=0;i<N;i++)
        {
            maxn=1;
            cover(x1[i],y1[i],x2[i],y2[i],i+1,1);
            final_max=max(final_max,maxn);
        }
        
        cout<<final_max<<endl;
    }
    //while(1);
}
