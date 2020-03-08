//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

//---------------------------------------------------------------------------

#pragma argsused
#include <iostream>
#include <string>
#include <stdio.h>
using namespace std;

int a[500000],b[500000];
long long s;

void merge(int l, int w, int h)
{
  int z,v,u,i;
  z=h; v=w+1; u=h-l+1;
  while (u)
  {
    if ((a[w]>a[h] || h==v-1) && w>=l)
    {
      b[u]=a[w];  u--;    w--;    s+=h-v+1;
    }
    else
    {
      b[u]=a[h];  u--;    h--;
    }
  }
//  for (i=l;i<=z;i++)
//    a[i]=b[i-l+1];
  memcpy(a+l,b+1,sizeof(int)*(z-l+1));
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
  int i,n,r,j;

  cin>>n;
  while(n)
  {
    for (i=1;i<=n;i++)
      scanf("%d",a+i);

    //for (i=1;i<=n;i++)
      //a[i]=n-i;
    s=0;
    mst(1,n);
    cout<<s<<endl;
//    for (i=1;i<=n;i++)
//      cout<<a[i]<<' ';
//    cout<<endl;
    cin>>n;
  }
  return 0;
}
//---------------------------------------------------------------------------
