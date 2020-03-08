//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

//---------------------------------------------------------------------------

#pragma argsused
#include <stdio.h>

int main(int argc, char* argv[])
{
  int i,j,k,n,m,x,t,c,d,
      I,a[100][100],p[100][100],r[100][100],v[100][100];
  while (scanf("%d",&n) && n)
  {
    for (i=0;i<n;i++)
    {
      for (j=0;j<n;j++)
        a[i][j]=0;
      scanf("%d",&m);
      for (j=0;j<m;j++)
      {
        scanf("%d%d",&x,&t);
        a[i][x-1]=t;
      }
      for (j=0;j<n;j++)
      {
        r[i][j]=a[i][j];
        v[i][j]=a[i][j];
      }
    }
    for (I=0;I<n;I++)
    {
      for (i=0;i<n;i++)
        for (j=0;j<n;j++)
          p[i][j]=0;

      for (i=0;i<n;i++)
        for (j=0;j<n;j++)
          if (i!=j && r[i][j])
            for (k=0;k<n;k++)
              if (k!=i && k!=j && a[j][k])
              {
                if (p[i][k]==0
                 || r[i][j]+a[j][k]<p[i][k])
                  p[i][k]=r[i][j]+a[j][k];
              }

      for (i=0;i<n;i++)
        for (j=0;j<n;j++)
        {
          r[i][j]=p[i][j];
          if (p[i][j])
            if (v[i][j]==0 || p[i][j]<v[i][j])
            v[i][j]=p[i][j];
        }
    }
    c=-1;
    d=-1;
    for (i=0;i<n;i++)
    {
      t=0;
      for (j=0;j<n;j++)
        if (i!=j && v[i][j]==0)
          break;
        else
          if (v[i][j]>t)
            t=v[i][j];
      if (j==n)
        if (d==-1 || t<d)
        {
          d=t;
          c=i;
        }
    }
    if (c==-1)
      printf("disjoint\n");
    else
      printf("%d %d\n",c+1,d);
  }
  return 0;
}
//---------------------------------------------------------------------------
