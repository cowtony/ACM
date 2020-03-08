//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

//---------------------------------------------------------------------------

#pragma argsused
#include <stdio.h>
#include <math.h>
int main(int argc, char* argv[])
{
  int N,I,r,i,x,n;
  scanf("%d",&N);
  for (I=0;I<N;I++)
  {
    if (I) printf("\n");
    scanf("%d",&n);
    if (n<5)
    {
      printf("%d\n",n);
      continue;
    }
    x=-1+sqrt(8*n+9);
    x/=2;

    r=n-x*(x+1)/2+1;

    for (i=2;i<x;i++)
      if (i+r>x)
        printf("%d ",i+1);
      else
        printf("%d ",i);
    if (r==x)
      x+=2;
    else
      x+=(r>0);

    printf("%d\n",x);
  }
  return 0;
}
//---------------------------------------------------------------------------
