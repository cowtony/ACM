//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

//---------------------------------------------------------------------------

#pragma argsused
#include <iostream.h>
#include <math.h>
#include <iomanip.h>

int main(int argc, char* argv[])
{
  int N,I,i,j,rf,rg,w;
  double d,k,rk,mn;
  int f[4],g[10];
  cout<<setiosflags(ios::fixed)<<setprecision(3);
  cin>>N;
  for (I=0;I<N;I++)
  {
    if (I) cout<<endl;
    for (i=0;i<3;i++)
      cin>>f[i];
    for (i=0;i<9;i++)
      cin>>g[i];
    cin>>d>>w;
    d*=3.14159;
    mn=fabs(f[0]*1.0/g[0]*d-w);
    for (i=0;i<3;i++)
      for (j=0;j<9;j++)
      {
        k=f[i]*1.0/g[j]*d;
        if (fabs(k-w)<mn)
        {
          mn=fabs(k-w);
          rk=k;
          rf=i;
          rg=j;
        }
      }
    cout<<"A gear selection of "
        <<f[rf]<<'/'<<g[rg]<<" produces a gear size of "
        <<rk<<'.'<<endl;

  }
  return 0;
}
//---------------------------------------------------------------------------
