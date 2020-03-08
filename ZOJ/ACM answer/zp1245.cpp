//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

//---------------------------------------------------------------------------

#pragma argsused
#include <stdio.h>

int main(int argc, char* argv[])
{
  int i,j,n,s,sm,mx,wd,a[110][210],cs=0;
  char st[110][210];
  while (scanf("%d",&n) && n)
  {
    for (i=0;i<n;i++)
    {
      scanf("%s",st[i]);
      s=1;
      for (j=0;j<i;j++)
        a[i][j]=-1;
      for (j=n*2-i-1;j<=n*2-2;j++)
        a[i][j]=-1;
      for (j=i;j<n*2-i-1;j++)
        if (st[i][j-i]=='#')
        {
          s=1;
          a[i][j]=0;
        }
        else
          a[i][j]=s++;
    }

    mx=0;
    for (i=0;i<n;i++)
      for (j=i+1;j<(n-1)*2;j+=2)
        if (a[i][j]>0)
        {
          wd=1; sm=0;
          while (1)
          {
            sm+=wd*2-1;
            if (wd+i<n && j+wd<2*n-2 && j-wd>=0
             && a[i+wd][j+wd]>0 && a[i+wd][j-wd]>0
             && a[i+wd][j+wd]-a[i+wd][j-wd]==wd*2)
              wd++;
            else
              break;
          }
          if (sm>mx)
            mx=sm;
        }

    for (i=0;i<n;i++)
      for (j=i;j<=(n-1)*2;j+=2)
        if (a[i][j]>0)
        {
          wd=1; sm=0;
          while (1)
          {
            sm+=wd*2-1;
            if (i>=wd
             && a[i-wd][j+wd]>0 && a[i-wd][j-wd]>0
             && a[i-wd][j+wd]-a[i-wd][j-wd]==wd*2)
              wd++;
            else
              break;
          }
          if (sm>mx)
            mx=sm;
        }
    printf("Triangle #%d\n",++cs);
    printf("The largest triangle area is %d.\n\n",mx);

  }
  return 0;
}
//---------------------------------------------------------------------------
