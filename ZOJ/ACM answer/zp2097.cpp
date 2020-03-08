//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

//---------------------------------------------------------------------------

#pragma argsused

#include <iostream.h>
struct typec
{
  int x,y,s;
};
typec p[10000];
int xx[4]={1,0,-1,0};
int yy[4]={0,-1,0,1};

int main(int argc, char* argv[])
{
  int mn,pf,sf,x0,y0,x1,y1,mx,my,mc,nx,ny,nc,i,j,k;
  int a[10][10],cost[5][10][10];
  cin>>x0>>y0>>x1>>y1;
  while (x0+y0+x1+y1)
  {

    p[0].x=x0;
    p[0].y=y0;
    p[0].s=1;

    for (i=1;i<=8;i++)
      for (j=1;j<=8;j++)
        cin>>a[i][j];
    if (x0==x1 && y0==y1)
    {
      cout<<0<<endl;
      cin>>x0>>y0>>x1>>y1;
      continue;
    }
    for (i=0;i<=8;i++)
      for (j=0;j<=8;j++)
        for (k=0;k<=4;k++)
          cost[k][i][j]=0;

    pf=0;sf=1;
    while (pf<sf)
    {
      mx=p[pf].x;
      my=p[pf].y;
      mc=p[pf].s;
      for (i=0;i<4;i++)
      {
        nx=mx+xx[i];
        ny=my+yy[i];
        nc=mc*a[nx][ny];
        if (nx>0 && nx<9 && ny>0 && ny<9)
          if (cost[nc%4+1][nx][ny]==0
           || cost[mc][mx][my]+nc<cost[nc%4+1][nx][ny])
          {
            cost[nc%4+1][nx][ny]=cost[mc][mx][my]+nc;
            p[sf].x=nx;
            p[sf].y=ny;
            p[sf].s=nc%4+1;
            sf++;
          }
      }
      pf++;
    }
    mn=0;
    for (i=1;i<=4;i++)
      if (cost[i][x1][y1] && cost[i][x1][y1]<mn || mn==0)
        mn=cost[i][x1][y1];
    cout<<mn<<endl;

    cin>>x0>>y0>>x1>>y1;
  }
  return 0;
}
//---------------------------------------------------------------------------
