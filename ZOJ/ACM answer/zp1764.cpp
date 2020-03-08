//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

//---------------------------------------------------------------------------

#pragma argsused
#include <iostream>
#include <string>
using namespace std;
int main(int argc, char* argv[])
{
  string st,mst;
  int n,i,j,nm,tm,sv,pt,mpt,msv;
  while(cin>>n)
  {
    for (i=0;i<n;i++)
    {
      cin>>st;
      sv=0; pt=0;
      for (j=1;j<=4;j++)
      {
        cin>>nm>>tm;
        if (tm)
        {
          sv++;
          pt+=tm+20*(nm-1);
        }
    }
    if (i==0 || (sv>=msv && pt<mpt))
    { mst=st; msv=sv; mpt=pt; }
  }
  cout<<mst<<' '<<msv<<' '<<mpt<<endl;
  }
  return 0;
}
//---------------------------------------------------------------------------
 