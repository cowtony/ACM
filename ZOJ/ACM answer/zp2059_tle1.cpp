//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

//---------------------------------------------------------------------------

#pragma argsused
#include <stdio.h>
#include <string.h>

int p[1010][1010],rx[1000010],ry[1000010],a[110];
int main(int argc, char* argv[])
{
  int n,sm,i,j,s,sy;
  while (scanf("%d",&n) && n>=0)
  {
    sm=0;
    for (i=0;i<n;i++)
    {
      scanf("%d",a+i);
      sm+=a[i];
    }
    sm/=2;
    memset(p,0,sizeof(int)*(1010)*(1010));
    p[0][0]=1;
    rx[0]=0;
    ry[0]=0;
    s=0;sy=0;
    for (i=0;i<n;i++)
    {
      sy=s;
      for (j=0;j<=sy;j++)
      {
        if (rx[j]+a[i]<=sm)
          if (p[rx[j]+a[i]][ry[j]]==0)
          {
            s++;
            rx[s]=rx[j]+a[i];
            ry[s]=ry[j];
            p[rx[j]+a[i]][ry[j]]=1;
          }
        if (ry[j]+a[i]<=sm)
          if (p[rx[j]][ry[j]+a[i]]==0)
          {
            s++;
            rx[s]=rx[j];
            ry[s]=ry[j]+a[i];
            p[rx[j]][ry[j]+a[i]]=1;
          }
      }
    }
    for (i=sm;i>0;i--)
      if (p[i][i])
        break;
    if (i==0)
      printf("Sorry\n");
    else
      printf("%d\n",i);
  }
  return 0;
}
//---------------------------------------------------------------------------
