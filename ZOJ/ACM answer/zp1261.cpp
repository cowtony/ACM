//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

//---------------------------------------------------------------------------

#pragma argsused
#include <stdio.h>

int main(int argc, char* argv[])
{
  char ch;
  int i,j,p[32770],n,s,t,k,f;
  for (i=2;i<=32767;i++)
    p[i]=1;
  for (i=2;i<=32767;i++)
    if (p[i])
    {
      j=i+i;
      while (j<=32767)
      {
        p[j]=0;
        j+=i;
      }
    }

  while (scanf("%d",&n) && n)
  {
    scanf("%d",&k);
    s=1;
    for (i=0;i<k;i++)
      s*=n;
    while (scanf("%c",&ch) && ch!='\n')
    {
      scanf("%d%d",&n,&k);
      for (i=0;i<k;i++)
        s*=n;
    }
    s--;
    if (s>1)
    {
      n=s;
      f=0;
      for (i=n;i>=2;i--)
        if (p[i] && s%i==0)
        {
          t=0;
          while (s%i==0)
          {
            t++;
            s/=i;
          }
          if (f)
            printf(" %d %d",i,t);
          else
          {
            printf("%d %d",i,t);
            f=1;
          }
        }
      printf("\n");
    }
  }
  return 0;
}
//---------------------------------------------------------------------------
