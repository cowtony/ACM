//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

//---------------------------------------------------------------------------

#pragma argsused
#include <stdio.h>
#include <math.h>

int a[100100][3];
int prm(int m, int n)
{
  int t=m%n;
  while (t)
  {
    m=n;
    n=t;
    t=m%n;
  }
  if (n==1)
    return 1;
  else
    return 0;
}
int main(int argc, char* argv[])
{
  int i,j,k,s;
  s=0;
  for (i=3;s<=100000;i++)
  {
    if (i%2==1)
    {
      for (j=sqrt(i);j>0;j--)
        if (i%j==0)
        {
          k=i/j;
          if (j%2==1 && 2*i<k*k-j*j)
            if (prm(i,(k*k-j*j)/2) && prm(i,(k*k+j*j)/2))
            {
              a[++s][0]=i;
              a[s][1]=(k*k-j*j)/2;
              a[s][2]=(k*k+j*j)/2;
            }
        }
    }
    else
    {
      for (j=sqrt(i/2);j>0;j--)
        if ((i/2)%j==0)
        {
          k=i/j/2;
          if ((k-j)%2==1 && i<k*k-j*j)
            if (prm(i,k*k-j*j) && prm(i,k*k+j*j))
            {
              a[++s][0]=i;
              a[s][1]=k*k-j*j;
              a[s][2]=k*k+j*j;
            }
        }
    }
  }
  while (scanf("%d",&i)!=EOF)
    printf("%d %d %d\n",a[i][0],a[i][1],a[i][2]);
  return 0;
}
//---------------------------------------------------------------------------
 