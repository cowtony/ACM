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
  int p[210],i,j,n,k,x,y,p,q;
  while (cin>>n)
  {
    memset(p,0,sizeof(int)*120);
    //for (i=0;i<=100;i++)
      //p[i]=0;
    for (i=1;i<n;i++)
    {
      cin>>x>>y;
      p=x-y+x;
      q=100-y+x;
      for (j=p;j<=q;j++)
        p[j]++;
    }
    cin>>k;
    for (i=k;i<=100;i++)
      if (p[i]==n-1)
        break;
    if (i>100)
      cout<<"try again"<<endl;
    else
      cout<<"clear!!!"<<endl;
  }
  return 0;
}
//---------------------------------------------------------------------------
