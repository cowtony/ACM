//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

//---------------------------------------------------------------------------

#pragma argsused
#include <iostream.h>
#include <iomanip.h>

int main(int argc, char* argv[])
{
  cout<<setiosflags(ios::fixed)<<setprecision(3);
  double dmx;
  int N,I,n,i,j,k,q,rp,kp;
  int nsg[110],pp[110][110],bb[110][110];
  cin>>N;
  for (I=0;I<N;I++)
  {
    cin>>n;
    for (i=0;i<n;i++)
    {
      cin>>nsg[i];
      for (j=0;j<nsg[i];j++)
        cin>>bb[i][j]>>pp[i][j];
    }
    dmx=0;
    for (i=0;i<n;i++)
      for (j=0;j<nsg[i];j++)
      {
        rp=pp[i][j];
        for (k=0;k<n;k++)
          if (k!=i)
          {
            kp=0;
            for (q=0;q<nsg[i];q++)
              if (bb[k][q]>=bb[i][j])
                if (kp==0 || pp[k][q]<kp)
                  kp=pp[k][q];
            if (kp==0)
              break;
            rp+=kp;
          }
        if (k==n)
          if (bb[i][j]*1.0/rp>dmx)
          {
            dmx=bb[i][j]*1.0/rp;
            //cout<<rp<<' '<<bb[i][j]<<' '<<i<<' '<<j<<endl;
          }
      }
    cout<<dmx<<endl;
  }
  return 0;
}
//---------------------------------------------------------------------------
