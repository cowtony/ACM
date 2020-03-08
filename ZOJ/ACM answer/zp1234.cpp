//---------------------------------------------------------------------------
#pragma hdrstop
//---------------------------------------------------------------------------
#pragma argsused
//program zp1234
#define cin fin
#include <fstream>
#include <iostream>
using namespace std;
int w,n,mn,l,k,a[6000],b[6000];
void doin(int k,int m)
{
  if (k)
  {
    for (int i=m;i<n-2*k+2;i++)
    {
      l+=(i>m); w+=b[i];
      if (l) doin(k-1,i+2);
      else doin(k-1,i+3);
      w-=b[i]; l-=(i>m);
    }
  }
  else if (w<mn || mn==0) mn=w;
}
int main(int argc, char* argv[])
{
  ifstream fin("d:\in1234.txt");
  int N,I,i,r;
  cin>>N;
  for (I=0;I<N;I++)
  {
    cin>>k>>n;
    k+=8;
    for (i=n;i>0;i--)
      cin>>a[i];
    mn=0;
    r=0;
    for (i=1;i<n;i++)
    {
      b[i]=(a[i]-a[i+1])*(a[i]-a[i+1]);
      if (b[i]!=b[1]) r=1;
    }
    if (r)
    {
      w=0;l=0;
      doin(k,2);
    }
    else
      mn=b[1]*k;
    cout<<mn<<endl;
  }
  return 0;
}
//---------------------------------------------------------------------------
