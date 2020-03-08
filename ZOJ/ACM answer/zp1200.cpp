//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

//---------------------------------------------------------------------------

#pragma argsused
#include <stdio.h>

int m,n,k,c;
int cmp(int x)
{
  int s=0;
  for (int i=0;i<k && i*m<x;i++)
    s+=c*((x-m*i)/n);
  if (s>=10000)
    return 1;
  return 0;
}
int bisearch(int low,int high)
{
  if (high-low==1)
    if (cmp(high) && !cmp(low))
      return high;
  int mid=(low+high)/2;
  if (cmp(mid) && !cmp(mid-1))
    return mid;
  if (cmp(mid) && cmp(mid-1))
    return bisearch(low,mid-1);
  else
    return bisearch(mid,high);
}
int main(int argc, char* argv[])
{
  int s,w,p,q;
  while (scanf("%d%d%d%d%d",&s,&w,&c,&k,&m)>0)
  {
    n=s+s+w;
    p=n;      q=m;
    while (q)
    { w=p%q;  p=q;  q=w;   }

    n/=p;     m/=p;

    s=m+bisearch(1,10100/c*n);
    s*=p;
    printf("%d\n",s);
  }
  return 0;
}
//---------------------------------------------------------------------------
