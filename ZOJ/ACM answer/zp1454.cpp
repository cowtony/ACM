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
  int dp[1000],dr[1000],mn[13];
  int n,hs,ss,fs,i,j,k,mx,mm;

  cin>>n;
  while (n)
  {
    cin>>hs>>ss>>fs;
    mx=0;
    for (i=1;i<=n;i++)
    {
      cin>>mn[i];
      if (mn[i]>mx)
        mx=mn[i];
    }
    memset(dp,0,sizeof(int)*(mx+2));
    memset(dr,0,sizeof(int)*(mx+2));

    for (i=mn[1];i<=mx;i++)
      dr[i]=i*(hs+ss);

    for (i=2;i<=n;i++)
    {
      for (j=mn[i-1];j<=mx;j++)
      {
        for (k=mn[i];k<j;k++)
          if (dp[k]==0 || dp[k]>dr[j]+(j-k)*fs)
            dp[k]=dr[j]+(j-k)*fs;
        if (dp[j]==0 || dp[j]>dr[j])
          dp[j]=dr[j];
        for (k=j+1;k<=mx;k++)
          if (dp[k]==0 || dp[k]>dr[j]+(k-j)*hs)
            dp[k]=dr[j]+(k-j)*hs;
      }
      for (j=mn[i];j<=mx;j++)
        dp[j]+=j*ss;

      memcpy(dr,dp,sizeof(int)*(mx+2));
      memset(dp,0,sizeof(int)*(mx+2));
    }

    mm=dr[mx];
    for (i=mn[n];i<mx;i++)
      if (dr[i]<mm)
        mm=dr[i];

    cout<<mm<<endl;

    cin>>n;
  }
  return 0;
}
//---------------------------------------------------------------------------
