//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

//---------------------------------------------------------------------------

#pragma argsused
#include <iostream.h>
#include <math.h>
int dbcmp(double d)
{
  if (fabs(d)<1e-7)
    return 0;
  if (d>0)
    return 1;
  return -1;
}
int main(int argc, char* argv[])
{
  int i,j,f,t,m,n,mx,mn,s,a[3][5000];
  double av,cv,mcv;
  f=0;
  while (cin>>m>>n)
  {
    if (f) cout<<endl; else f=1;
    s=0;
    av=1.0*m/n;
    for (i=1;i<=n;i++)
    {
      j=av*i+0.500000111;
      cv=fabs(av-1.0*j/i);
      if (dbcmp(mcv-cv)>0 || s==0)
      {
        a[0][s]=i;
        a[1][s++]=j;
        mcv=cv;
      }
    }
    for (i=0;i<s;i++)
      cout<<a[1][i]<<'/'<<a[0][i]<<endl;
  }
  return 0;
}
//---------------------------------------------------------------------------
