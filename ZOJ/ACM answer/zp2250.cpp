//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

//---------------------------------------------------------------------------

#pragma argsused
#include <iostream.h>
int main(int argc, char* argv[])
{
  int m,n,i,j,mx,mn,max,x,r,p[10001];
  cin>>n>>m;
  mx=10000;
  while (m+n)
  {
    for (i=1;i<=mx;i++)
      p[i]=0;
    max=0;
    for (i=0;i<n;i++)
      for (j=0;j<m;j++)
      {
        cin>>x;
        p[x]++;
        if (x>max) max=x;
      }
    mn=0;
    for (i=1;i<=max;i++)
      if (p[i]>mn)
      {
        mn=p[i];
        r=i;
      }
    mn=0;
    for (i=1;i<=max;i++)
      if (p[i]>mn && i!=r)
      {
        mn=p[i];
      }
    for (i=1;i<=max;i++)
      if (p[i]==mn)
        cout<<i<<' ';

    cout<<endl;

    cin>>n>>m;
  }
  return 0;
}
//---------------------------------------------------------------------------
 