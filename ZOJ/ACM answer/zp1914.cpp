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
int sm;

void swap(msty &a,msty &b)
{
  msty t=a;a=b;b=t;
}
void slpdown(int r)
{
  while (r<sm/2)
  {
    if (r*2+2==sm)
    {
      if (rp[r].num>=rp[r*2+1].num)
        swap(rp[r],rp[r*2+1]);
      r*=2; r++;
    }
    else
    {
      if (rp[r].num>rp[r*2+1].num &&
          rp[r*2+1].num<=rp[r*2+2].num)
      {
        swap(rp[r],rp[r*2+1]);
        r*=2; r+=1;
      }
      else
      if (rp[r].num>rp[r*2+2].num &&
          rp[r*2+2].num<=rp[r*2+1].num)
      {
        swap(rp[r],rp[r*2+2]);
        r*=2; r+=2;
      }
      else
      if (rp[r].num<=rp[r*2+2].num &&
          rp[r].num<=rp[r*2+1].num)
        return;
    }
  }
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
    sm=s;

    for (i=sm/2-1;i>=0;i--)
      slpdown(i);

    for (i=0;i<n;i++)
      p[i]=i;

    b=n-m;
    m=0;
    while (m<b)
    {
      if (p[rp[0].v1]!=p[rp[0].v2])
      {
        m++;
        t=p[rp[0].v2];
        for (i=0;i<n;i++)
          if (p[i]==t)
            p[i]=p[rp[0].v1];
      }
      if (m<b)
      {
        swap(rp[0],rp[sm-1]);
        slpdown(0);
        sm--;
      }
    }
    printf("%.2f\n",sqrt(rp[0].num));
  }
  return 0;
}
//---------------------------------------------------------------------------
