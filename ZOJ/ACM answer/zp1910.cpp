//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

//---------------------------------------------------------------------------

#pragma argsused
#include <stdio.h>
#include <math.h>

int main(int argc, char* argv[])
{
  int N,I,i,j,n,m,mn;
  scanf("%d",&N);
  for (I=0;I<N;I++)
  {
    scanf("%d",&n);
    i=pow(n,1.0/3)+1e-5;
    //printf("%d\n",i);
    mn=0;
    for (;i>0;i--)
      if (n%i==0)
      {
        m=n/i;
        j=sqrt(m)+1e-5;
        for (;j>0;j--)
          if (m%j==0)
          {
            if (mn==0 || (i*j+n/i+n/j)*2<mn)
              mn=(i*j+n/i+n/j)*2;
          }
      }
    printf("%d\n",mn);
  }
  return 0;
}
//---------------------------------------------------------------------------
