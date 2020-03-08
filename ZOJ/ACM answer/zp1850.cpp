//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

//---------------------------------------------------------------------------

#pragma argsused
#include <stdio.h>
#include <math.h>

int main(int argc, char* argv[])
{
  int n,m,q,i,j,s,a[10000],b[10000];
  while (scanf("%d %d",&m,&n)!=EOF)
  {
    if (n==0)
    {
      printf("0 does not divide %d!\n",m);
      continue;
    }
    q=n;
    i=2;
    s=0;
    while (q>1)
    {
      if (q%i==0)
      {
        a[++s]=0;
        b[s]=i;
        while (q%i==0)
        {
          a[s]++;
          q/=i;
        }
      }
      i++;
      if (i>sqrt(n))
        break;
    }
    if (q>1)
    {
      a[++s]=1;
      b[s]=q;
    }

    for (i=s;i>0;i--)
    {
      j=1;
      while (j<=a[i])
      {
        if (b[i]*j>m)
          break;
        j++;
      }
      if (j<=a[i])
        break;
    }

    if (i==0)
      printf("%d divides %d!\n",n,m);
    else
      printf("%d does not divide %d!\n",n,m);
  }
  return 0;
}
//---------------------------------------------------------------------------
