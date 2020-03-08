//---------------------------------------------------------------------------

#pragma hdrstop

//---------------------------------------------------------------------------

#pragma argsused
#define cin fin
#include <fstream>
#include <iostream>
using namespace std;

int n,kp,p[60],a[60][60],r[60];
int gtp(int dp,int b)
{
  int i,j;
  if (dp>0)
  {
    for (i=b+1;i<=n-dp;i++)
      if (r[i]>=kp-1)
      {
        p[i]=1;
        if (gtp(dp-1,i))
          return 1;
        p[i]=0;
      }
  }
  else
  {
    for (i=0;i<n;i++)
      if (p[i])
        for (j=i+1;j<n;j++)
          if (p[j])
            if (a[i][j]==0) return 0;
    return 1;
  }
  return 0;
}
int main(int argc, char* argv[])
{
  ifstream fin("in1492.txt");
  int i,j,lm,sm;
  cin>>n;
  while (n)
  {
    for (i=0;i<n;i++)
      for (j=0;j<n;j++)
        cin>>a[i][j];
    for (i=0;i<n;i++)
      p[i]=0;

    lm=0; sm=0;
    for (i=0;i<n;i++)
    {
      r[i]=0;
      for (j=0;j<n;j++)
        r[i]+=a[i][j];
      if (r[i]>lm) lm=r[i];
      sm+=r[i];
    }
    if (sm==n*(n-1))
      cout<<n;
    else
    if (lm==0)
      cout<<1;
    else
    if (lm==1)
      cout<<2;
    else
    {
      if (lm>=n-1) lm=n-2;
      for (kp=lm+1;kp>1;kp--)
        if (gtp(kp,-1)) break;

      cout<<kp;
    }
    cout<<endl;
    cin>>n;
  }
  return 0;
}
//---------------------------------------------------------------------------
