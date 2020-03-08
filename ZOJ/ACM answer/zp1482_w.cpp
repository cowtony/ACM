//---------------------------------------------------------------------------

#pragma hdrstop

//---------------------------------------------------------------------------
//#define cin fin
#pragma argsused
//#include <fstream.h>
//#include <iostream.h>
#include <stdio.h>

int a[3010],p[3010],d[3010],x0[3010],x1[3010];

int main(int argc, char* argv[])
{
  //ifstream fin("in1482.txt");
  int n,sum,i,j,c0,c1,s,m,k;
  while (scanf("%d",&n)!=EOF)
  {
    sum=0;
    for (i=1;i<=n;i++)
      scanf("%d",&a[i]);
    a[n+1]=1-a[n];
    a[0]  =1-a[1];
    for (i=2;i<=n+1;i++)
    {
      if (i==2)
        for (j=1;j<=n;j++)  d[j]=1;
      else
        for (j=0;j<=n+1;j++)
        { d[j]=a[j]; a[j]=p[j]; }
      if (i>n)
        for (j=1;j<=n;j++)  p[j]=1;
      else
        for (j=1;j<=n;j++)
          scanf("%d",&p[j]);

      d[n+1]=1-d[n];
      d[0]  =1-d[1];
      p[n+1]=1-p[n];
      p[0]  =1-p[1];
      c0=1;   c1=c0;   s=0;
      while (c1<=n)
      {
        while (a[c1]==a[c0]) c1++;

        if (!a[c0])
        {
          x0[++s]=c0;
          x1[s]=c1-1;
        }
        c0=c1;
      }
      for (j=1;j<=s;j++)
      {
        m=0;
        if (!p[x0[j]]) m++;
        for (k=x0[j]+1;k<=x1[j];k++)
          if (p[k-1] && !p[k]) m++;
        if (m)
          sum-=m-1;
        else
          sum++;
      }
      for (j=1;j<=s;j++)
      {
        m=0;
        if (!d[x0[j]]) m++;
        for (k=x0[j]+1;k<=x1[j];k++)
          if (d[k-1] && !d[k]) m++;
        if (m)
          sum+=m-1;
        else
          sum--;
      }
    }
    printf("%d\n",sum);
    //cout<<sum<<endl;
  }
  return 0;
}
//---------------------------------------------------------------------------
