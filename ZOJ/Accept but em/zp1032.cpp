//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

//---------------------------------------------------------------------------

#pragma argsused

#include <stdio.h>
#include <stdlib.h>

struct ptt
{
  int x,y;
};
struct ptt a[100];

int n,xl,xr,yd,yu;
/*int det(int x1,int y1,int x2,int y2,int x3,int y3)
{
  return (x1-x3)*(y2-y3)-(x2-x3)*(y1-y3);
}
int onborder(int x,int y)
{
  int i;
  for (i=0;i<n;i++)
    if (det(a[i].x,a[i].y,x,y,a[i+1].x,a[i+1].y)==0)
      if ((a[i].x-x)*(x-a[i+1].x)>=0 && (a[i].y-y)*(y-a[i+1].y)>=0)
        break;
  if (i==n)
    return 0;
  return 1;
}
int within(int x,int y)
{
  if (onborder(x,y))
    return 0;
  int j,i=0,t=0;
  while (a[i].y==y && a[i].x>x && i<n)
    i++;
  if (i==n)
    return 0;
  for (;i<n;i++)
  {
    j=i;
    while (a[(i+1)%n].y==y && a[(i+1)%n].x>x)
      i++;
    if (i==j)
    {
      if (det(x,y,a[i].x,a[i].y,xr+1,y)*det(x,y,a[i+1].x,a[i+1].y,xr+1,y)<0
       && det(a[i].x,a[i].y,x,y,a[i+1].x,a[i+1].y)*det(a[i].x,a[i].y,xr+1,y,a[i+1].x,a[i+1].y)<0)
        t++;
    }
    else
    {
      if ((a[(i+1)%n].y-y)*(y-a[j].y)>0)
        t++;
    }
  }
  if (t%2)
    return 1;
  return 0;
}
*/

int main(int argc, char* argv[])
{
  int I,N,i,x,y,t,s,r;
  scanf("%d",&N);
  for (I=0;I<N;I++)
  {
    printf("Scenario #%d:\n",I+1);
    scanf("%d",&n);
    a[0].x=0;
    a[0].y=0;
    xl=0;
    xr=0;
    yd=0;
    yu=0;
    for (i=1;i<=n;i++)
    {
      scanf("%d%d",&x,&y);
      a[i].x=a[i-1].x+x;
      a[i].y=a[i-1].y+y;
/*
      if (a[i].x<xl)
        xl=a[i].x;
      if (a[i].x>xr)
        xr=a[i].x;

      if (a[i].y<yd)
        yd=a[i].y;
      if (a[i].y>yu)
        yu=a[i].y;
*/
    }

/*
    s=0;
    for (x=xl+1;x<xr;x++)
      for (y=yd+1;y<yu;y++)
        s+=within(x,y);
*/
    r=0;
    for (i=0;i<n;i++)
    {
      x=abs(a[i+1].x-a[i].x);
      y=abs(a[i+1].y-a[i].y);
      if (x && y)
      {
        t=x%y;
        while (t)
        {
          x=y;
          y=t;
          t=x%y;
        }
        r+=y;
      }
      else
        r+=x+y;
    }

    s=0;
    for (i=1;i<n-1;i++)
      s+=a[i].x*a[i+1].y-a[i+1].x*a[i].y;

    i=s/2.0+1-r/2.0;
    printf("%d %d %.1lf\n\n",i,r,s/2.0);
  }
  return 0;
}
//---------------------------------------------------------------------------
