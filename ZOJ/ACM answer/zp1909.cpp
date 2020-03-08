#include <stdio.h>
#include <string.h>

int a[20],p[20],n,s,t,w[50010],v[50010];

void dfs(int m,int d)
{
  if (m==s)
  {
    t++;
    if (t<d)
    {
      int i=0;
      while (p[i]!=-1)
        i++;
      if (v[s-a[i]])
      {
        p[i]=t;
        dfs(a[i],d);
        if (t==d) return;
        t=p[i];
        p[i]=-1;
      }
    }
  }
  else
  {
    for (int i=0;i<n;i++)
      if (p[i]==-1 && m+a[i]<=s && v[s-m-a[i]])
      {
        p[i]=t;
        dfs(m+a[i],d);
        if (t==d) return;
        t=p[i];
        p[i]=-1;
      }
  }
}
int main(int argc, char* argv[])
{
//   FILE *out=fopen("output.txt","w");

  int N,I,i,j,r;
  scanf("%d",&N);
  for (I=0;I<N;I++)
  {
    scanf("%d",&n);
    s=0;
    for (i=0;i<n;i++)
    {
      scanf("%d",&a[i]);
      s+=a[i];
    }
    if (s%4)
      printf("no\n");
    else
    {
      s/=4;
      for (i=0;i<n-1;i++)
        for (j=i+1;j<n;j++)
          if (a[i]<a[j])
          {
            t=a[i];
            a[i]=a[j];
            a[j]=t;
          }
      memset(v,0,sizeof(v));
      v[0]=1;
      for (i=0;i<n;i++)
      {
        memset(w,0,sizeof(w));
        for (j=0;j<=s;j++)
          if (v[j])
          {
            w[j]=1;
            if (j+a[i]<=s)
              w[j+a[i]]=1;
          }
        memcpy(v,w,sizeof(v));
      }
      t=0;
      if (a[0]<=s)
      {
        t=0;
        for (i=0;i<n;i++)
          p[i]=-1;

        p[0]=0;

        dfs(a[0],3);
      }

      if (t==3)
        printf("yes\n");
      else
        printf("no\n");
    }
  }
  return 0;
}
//---------------------------------------------------------------------------
