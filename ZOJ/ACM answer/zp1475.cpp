//---------------------------------------------------------------------------

#pragma hdrstop

//---------------------------------------------------------------------------

#pragma argsused
#include <iostream>
#include <string>
using namespace std;

int cmn(int n,int m)
{
  int s=1;
  int h=(n>m-n)? m-n:n;
  for (int i=1;i<=h;i++)
    s*=m-i+1;
  for (int i=2;i<=h;i++)
    s/=i;
  return s;
}
int main(int argc, char* argv[])
{
  int jrm,i,j,n,a[210][210];

  a[1][1]=1;
  a[1][0]=1;
  jrm=1;
  for (i=2;i<=200;i++)
  {
    jrm*=i;
    a[i][1]=jrm;
    a[i][0]=a[i][1];
    for (j=2;j<=i;j++)
    {
      a[i][j]=cmn(j,i)*a[i-1][j-1];
      a[i][0]+=a[i][j];
    }
  }
  cin>>n;
  while (n>=0)
  {
    cout<<a[n][0]<<endl;
    cin>>n;
  }
  return 0;
}
//---------------------------------------------------------------------------
 