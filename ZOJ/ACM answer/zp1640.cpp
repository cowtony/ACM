//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

//---------------------------------------------------------------------------

#pragma argsused
#include <stdio.h>
int mabs(int d)
{
  if (d<0)
    return -d;
  return d;
}
int main(int argc, char* argv[])
{
  int N,I,i,j,m,s,a[25],b[25],r[25];
  scanf("%d",&N);
  for (I=0;I<N;I++)
  {
    scanf("%d",&m);
    for (i=0;i<=m;i++)
    {
      scanf("%d",a+i);
      b[i]=a[i];
    }
    s=0;
    while (m)
    {
      if (a[m]==0)
        i=0;
      else
      for (i=1;i<=mabs(a[m]);i++)
        if (a[m]%i==0)
        {
          for (j=1;j<m;j++)
            a[j]+=a[j-1]*i;
          if (a[m-1]+a[m]/i==0)
            break;
          else
            for (j=0;j<m;j++)
              a[j]=b[j];

          for (j=1;j<m;j++)
            a[j]-=a[j-1]*i;
          if (a[m-1]-a[m]/i==0)
          {
            i=-i;
            break;
          }
          else
            for (j=0;j<m;j++)
              a[j]=b[j];
        }

      if (i>mabs(a[m]))
        break;
      else
      {
        for (j=0;j<m;j++)
          b[j]=a[j];
        r[s++]=i;
      }
      m--;
    }
    if (s==0)
      printf("NIR");
    else
    {
      for (i=0;i<s-1;i++)
        for (j=i+1;j<s;j++)
          if (r[i]>r[j])
          {
            m=r[i];
            r[i]=r[j];
            r[j]=m;
          }
      printf("%d",r[0]);
      for (i=1;i<s;i++)
        printf(" %d",r[i]);
    }
    printf("\n");
  }
  return 0;
}
//---------------------------------------------------------------------------
