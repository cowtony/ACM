//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

//---------------------------------------------------------------------------

#pragma argsused
//#define cin fin
//#include <fstream>
#include <iostream>
using namespace std;

int main(int argc, char* argv[])
{
  //ifstream fin("in1250.txt");
  int a[15][15][35],p[14][1010],r[15][15];
  int n,y,i,j,k,d,s,cs=0;

  cin>>n>>y;
  while (n+y)
  {
    for (i=1;i<=n;i++)
      for (j=1;j<=y;j++)
        p[i][j]=0;

    for (i=1;i<=n;i++)
      for (j=1;j<=n;j++)
        if (i!=j)
        {
          cin>>r[i][j];
          for (k=1;k<=r[i][j];k++)
            cin>>a[i][j][k];
          a[i][j][0]=a[i][j][r[i][j]];
        }

    for (j=2;j<=n;j++)
      p[j][1]=a[1][j][1];
    for (d=2;d<y;d++)
    {
      s=0;
      for (j=1;j<=n;j++)
        if (p[j][d-1])
        { s=1; break; }
      if (s==0) break;

      for (i=1;i<=n;i++)
        if (p[i][d-1])
          for (j=1;j<=n;j++)
            if (i!=j && a[i][j][d%r[i][j]])
              if (p[j][d]==0 ||
                 (p[j][d] &&
                  p[i][d-1]+a[i][j][d%r[i][j]]<p[j][d]))
                p[j][d]=p[i][d-1]+a[i][j][d%r[i][j]];
    }

    if (s)
      for (j=1;j<n;j++)
        if (p[j][y-1] && a[j][n][y%r[j][n]])
          if (p[n][y]==0 ||
             (p[n][y] &&
              p[j][y-1]+a[j][n][y%r[j][n]]<p[n][y]))
            p[n][y]=p[j][y-1]+a[j][n][y%r[j][n]];

    cout<<"Scenario #"<<++cs<<endl;
    if (p[n][y])
      cout<<"The best flight costs "<<p[n][y]<<'.'<<endl;
    else
      cout<<"No flight possible."<<endl;

    cout<<endl;
    cin>>n>>y;
  }
  return 0;
}
//---------------------------------------------------------------------------
