//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

//---------------------------------------------------------------------------

#pragma argsused
#include <stdio.h>
#include <fstream.h>
int sm,s,b[1000010],a[15];
void dfs(int m)
{

  if (m==s)
  {
    if (sm<1e6)
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
  ofstream fout("out2358_p.txt");
  int i,n;
  for (i=0;i<=1e6;i++)
    b[i]=0;

  s=1;
  i=1;
  while (i<=1e6)
  {
    i*=s;
    a[s++]=i;
  }
//  printf("%d",s);

  sm=0;
  dfs(1);
  for (i=0;i<=1e6;i++)
    if (b[i])
      fout<<"  a["<<i<<"]=1;\n";

  printf("a[%d]=1\n",i);

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
 