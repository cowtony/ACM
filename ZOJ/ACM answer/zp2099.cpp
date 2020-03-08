//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

//---------------------------------------------------------------------------

#pragma argsused
#include <iostream.h>
int main(int argc, char* argv[])
{
  int x,y,mnx,mxx,mny,mxy;

  cin>>x>>y;
  while (x || y)
  {
    mxx=x;  mxy=y;  mnx=x;  mny=y;
    while (x || y)
    {
      if (x>mxx) mxx=x;
      if (x<mnx) mnx=x;
      if (y>mxy) mxy=y;
      if (y<mny) mny=y;
      cin>>x>>y;
    }
    cout<<mnx<<' '<<mny<<' '<<mxx<<' '<<mxy<<endl;

    cin>>x>>y;
  }
  return 0;
}
//---------------------------------------------------------------------------
