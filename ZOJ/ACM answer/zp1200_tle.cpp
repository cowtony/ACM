//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

//---------------------------------------------------------------------------

#pragma argsused
#include <stdio.h>

int main(int argc, char* argv[])
{
  int i,j,p,q,t,m,n,s,w,c,k,sm,v;
  while (scanf("%d%d%d%d%d",&s,&w,&c,&k,&m)>0)
  {
    n=2*s+w;
    if (k==1 || (9999/c)*n<=m)
    {
      printf("%d\n",((9999/c)+1)*n+m);
      continue;
    }

    p=n;
    q=m;
    t=p%q;
    while (t)
    {
      p=q;
      q=t;
      t=p%q;
    }
    n/=q;
    m/=q;
    sm=0;
    v=1;
    for (i=m+1;;i++)
    {
      p=i;
      for (j=1;j<=v;j++)
      {
        p-=m;
        if (p%n==0)
        {
          sm+=c;
          break;
        }
      }
      if (sm>=10000)
        break;
      if (i%m==0 && i/m<=k)
        v++;
    }
    printf("%d\n",i*q);
  }
  return 0;
}
//---------------------------------------------------------------------------
