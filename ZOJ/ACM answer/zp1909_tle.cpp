#include <stdio.h>

int a[20],r[4],n,s,t;
void dfs(int m)
{
  int i;
  if (m==n)
    t=1;
  else
  {
    for (i=0;i<4;i++)
    {
      if (r[i]+a[m]<=s)
      {
        r[i]+=a[m];
        dfs(m+1);
        if (t) return;
        r[i]-=a[m];
      }
    }
  }
}

int main(int argc, char* argv[])
{
  int N,I,i,j;
  scanf("%d",&N);
  for (I=0;I<N;I++)
  {
    scanf("%d",&n);
    s=0;
    for (i=0;i<n;i++)
    {
      scanf("%d",a+i);
      s+=a[i];
    }
    if (s%4)
      printf("no\n");
    else
    {
      s/=4;
      for (i=0;i<n-1;i++)
        for (j=i+1;j<n;j++)
          if (a[i]>a[j])
          {
            t=a[i];
            a[i]=a[j];
            a[j]=t;
          }
      t=0;
      if (a[n-1]<=s)
      {
        for (i=0;i<4;i++)
          r[i]=0;
        r[0]=a[0];
        dfs(1);
      }
      if (t)
        printf("yes\n");
      else
        printf("no\n");
    }
  }
  return 0;
}
//---------------------------------------------------------------------------
