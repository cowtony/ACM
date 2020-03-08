#include <stdio.h>

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
  int s,i,j,k,x,y;
  while (scanf("%d%d%d",&n,&m,&k)>0)
  {
    for (i=0;i<n;i++)
      for (j=0;j<m;j++)
        mat[i][j]=0;

    for (i=0;i<k;i++)
    {
      scanf("%d%d%d",&j,&x,&y);
      if (x && y)
        mat[x-1][y-1]=1;
    }
    m--;
    n--;

    for (i=0;i<m+n;i++)
      p[i]=-1;
    s=0;

    for (i=0;i<m;i++)
      if (p[i]==-1)
      {
        for (j=0;j<m;j++)
          r[j]=1;
        if (find(i)) s++;
      }
    printf("%d\n",s);
  }
  return 0;
}
//---------------------------------------------------------------------------
