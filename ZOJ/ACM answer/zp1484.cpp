//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

//---------------------------------------------------------------------------

#pragma argsused
#include <iostream>
#include <string>
using namespace std;

int main(int argc, char* argv[])
{
  int n,i,j,t,mn,a[5010],p[5010],b[5010];

  while (cin>>n)
  {
    for (i=1;i<=n;i++)
      cin>>a[i];
    for (i=1;i<=n;i++)
      p[i]=0;
    for (i=1;i<=n;i++)
    {
      b[i]=p[i];
      t=0;
      for (j=i+1;j<=n;j++)
      {
        if (a[j]<a[i]) t++;
        b[j]=p[j]+t;
      }
      for (j=1;j<i;j++)
      {
        if (a[j]<a[i]) t++;
        b[j]=p[j]+t;
      }
      memcpy(p,b,sizeof(int)*(n+3));
    }

    mn=p[1];
    for (i=2;i<=n;i++)
      if (p[i]<mn)
        mn=p[i];
    cout<<mn<<endl;
  }
  return 0;
}
//---------------------------------------------------------------------------
 