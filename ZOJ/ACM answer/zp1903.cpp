#include <stdio.h>

  int n,s,mx,a[20][20],d[20],p[20];

void seac(int w)
{
  if (w)
  {
    int i,j;
    for (i=0;i<n;i++)
      if (d[i]%2 && p[i])
      {
        for (j=i+1;j<n;j++)
          if (d[j]%2 && p[j])
          {
            p[i]=0;
            p[j]=0;
            s+=a[i][j];
            seac(w-2);
            p[i]=1;
            p[j]=1;
            s-=a[i][j];
          }
        break;
      }
  }
  else
    if (s<mx || mx==0)
      mx=s;
}
int main(int argc, char* argv[])
{
//   FILE *in=fopen("zp1903.in","r");
//   FILE *out=fopen("output.txt","w");

  int m,i,j,k,sum,x,y,c;
  while (scanf("%d",&n) && n)
  {
    scanf("%d",&m);
    for (i=0;i<n;i++)
      d[i]=0;
    for (i=0;i<n;i++)
      for (j=0;j<n;j++)
        a[i][j]=-1;

    sum=0;
    for (i=0;i<m;i++)
    {
      scanf("%d%d%d",&x,&y,&c);
      if (a[x-1][y-1]==-1 || a[x-1][y-1]>c)
      {
        a[x-1][y-1]=c;
        a[y-1][x-1]=c;
      }
      d[x-1]++;
      d[y-1]++;
      sum+=c;
    }

    for (i=0;i<n;i++)    if (d[i]%2)
      for (j=0;j<n;j++)    if (i!=j && d[j]%2)
        for (k=0;k<n;k++)
          if (a[i][k]>-1 && a[k][j]>-1)
            if (a[i][j]>a[i][k]+a[k][j] || a[i][j]==-1)
              a[i][j]=a[i][k]+a[k][j];

    for (i=0;i<n;i++)    if (d[i]%2)
      for (j=0;j<n;j++)    if (i!=j && d[j]%2)
        for (k=0;k<n;k++)
          if (a[i][k]>-1 && a[k][j]>-1)
            if (a[i][j]>a[i][k]+a[k][j] || a[i][j]==-1)
              a[i][j]=a[i][k]+a[k][j];

    k=0;
    for (i=0;i<n;i++)
      if (d[i]%2)
        k++;

    mx=0;
    s=0;

    for (i=0;i<n;i++)
      p[i]=1;

    seac(k);

    sum+=mx;
    printf("%d\n",sum);
  }
  return 0;
}
//---------------------------------------------------------------------------
