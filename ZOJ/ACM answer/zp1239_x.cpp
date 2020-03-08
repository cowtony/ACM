//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

//---------------------------------------------------------------------------

#pragma argsused
#include <stdio.h>
#include <math.h>

int main(int argc, char* argv[])
{
  int n,i,a[51],s,m,x;
  for (n=1;n<51;n++)
  {
    for (i=1;i<=n;i++)
      a[i]=0;
    s=1;
    a[1]=s++;
    m=1;
    while (1)
    {
      for (i=1;i<=m;i++)
      {
        x=sqrt(a[i]+s);
        if (a[i]+s==x*x)
        {
          a[i]=s++;
          break;
        }
      }
      if (i>m)
        if (m==n)
          break;
        else
          a[++m]=s++;
    }
    printf("  a[%d]=%d;\n",n,s-1);

  }
  return 0;
}
//---------------------------------------------------------------------------
