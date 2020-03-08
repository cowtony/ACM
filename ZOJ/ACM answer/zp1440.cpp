//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

//---------------------------------------------------------------------------

#pragma argsused
#include <stdio.h>
#include <string.h>

int a[100010],b[100010],c[100010],d[100010];
long long s,r;

void merge(int l, int w, int h)
{
  int z,v,u,i;
  z=h; v=w+1; u=h-l+1;
  while (u)
  {
    if ((a[w]>a[h] || h==v-1) && w>=l)
    {
      b[u]=a[w];
      d[u]=c[w];
      u--;    w--;
      s+=h-v+1;
    }
    else
    {
      b[u]=a[h];
      d[u]=c[h];
      u--;    h--;
    }
  }
  memcpy(a+l,b+1,sizeof(int)*(z-l+1));
  memcpy(c+l,d+1,sizeof(int)*(z-l+1));

}
void mst(int l, int h)
{
  if (l<h)
  {
    int w=(l+h)/2;
    mst(l,w);
    mst(w+1,h);
    merge(l,w,h);
  }
}

int main(int argc, char* argv[])
{
  int i,n,t;

  while(scanf("%d",&n)>0)
  {
    for (i=1;i<=n;i++)
    {
      scanf("%d",a+i);
      c[i]=i;
    }
    s=0;
    r=0;

    mst(1,n);

    for (i=1;i<=n;i++)
      while (c[i]!=i)
      {
        t=c[c[i]];
        c[c[i]]=c[i];
        c[i]=t;
        r++;
      }
    printf("%d\n%d\n",r,s);
  }
  return 0;
}
//---------------------------------------------------------------------------
