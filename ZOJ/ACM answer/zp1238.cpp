//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

//---------------------------------------------------------------------------

#pragma argsused
#include <stdio.h>
#include <math.h>
#include <string.h>

int main(int argc, char* argv[])
{
  int N,I,k,m,i,n,ln,r[100001];
  char st[500010];
  for (i=1;i<=100000;i++)
    r[i]=i*log(i)/log(10)+1;

  scanf("%d",&N);
  for (I=0;I<N;I++)
  {
    scanf("%s",st);
    ln=strlen(st);
    if (ln==1)
    {
      if (st[0]=='4')
        printf("2\n");
      else
      if (st[0]=='1')
        printf("1\n");
      else
        printf("-1\n");
    }
    else
    {
      for (i=3;i<=100000;i++)
        if (ln<=r[i])
          break;
      if (ln==r[i])
      {
        n=i;
        k=0;
        for (i=0;i<ln;i++)
        {
          k*=10;
          k+=st[i]-'0';
          k%=99;
        }
        m=1;
        for (i=1;i<=n;i++)
        {
          m*=n;
          m%=99;
        }
        if (m==k)
          printf("%d\n",n);
        else
          printf("-1\n");
      }
      else
        printf("-1\n");
    }
  }
  return 0;
}
//---------------------------------------------------------------------------
