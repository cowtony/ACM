//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

//---------------------------------------------------------------------------

#pragma argsused
#include <iostream.h>
int main(int argc, char* argv[])
{
  int n,m,s,t;
  cin>>n>>m;
  while (m+n)
  {
    if (m>n)
    {
      s=m;m=n;n=s;
    }
    t=1;
    while (n/m<=1 && n%m)
    {
      t=1-t;
      s=m;
      m=n%m;
      n=s;
      //cout<<n<<' '<<m<<endl;
    }
    if (t)
      cout<<"Stan";
    else
      cout<<"Ollie";
    cout<<" wins"<<endl;
    cin>>n>>m;
  }
  return 0;
}
//---------------------------------------------------------------------------
 