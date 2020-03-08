//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

//---------------------------------------------------------------------------

#pragma argsused
#include <stdio.h>

struct pointa
{
  int x,y;
};
struct pointa a[100];

int n,rght;
int det(int x1,int y1,int x2,int y2,int x3,int y3)
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
    return 1;
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
      if (det(x,y,a[i].x,a[i].y,rght,y)*det(x,y,a[i+1].x,a[i+1].y,rght,y)<0
       && det(a[i].x,a[i].y,x,y,a[i+1].x,a[i+1].y)*det(a[i].x,a[i].y,rght,y,a[i+1].x,a[i+1].y)<0)
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
int main(int argc, char* argv[])
{
  int m,f,i,x,y,cs=0;
  while (scanf("%d",&n) && n)
  {
    scanf("%d",&m);
    f=0;
    for (i=0;i<n;i++)
    {
      scanf("%d%d",&a[i].x,&a[i].y);
      if (f==0 || a[i].x>rght)
      {
        f=1;
        rght=a[i].x;
      }
    }
    rght++;
    a[n].x=a[0].x;
    a[n].y=a[0].y;
    if (cs)
      printf("\n");

    printf("Problem %d:\n",++cs);
    for (i=0;i<m;i++)
    {
      scanf("%d%d",&x,&y);
      if (x<rght && within(x,y))
        printf("Within\n");
      else
        printf("Outside\n");
    }
  }
  return 0;
}
//---------------------------------------------------------------------------
