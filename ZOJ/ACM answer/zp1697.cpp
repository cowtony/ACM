//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

//---------------------------------------------------------------------------

#pragma argsused
#include <stdio.h>
int a[6][5],en,sm,mx,p[6];
void dfs(int d,int ck)
{
  if (d==6)
  {
    if (ck==en)
      if (sm>mx)
        mx=sm;
  }
  else
  {
    int i,j;
    for (i=1;i<6;i++)
      if (p[i])
      {
        p[i]=0;
        for (j=0;j<3;j++)
          if (a[i][j+2]==ck)
          {
            sm+=a[i][j];
            dfs(d+1,a[i][j+1]);
            sm-=a[i][j];
          }
        p[i]=1;
      }
  }
}
int main(int argc, char* argv[])
{
  int i;
  char st[3];
  while (1)
  {
    for (i=0;i<6;i++)
    {
      scanf("%d%d%d",&a[i][0],&a[i][1],&a[i][2]);
      a[i][3]=a[i][0];
      a[i][4]=a[i][1];
    }
    for (i=1;i<6;i++)
      p[i]=1;
    p[0]=0;
    mx=-1;
    for (i=0;i<3;i++)
    {
      sm=a[0][i];
      en=a[0][i+2];
      dfs(1,a[0][i+1]);
    }
    if (mx<0)
      printf("none\n");
    else
      printf("%d\n",mx);
    scanf("%s",st);
    if (st[0]=='$')
      break;
  }
  return 0;
}
//---------------------------------------------------------------------------
