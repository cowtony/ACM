//---------------------------------------------------------------------------

#pragma hdrstop

//---------------------------------------------------------------------------

#pragma argsused
#include <iostream.h>
#include <iomanip.h>

int main(int argc, char* argv[])
{
  long double a[110][110],s;
  int i,j,k,m,n;
  a[1][0]=0;
  a[1][1]=1;
  for (i=2;i<=100;i++)
  {
    a[i][i]=1;
    for (k=2;k<=i;k++)
      a[i][i]/=k;
    a[i][i-1]=0;
    s=1-a[i][i];
    for (j=1;j<i-1;j++)
    {
      a[i][j]=a[i-j][0];
      for (k=2;k<=j;k++)
        a[i][j]/=k;
      s-=a[i][j];
    }
    a[i][0]=s;
  }
  cout<<setiosflags(ios::fixed)<<setprecision(8);
  while (cin>>n>>m)
    cout<<a[n][m]<<endl;
  return 0;
}
//---------------------------------------------------------------------------
 