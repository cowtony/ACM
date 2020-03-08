#include <stdio.h>
#include <math.h>
#include <memory.h>

double min(double a,double b)
{
  if (a>b)
    return b;
  return a;
}
double max(double a,double b)
{
  if (a>b)
    return a;
  return b;
}

int main(int argc, char* argv[])
{
  int n,d,i,j,t,s,z=0;
  int ax[1010],ay[1010],p[1010];
  double x,r0[1010],r1[1010];
  while (scanf("%d%d",&n,&d) && (n || d))
  {
    memset(p,0,sizeof(p));
    for (i=1;i<=n;i++)
      scanf("%d%d",ax+i,ay+i);
    printf("Case %d: ",++z);

    for (i=1;i<=n;i++)
      if (ay[i]>d)
      {
        printf("-1\n");
        break;
      }
      else
      {
        x=sqrt(d*d-ay[i]*ay[i]);
        r0[i]=ax[i]-x;
        r1[i]=ax[i]+x;
      }

    if (i<=n) continue;

    s=n;

    for (i=1;i<n;i++)
      if (p[i])
        for (j=i+1;j<=n;j++)
          if (p[j])
            if (!(r1[i]<r0[j] || r1[j]<r0[i]))
            {
              s--;
              p[j]=0;
              r0[i]=max(r0[i],r0[j]);
              r1[i]=min(r1[i],r1[j]);
            }

    printf("%d\n",s);
  }
  return 0;
}

