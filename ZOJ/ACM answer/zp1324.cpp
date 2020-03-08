//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

//---------------------------------------------------------------------------

#pragma argsused
#include <iostream>
#include <iomanip>
#include <string>
using namespace std;
int main(int argc, char* argv[])
{
  int n,ml,i,l,r,c,j;
  string st[110],stt;
  while (cin>>n)
  {
    ml=0;
    for (i=0;i<n;i++)
    {
      cin>>st[i];
      l=st[i].length();
      if (l>ml)
        ml=l;
    }
    ml+=2;
    r=62/ml;
    c=(n-1)/r+1;
    cout<<"------------------------------------------------------------"<<endl;

    for (i=0;i<n-1;i++)
      for (j=i+1;j<n;j++)
        if (st[i]>st[j])
        {
          stt=st[i];
          st[i]=st[j];
          st[j]=stt;
        }
    //cout<<ml<<' '<<r<<' '<<c<<endl;
    for (i=0;i<c;i++)
    {
      for (j=i;j<n;j+=c)
        if (j+c<n)
          cout<<left<<setw(ml)<<st[j];
        else
          cout<<left<<setw(ml-2)<<st[j];

      cout<<endl;
    }
  }
  return 0;
}
//---------------------------------------------------------------------------
