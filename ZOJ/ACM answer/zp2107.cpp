//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

//---------------------------------------------------------------------------

#pragma argsused
#include <stdio.h>
#include <math.h>
#include <stdlib.h>

struct ptt
{
  double x,y;
};
struct ptt a[100000];

int Cmp(void const *a, void const *b) {

    ptt p1 = *(ptt*)a, p2 = *(ptt*)b;
    if (p1.x+p1.y<p2.x+p2.y)
      return -1;
    return 1;
}

int main(int argc, char* argv[])
{
  int i,j,n;
  double r,v;

  while(scanf("%d",&n) && n)
  {
    for (i=0;i<n;i++)
      scanf("%lf%lf",&a[i].x,&a[i].y);

    qsort(a,n,sizeof(a[0]),Cmp);

    r=(a[0].x-a[1].x)*(a[0].x-a[1].x)+
      (a[0].y-a[1].y)*(a[0].y-a[1].y);

    for (i=0;i<n-1;i++)
    {
      j=i+1;
      v=(a[i].x-a[j].x)*(a[i].x-a[j].x)+
        (a[i].y-a[j].y)*(a[i].y-a[j].y);
      if (v<r)
        r=v;
    }
    r=(sqrt(r)/2);
    printf("%.2lf\n",r);
  }
  return 0;
}
//---------------------------------------------------------------------------
