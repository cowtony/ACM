#include <stdio.h>

int main(int argc, char* argv[])
{
  int n,i,j,k,l,t,a[110],p[110][110];
  while (scanf("%d",&n)>0)
  {
    for (i=0;i<n;i++)
    {
      scanf("%d",a+i);
      p[i][i]=0;
    }
    n--;
    for (l=1;l<n;l++)
      for (i=0;i<n-l;i++)
      {
        j=l+i;
        p[i][j]=200000000;
        for (k=i+1;k<=j;k++)
        {
          t=p[i][k-1]+p[k][j]+a[i]*a[k]*a[j+1];
          if (t<p[i][j])
            p[i][j]=t;
        }
      }
    printf("%d\n",p[0][n-1]);
  }
  return 0;
}
//---------------------------------------------------------------------------
