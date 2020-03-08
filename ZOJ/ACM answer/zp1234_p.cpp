//---------------------------------------------------------------------------

#pragma hdrstop

//---------------------------------------------------------------------------

#pragma argsused
#define cin fin
#include <fstream.h>
#include <iostream.h>
int a[5010][1010];
int main(int argc, char* argv[])
{
  ifstream fin("d:\in1234p.txt");
  int g0,g1,i,j,k,n,c,I,T;
  int d[5010];
  cin>>T;
  for (I=0;I<T;I++)
  {
    cin>>k>>n>>g0;
    k+=8;
    for (i=1;i<n;i++)
    {
      g1=g0;
      cin>>g0;
      d[i]=(g1-g0)*(g1-g0);
    }
    for (i=1;i<=n+3;i++)
      a[i][0]=0;
    c=n-2;
    for (j=1;j<=k;j++)
    {
      if (a[c+2][j-1]>a[c+3][j-1])
        a[c][j]=d[c]+a[c+3][j-1];
      else
        a[c][j]=d[c]+a[c+2][j-1];
      for (i=c-1;i>(k-j)*2;i--)
      {
        if (a[i+1][j]<a[i+2][j-1]+d[i])
          a[i][j]=a[i+1][j];
        else
          a[i][j]=a[i+2][j-1]+d[i];
      }
      c-=3;
    }
    cout<<a[1][k]<<endl;
  }
  return 0;
}
//---------------------------------------------------------------------------
