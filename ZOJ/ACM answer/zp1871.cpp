//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

//---------------------------------------------------------------------------

#pragma argsused
#include <iostream.h>
#include <math.h>
int main(int argc, char* argv[])
{
  int n,m;
  while (cin>>n>>m)
  {
    n=m-n;
    if (n<=1)
      cout<<n;
    else
    {
      m=(1+sqrt(4*n-3))/2;
      if ((1+int(sqrt(4*n-4*m-3)))/2==m)
        cout<<2*m;
      else
        cout<<2*m-1;
    }
    cout<<endl;
  }
  return 0;
}
//---------------------------------------------------------------------------
 