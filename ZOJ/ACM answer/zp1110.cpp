//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

//---------------------------------------------------------------------------

#pragma argsused
#include <iostream.h>
int main(int argc, char* argv[])
{
  int s,p,y,j,x;
  while (cin>>s>>p>>y>>j)
  {
    x=(12+j+s+y)/3;
    p=y-s-p;
      switch ((12+j+s+y)%3)
      {
        case 0: cout<<x<<' '<<x-s<<' '<<x-y; break;
        case 1: cout<<x+1<<' '<<x-s<<' '<<x-y; break;
        case 2: cout<<x+1<<' '<<x-s+1-p<<' '<<x-y+p; break;
      }
    cout<<endl;
  }
  return 0;
}
//---------------------------------------------------------------------------
 