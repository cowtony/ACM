//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

//---------------------------------------------------------------------------

#pragma argsused
#include <iostream.h>
int main(int argc, char* argv[])
{
  int n,i,a,p,c;
  while (cin>>n)
  {
    p=0;c=0;
    for (i=1;i<=n;i++)
    {
      cin>>a;
      if (c==0)
      {
        p=a;
        c++;
      }
      else
        if (p==a)
          c++;
        else
          c--;
    }
    cout<<p<<endl;
  }
  return 0;
}
//---------------------------------------------------------------------------
 