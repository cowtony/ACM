#include <stdio.h>
#include <string.h>

int main(int argc, char* argv[])
{
  int i,j,k,n;
  double b[12],p[12],w[12][110];
  for (i=1;i<=10;i++)
  {
    w[i][0]=0;
    w[i][1]=0;
    for (j=0;j<i;j++)
    {
      b[j]=1.0/i;
      w[i][1]+=b[j];
    }
    for (k=2;k<=100;k++)
    {
      w[i][k]=0;
      p[0]=(b[0]+b[1])/i;
      p[i-1]=(b[i-1]+b[i-2])/i;
      for (j=1;j<i-1;j++)
        p[j]=(b[j-1]+b[j]+b[j+1])/i;
      for (j=0;j<i;j++)
        w[i][k]+=p[j];
      memcpy(b,p,sizeof(double)*i);
    }
  }
  while (scanf("%d%d",&k,&n)>0)
    printf("%.5lf\n",w[k+1][n]*100);
  return 0;
}
//---------------------------------------------------------------------------
