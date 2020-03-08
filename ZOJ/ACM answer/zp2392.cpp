//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

//---------------------------------------------------------------------------

#pragma argsused
#include <stdio.h>
#include <math.h>

void count(int *a,int n)
{
  int i;
  for (i=0;i<10;i++)
    a[i]=0;

  if (n>0)
  {
    int r,t,k=1,ln;
    //log(n)/log(10)+1;
    k=n;ln=0;
    while (k)
    {
      k/=10;
      ln++;
    }

    k=1;
    for (i=1;i<ln;i++)
    {
      a[0]-=k;
      k*=10;
    }
    a[0]-=k;

    while (ln)
    {
      r=n/k;
      t=n%k;

      for (i=0;i<r;i++)
        a[i]+=k;
      a[r]+=t+1;
      for (i=0;i<10;i++)
        a[i]+=k*(ln-1)*r/10;
      ln--;

      n=t;
      k/=10;
    }
  }
  else
    if (n<0)
      a[0]=-1;
}
int main(int argc, char* argv[])
{
  int i,n1,n2,a1[10],a2[10];
  while (scanf("%d%d",&n1,&n2)!=EOF && (n1||n2))
  {
    if (n1>n2)
    {
      i=n1;
      n1=n2;
      n2=i;
    }
    n1--;

    count(a1,n1);
    count(a2,n2);

    printf("%d",a2[0]-a1[0]);
    for (i=1;i<10;i++)
      printf(" %d",a2[i]-a1[i]);
    printf("\n");
  }
  return 0;
}
//---------------------------------------------------------------------------
