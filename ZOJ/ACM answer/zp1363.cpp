//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

//---------------------------------------------------------------------------

#pragma argsused
#include <iostream>
#include <iomanip>
using namespace std;

int main(int argc, char* argv[])
{
  int c,n,m,i,j;
  double a[110],b[110];

  cout<<setiosflags(ios::fixed)<<setprecision(3);

  cin>>c;
  while (c)
  {
    cin>>n>>m;
    if((n==0)&&(m==0))
      cout<<1<<endl;
    else
      if((m>c)||(m>n)||((n-m)%2!=0))
        cout<<0<<endl;
    else
    {
      //if (n>c*5)
      //  n=c*5;
      //if ((n-m)%2!=0)
      //  n++;

      if (n>600)
        if (n%2)
          n=601;
        else
          n=600;

        for (i=0;i<=c;i++)
        {
          a[i]=0;
          b[i]=0;
        }
        a[1]=1;
        for (i=2;i<=n;i++)
        {
          b[1]=a[0];
          b[c-1]=a[c];
          for (j=1;j<c;j++)
          {
            b[j-1]+=a[j]*(j*1.0/c);
            b[j+1]+=a[j]*(1-(j*1.0/c));
          }
          for (j=0;j<=c;j++)
          {
            a[j]=b[j];
            b[j]=0;
          }
        }
        cout<<a[m]<<endl;
    }
    cin>>c;
  }
  return 0;
}
//---------------------------------------------------------------------------

