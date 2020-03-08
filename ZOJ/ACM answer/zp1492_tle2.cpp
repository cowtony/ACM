//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

//---------------------------------------------------------------------------

#pragma argsused
#include <stdio.h>
int r[52],a[52][52],n,s,mx;
void dfs()
{
  int i,j;
  for (i=0;i<n;i++)
    if (r[i]==0)
    {
      for (j=0;j<n;j++)
        if (r[j]==1)
          if (a[i][j]==0)
            break;
      if (j==n)
      {
        s++;
        if (s>mx)
          mx=s;
        for (j=0;j<n;j++)
          if (r[j]==1)
          {
            a[i][j]=-1;
            a[j][i]=-1;
          }
        r[i]=1;
        dfs();
        s--;
        r[i]=0;
      }
    }
}
int main(int argc, char* argv[])
{
  int i,j;
  while (scanf("%d",&n) && n)
  {
    for (i=0;i<n;i++)
      r[i]=0;
    for (i=0;i<n;i++)
      for (j=0;j<n;j++)
        scanf("%d",&a[i][j]);
    mx=0;
    for (i=0;i<n-1;i++)
    {
      for (j=i+1;j<n;j++)
        if (a[i][j]==1)
        {
          r[i]=1;
          r[j]=1;
          s=2;
          a[i][j]=-1;
          a[j][i]=-1;
          dfs();
          if (mx>=n-1)
            break;
          r[i]=0;
          r[j]=0;
        }
      if (j<n)
        break;
    }

    printf("%d\n",mx);
  }
  return 0;
}
//---------------------------------------------------------------------------
