//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

//---------------------------------------------------------------------------

#pragma argsused
#include <stdio.h>
#include <math.h>
int q,s,k,t,r,a[10000];
void dfs(int m)
{
  if (m==s)
  {
    if (k)
      if (k%2)
        t-=q/r;
      else
        t+=q/r;
  }
  else
    for (int i=0;i<=1;i++)
    {
      k+=i;
      if (i)    r*=a[m];
      dfs(m+1);
      if (i)    r/=a[m];
      k-=i;
    }
}
int main(int argc, char* argv[])
{
  int n,i;
  scanf("%d",&n);
  while (n)
  {
    t=n-1;
    s=0;
    q=n;
    i=2;
    while (q>1)
    {
      if (q%i==0)
        a[s++]=i;
      while (q%i==0)
        q/=i;
      if (i*i>=n)
        break;
      i++;

    }
    if (q>1)
      a[s++]=q;
    k=0;
    if (s>1)
    {
      q=n-1;
      r=1;
      dfs(0);
    }
    printf("%d\n",t);
    scanf("%d",&n);
  }
  return 0;
}
//---------------------------------------------------------------------------
