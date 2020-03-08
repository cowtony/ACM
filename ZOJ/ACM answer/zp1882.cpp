#include <stdio.h>

struct coordinate
{
  double x,y;
}g[100],hole;

double dist(coordinate a,coordinate b)
{
  return (a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y);
}

int r[100],m,n,mat[100][100],p[200];

int find(int d)
{
  int i;
  r[d]=0;
  for (i=0;i<n;i++)
    if (mat[i][d])
      if (p[m+i]>-1)
      {
        if (r[p[m+i]] && find(p[m+i]))
        {
          p[m+i]=d;
          p[d]=m+i;
          return 1;
        }
      }
      else
      {
        p[m+i]=d;
        p[d]=m+i;
        return 1;
      }

  return 0;
}

int main(int argc, char* argv[])
{
  int s,v,i,j;
  while (scanf("%d%d%d%d",&n,&m,&s,&v)>0)
  {
    s*=v;
    for (i=0;i<n;i++)
      scanf("%lf%lf",&g[i].x,&g[i].y);
    for (i=0;i<m;i++)
    {
      scanf("%lf%lf",&hole.x,&hole.y);
      for (j=0;j<n;j++)
        if (dist(g[j],hole)<=s*s)
          mat[j][i]=1;
        else
          mat[j][i]=0;
    }

    for (i=0;i<m+n;i++)
      p[i]=-1;
    s=n;

    for (i=0;i<m;i++)
      if (p[i]==-1)
      {
        for (j=0;j<m;j++)
          r[j]=1;
        if (find(i)) s--;
      }
    printf("%d\n",s);
  }
  return 0;
}
//---------------------------------------------------------------------------
