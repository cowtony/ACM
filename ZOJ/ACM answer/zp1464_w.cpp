//---------------------------------------------------------------------------

#pragma hdrstop

//---------------------------------------------------------------------------

#pragma argsused
#define cin fin
#include <fstream.h>
#include <iostream.h>
//using namespace std;

double da[10005],ds;
int n,k,s,mx,mi,mj,mm,mr,r[10005],a[10005],d[10005],md[10005];

int main(int argc, char* argv[])
{
//   ifstream fin("in1464.txt");
    ifstream fin("cable.in");
  int N,i,j;
  cin>>N;
  for (int I=0;I<N;I++)
  {
    cin>>n>>k;
    ds=0;
    for (i=1;i<=n;i++)
    {
      cin>>da[i];
      ds+=da[i];
    }
    ds/=k;
    mx=1000*ds+1e-8;

    if (mx==0)
      mm=0;
    else
    {
    for (i=1;i<=n;i++)
      a[i]=1000*da[i]+1e-8;

    s=0;mm=0;
    for (i=1;i<=n;i++)
    {
      r[i]=a[i]/mx;
      md[i]=a[i]-r[i]*mx;
      s+=r[i];
      if (a[i]>mm)
      { mi=i;mm=a[i];}
      d[i]=1;
    }

    for (i=1;i<=k-s;i++)
    {
      mm=0;
      for (j=1;j<=n;j++)
        if (d[j] && md[j]>=mm)
        {
          if (md[j]==mm)
            {
              if (r[j]>mr)
              { mj=j; mr=r[j]; }
            }
          else
          {
            mm=md[j];
            mj=j;
            mr=r[j];
          }
        }
      d[mj]=0;
      r[mj]+=1;
    }
    mm=a[mi]/r[mi];
    }
    cout<<mm/1000<<'.'<<(mm%1000)/100<<(mm%100)/10<<endl;
  }
  return 0;
}
//---------------------------------------------------------------------------
