#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct cr_type
{
  int x,y;
} cr[500];

struct msty
{
  int v1,v2,num;
} rp[125000];

int cmp(const void *a,const void *b)
{
  msty p1=*(msty *)a,p2=*(msty *)b;
  if (p1.num<p2.num)  return -1;
  if (p1.num>p2.num)  return 1;
  return 0;
}

int main(int argc, char* argv[])
{

  int N,n,m,t,s,i,j,b,p[500];
  scanf("%d",&N);
  while (N--)
  {
    scanf("%d%d",&m,&n);
    for (i=0;i<n;i++)
      scanf("%d%d",&cr[i].x,&cr[i].y);
    s=0;
    for (i=0;i<n;i++)
      for (j=i+1;j<n;j++)
      {
        rp[s].v1=i;
        rp[s].v2=j;
        rp[s++].num=(cr[i].x-cr[j].x)*(cr[i].x-cr[j].x)
                   +(cr[i].y-cr[j].y)*(cr[i].y-cr[j].y);
      }

    qsort(rp,s,sizeof(msty),cmp);

    for (i=0;i<n;i++)
      p[i]=i;

    b=n-m;
    s=-1;
    m=0;
    while (m<b)
    {
      s++;
      if (p[rp[s].v1]!=p[rp[s].v2])
      {
        m++;
        t=p[rp[s].v2];
        for (i=0;i<n;i++)
          if (p[i]==t)
            p[i]=p[rp[s].v1];
      }
    }
    printf("%.2f\n",sqrt(rp[s].num));
  }
  return 0;
}
//---------------------------------------------------------------------------
