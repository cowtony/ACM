#include <stdio.h>

int main(int argc, char* argv[])
{
  int cs,n,m,i,j,k,l,a[110],b[110],p[110][110];
  scanf("%d",&cs);

  for (i=0;i<=110;i++)
    p[i][0]=p[i][1]=0;
  for (j=0;j<=110;j++)
    p[0][j]=p[1][j]=0;

  while (cs--)
  {
    scanf("%d%d",&n,&m);
    for (i=1;i<=n;i++)
      scanf("%d",a+i);
    for (i=1;i<=m;i++)
      scanf("%d",b+i);
    for (i=2;i<=n;i++)
      for (j=2;j<=m;j++)
      {
        p[i][j]=0;
        for (k=1;k<=i;k++)
          for (l=1;l<=j;l++)
            if (p[k][l]>p[i][j])
              p[i][j]=p[k][l];
        if (a[i]!=b[j])
          for (k=1;k<i;k++)
            for (l=1;l<j;l++)
              if (a[i]==b[l] && b[j]==a[k])
                if (p[i][j]<p[k-1][l-1]+1)
                  p[i][j]=p[k-1][l-1]+1;
      }
    printf("%d\n",p[n][m]*2);
  }
  return 0;
}

