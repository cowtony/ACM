//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

//---------------------------------------------------------------------------

#pragma argsused
#include <stdio.h>
int main(int argc, char* argv[])
{
  int p[203],c[8],i,j,t,mx,sm,N,I,m;

  scanf("%d",&N);
  for (I=0;I<N;I++)
  {
    for (i=0;i<=200;i++)
      p[i]=0;
    for (i=0;i<6;i++)
    {
      scanf("%d",c+i);
      p[c[i]]=1;
    }
    while (1)
    {
      t=1;
      for (i=1;i<=200;i++)
        if (p[i])
          for (j=0;j<6;j++)
          {
            m=i+c[j];
            if (m<=200)
              if (p[m]>p[i]+1 || p[m]==0)
              {
                p[m]=p[i]+1;
                t=0;
              }
            m=i-c[j];
            if (m>0)
              if (p[m]>p[i]+1 || p[m]==0)
              {
                p[m]=p[i]+1;
                t=0;
              }
          }
      if (t)
        break;
    }
    sm=0;
    mx=0;
    for (i=1;i<=100;i++)
    {
      sm+=p[i];
      if (p[i]>mx)
        mx=p[i];
    }
    if (sm%100>9)
      printf("%d.%d %d\n",sm/100,sm%100,mx);
    else
      printf("%d.0%d %d\n",sm/100,sm%100,mx);
  }
  return 0;
}
//---------------------------------------------------------------------------
