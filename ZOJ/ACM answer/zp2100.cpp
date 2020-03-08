//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

//---------------------------------------------------------------------------

#pragma argsused
#include <stdio.h>
int s,t,m,n,p[10][10];
char st[10][10];
void dfs(int x,int y,int d)
{
  if (d==s)
    t=1;
  else
  {
    p[x][y]=0;
    if (x>0 && st[x-1][y]!='S' && p[x-1][y]==1)
      dfs(x-1,y,d+1);
    if (t) return;
    if (y>0 && st[x][y-1]!='S' && p[x][y-1]==1)
      dfs(x,y-1,d+1);
    if (t) return;
    if (x<n-1 && st[x+1][y]!='S' && p[x+1][y]==1)
      dfs(x+1,y,d+1);
    if (t) return;
    if (y<m-1 && st[x][y+1]!='S' && p[x][y+1]==1)
      dfs(x,y+1,d+1);
    if (t) return;
    p[x][y]=1;
  }
}
int main(int argc, char* argv[])
{
  int i,j;
  while (scanf("%d%d",&n,&m) && m && n)
  {
    s=0;
    for (i=0;i<n;i++)
    {
      scanf("%s",st[i]);
      for (j=0;j<m;j++)
      {
        if (st[i][j]!='S')
        {
          s++;
          p[i][j]=1;
        }
        else
          p[i][j]=0;
      }
    }
    t=0;
    if (st[0][0]!='S')
      dfs(0,0,1);
    if (t || s==0)
      printf("YES\n");
    else
      printf("NO\n");
  }
  return 0;
}
//---------------------------------------------------------------------------
