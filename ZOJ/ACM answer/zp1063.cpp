//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

//---------------------------------------------------------------------------

#pragma argsused

#include <stdio.h>

int n,m,k;
short a[70][70][70];

void color(int x,int y,int z)
{
  if (a[x][y][z]==0)
  {
    a[x][y][z]=-1;
    if (x<=n)
      color(x+1,y,z);
    if (y<=m)
      color(x,y+1,z);
    if (y>0)
      color(x,y-1,z);
    if (z<=k)
      color(x,y,z+1);
    if (z>0)
      color(x,y,z-1);
    if (x>0)
      color(x-1,y,z);
  }
}
int main(int argc, char* argv[])
{
  int pm,pn,pk,i,j,l,s,w,x;
  short nm[70][70],nk[70][70],mk[70][70];
  while (scanf("%d%d%d%d",&n,&m,&k,&w) && (n||m||k||w))
  {
    for (i=0;i<=n+1;i++)
      for (j=0;j<=m+1;j++)
        for (l=0;l<=k+1;l++)
          a[i][j][l]=0;
    for (i=0;i<w;i++)
    {
      scanf("%d",&x);
      pk=x/(n*m)+1;
      x%=m*n;
      pm=x/n+1;
      pn=x%n+1;
      a[pn][pm][pk]=1;
    }

    color(0,0,0);

    for (i=1;i<=n;i++)
      for (j=1;j<=m;j++)
        nm[i][j]=0;
    for (i=1;i<=n;i++)
      for (l=1;l<=k;l++)
        nk[i][l]=0;
    for (j=1;j<=m;j++)
      for (l=1;l<=k;l++)
        mk[j][l]=0;

    s=0;
    for (i=1;i<=n;i++)
      for (j=1;j<=m;j++)
        for (l=1;l<=k;l++)
          if (a[i][j][l]<0)
          {
            nm[i][j]=0;
            nk[i][l]=0;
            mk[j][l]=0;
          }
          else
          {
            if (nm[i][j]==0)
            {
              s++;
              nm[i][j]=1;
            }
            if (nk[i][l]==0)
            {
              s++;
              nk[i][l]=1;
            }
            if (mk[j][l]==0)
            {
              s++;
              mk[j][l]=1;
            }
          }
    printf("The number of faces needing shielding is %d.\n",s*2);
  }
  return 0;
}
//---------------------------------------------------------------------------
