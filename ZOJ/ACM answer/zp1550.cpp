//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

//---------------------------------------------------------------------------

#pragma argsused
#include <iostream.h>
int main(int argc, char* argv[])
{
  double a,b,c,d,e,t;
  while (cin>>a>>b>>c>>d>>e)
  {
    if (a>c)
    { t=a;a=c;c=t; }
    if (b>c)
    { t=b;b=c;c=t; }
    if (a>b)
    { t=a;a=b;b=t; }

    if (d>e)
    { t=d;d=e;e=t; }

    if (a<=d && b<=e )
      cout<<"YES";
    else
      cout<<"NO";
    cout<<endl;

  }
  return 0;
}
//---------------------------------------------------------------------------
 