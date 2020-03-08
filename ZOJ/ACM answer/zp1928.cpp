//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

//---------------------------------------------------------------------------

#pragma argsused
#include <iostream>
using namespace std;

int main(int argc, char* argv[])
{
  int x,a,at,b,c,r;
  cin>>x>>a>>b>>c;
  while (x+a+b+c)
  {
    r=1080;
    a*=9;
    b*=9;
    c*=9;
    x*=9;

    at=a;
    if (x>=a)
      a+=360;

    r+=360-(a-x);
    x=at;

    if (b>x)
      x+=360;
    r+=360-(x-b);
    x=b;

    if (x>c)
      c+=360;
    r+=360-(c-x);
    x=c;

    cout<<r<<endl;
    cin>>x>>a>>b>>c;
  }
  return 0;
}
//---------------------------------------------------------------------------
