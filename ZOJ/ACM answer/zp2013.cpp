//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

//---------------------------------------------------------------------------

#pragma argsused
#include <stdio.h>
#include <string>
using namespace std;

int n,m,mx,xx,yy,a[1010][1010];

void dfs(int x,int y,int d)
{
  int t=0;

  a[x][y]=1;

    if (x>0 && a[x-1][y]==0)
    {
      dfs(x-1,y,d+1);
      t++;
    }
    if (y>0 && a[x][y-1]==0)
    {
      dfs(x,y-1,d+1);
      t++;
    }
    if (x<n-1 && a[x+1][y]==0)
    {
      dfs(x+1,y,d+1);
      t++;
    }
    if (y<m-1 && a[x][y+1]==0)
    {
      dfs(x,y+1,d+1);
      t++;
    }

  a[x][y]=0;

  if (t==0)
    if (d>mx)
    {
      mx=d;
      xx=x;
      yy=y;
    }
}
int main(int argc, char* argv[])
{

  int i,j,N,I;
  char st[1010];
  scanf("%d",&N);
  for (I=0;I<N;I++)
  {
    scanf("%d %d",&m,&n);
    for (i=0;i<n;i++)
    {
      scanf("%s",st);
      for (j=0;j<m;j++)
        if (st[j]=='#')
          a[i][j]=1;
        else
          a[i][j]=0;
    }
    mx=0;
    for (i=0;i<n;i++)
    {
      for (j=0;j<m;j++)
        if (a[i][j]==0)
        {
          dfs(i,j,0);
          break;
        }
      if (j<m) break;
    }

    dfs(xx,yy,0);

    printf("Maximum rope length is %d.\n",mx);
  }
  return 0;
}
//---------------------------------------------------------------------------
