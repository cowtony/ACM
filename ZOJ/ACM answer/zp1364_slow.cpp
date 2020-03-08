
#include <stdio.h>

int n,m,s,t,c,a[110][110],x[220],y[220],p[110],q[110];

void exte(int fm,int md,int ori)
{
  int i,f=1;
  if (md==1 && ori==1)
  {
    for (i=1;i<n;i++)
      if (p[i] && a[i][fm]==2)
        break;
    if (i==n)
    for (i=1;i<n;i++)
      if (p[i] && a[i][fm]==1)
      {
        f=0;
        s++;     x[s]=i;   y[s]=fm;
        p[i]=0;
        exte(i,2,2);
        if (t)             return;
        s--;
        p[i]=1;
      }
  }
  else
  if (md==1 && ori==2)
  {
    for (i=1;i<m;i++)
      if (q[i] && a[fm][i]==2)
        break;
    if (i==m)
    for (i=1;i<m;i++)
      if (q[i] && a[fm][i]==1)
      {
        f=0;
        s++;     x[s]=fm;  y[s]=i;
        q[i]=0;
        exte(i,2,1);
        if (t)             return;
        s--;
        q[i]=1;
      }
  }
  else
  if (md==2 && ori==1)
  {
    for (i=1;i<n;i++)
      if (p[i] && a[i][fm]==2)
      {
        f=0;
        s++;     x[s]=i;   y[s]=fm;
        p[i]=0;
        exte(i,1,2);
        if (t)             return;
        s--;
        p[i]=1;
      }
  }
  else
  if (md==2 && ori==2)
  {
    for (i=1;i<m;i++)
      if (q[i] && a[fm][i]==2)
      {
        f=0;
        s++;     x[s]=fm;  y[s]=i;
        q[i]=0;
        exte(i,1,1);
        if (t)             return;
        s--;
        q[i]=1;
      }
  }

  if (f && md==2)
  {
    for (i=1;i<=s;i++)
      a[x[i]][y[i]]=3-a[x[i]][y[i]];
    t=1;
    c++;
  }
}
int main(int argc, char* argv[])
{
  int k,i,j,g,h;

  scanf("%d",&n);
  while (n)
  {
    scanf("%d%d",&m,&k);
    for (i=1;i<n;i++)
      for (j=1;j<m;j++)
        a[i][j]=0;
    c=0;
    for (i=0;i<k;i++)
    {
      scanf("%d%d%d",&j,&h,&g);
      if (h || g)
        a[h][g]=1;
      if (g==h)
      {
        a[g][h]=2;
        c++;
      }
    }

    while (1)
    {
      t=0;

      for (i=1;i<n;i++)
      {
        for (j=1;j<n;j++)
          p[j]=1;
        for (j=1;j<m;j++)
          q[j]=1;
        s=0;
        p[i]=0;
        exte(i,1,2);
      }

      for (i=1;i<m;i++)
      {
        for (j=1;j<n;j++)
          p[j]=1;
        for (j=1;j<m;j++)
          q[j]=1;
        s=0;
        q[i]=0;
        exte(i,1,1);
      }

      if (t==0)
        break;
    }

    printf("%d\n",c);
    scanf("%d",&n);
  }
  return 0;
}
//---------------------------------------------------------------------------
