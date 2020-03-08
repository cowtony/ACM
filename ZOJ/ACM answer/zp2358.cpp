//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

//---------------------------------------------------------------------------

#pragma argsused
#include <stdio.h>
//#include <fstream.h>
int sm,s,b[1000010],a[15];
void dfs(int m)
{

  if (m==s)
  {
    if (sm<=1000000)
      b[sm]=1;
  }
  else
  {
    for (int i=0;i<2;i++)
    {
      sm+=i*a[m];
      dfs(m+1);
      sm-=i*a[m];
    }
  }
}
int main(int argc, char* argv[])
{
  //ofstream fout("out2358_p.txt");
  int i,n;
  for (i=0;i<=1000000;i++)
    b[i]=0;

  s=1;
  i=1;
  while (i<=1000000)
  {
    i*=s;
    a[s++]=i;
  }

  sm=0;
  a[0]=1;
  dfs(0);

  b[0]=0;
  while (scanf("%d",&n) && n>=0)
  {
    if (b[n])
      printf("YES\n");
    else
      printf("NO\n");
  }
  return 0;
}
//---------------------------------------------------------------------------
