//---------------------------------------------------------------------------

#pragma hdrstop

//---------------------------------------------------------------------------

#pragma argsused
#define cin fin
#include <fstream>
#include <iostream>
#include <iomanip>
using namespace std;

int main(int argc, char* argv[])
{
  ifstream fin("inpk1926.txt");
  int N,I,n,m,x,sf,pf,i,j,nol,sum,s;
  int p[110][110],r[110],w[110],y[110];
  double v[110],last[110];
  cin>>N;
  for (I=0;I<N;I++)
  {
    cin>>n>>m;
    for (i=1;i<=n;i++)
      cin>>v[i];
    for (i=1;i<=n;i++)
      for (j=1;j<=n;j++)
        p[i][j]=0;
    for (i=1;i<=m;i++)
    {
      cin>>x>>j;
      p[x][j]=1;
      p[j][x]=1;
    }
    for (i=1;i<=n;i++)
    {
      y[i]=0; w[i]=0;
      for (j=1;j<=n;j++)
        y[i]+=p[i][j];
    }

    s=0;  x=1;
    pf=0; sf=1;
    r[0]=x;
    while (1)
    {
      s++;
      w[x]=s;
      while (pf<sf)
      {
        for (i=1;i<=n;i++)
          if (p[r[pf]][i] && w[i]==0)
          {
            r[sf]=i;
            sf++;
            w[i]=s;
          }
        pf++;
      }
      for (i=1;i<=n;i++)
        if (w[i]==0) break;
      if (i>n)
        break;
      else
        x=i;

      pf=0; sf=1;
      r[0]=x;
    }

    for (i=1;i<=s;i++)
    {
      nol=0; sum=0;
      for (j=1;j<=n;j++)
        if (w[j]==i)
        {
          nol+=y[j];
          sum+=v[j];
        }

      if (nol==0)
      {
        for (j=1;j<=n;j++)
          if (w[j]==i)
            last[j]=sum;
      }
      else
        for (j=1;j<=n;j++)
          if (w[j]==i)
            last[j]=double(sum)/nol*y[j];
    }

    for (i=1;i<=n;i++)
      cout<<setiosflags(ios::fixed)
          <<setprecision(3)<<last[i]<<endl;
    cout<<endl;
  }
  return 0;
}
//---------------------------------------------------------------------------
