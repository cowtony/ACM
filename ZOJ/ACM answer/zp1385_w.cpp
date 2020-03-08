//---------------------------------------------------------------------------

#pragma hdrstop

//---------------------------------------------------------------------------

#pragma argsused

#include <stdio.h>
int main(int argc, char* argv[])
{
  int N,I,n,m,i,k,c;
  scanf("%d",&N);

  for( I=0;I<N;I++)
  {
    scanf("%d%d",&n,&m);

        c=0;k=m-1;
        while (k>1)
        { k/=2; c++; }

        for (i=0;i<c;i++)
          k*=2;
        c=k;
        n-=m;    n%=c;   c/=2;

        if (c==0)
          printf("1\n");
        else
        {
          m=(m+1)/2-c-1;   c/=2;
          while (c>1)
          {
            if (m/c>0 && n/c>0)
            { printf("0\n"); break;  }
            else
            { m%=c; n%=c; c/=2; }
          }
          if (c<=1)
            if (m>0 && n>0) printf("0\n");
            else            printf("1\n");
        }
  }
  return 0;
}
//---------------------------------------------------------------------------
