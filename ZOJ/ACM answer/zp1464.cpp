//---------------------------------------------------------------------------

#pragma hdrstop

//---------------------------------------------------------------------------

#pragma argsused
//#define cin fin
#include <fstream.h>
#include <iostream.h>
//using namespace std;

double da[10005],dm,ds;
int n,k,mx,mn,a[10005];

void sekin(int min,int max)
{
  if (min==max)
    cout<<min/100<<'.'<<(min%100)/10<<min%10<<endl;
  else
  {
    int mid=(min+max)/2,x1=0,x2=0;
    for (int i=1;i<=n;i++)
    {
      x1+=a[i]/mid;
      x2+=a[i]/(mid+1);
    }
    if (max==min+1)
      if (x2>=k)
        sekin(max,max);
      else
        sekin(mid,mid);
    else
      if (x1==k && x2<x1)
        sekin(mid,mid);
      else
        if (x1<k)
          sekin(min,mid);
        else
          sekin(mid,max);
  }
}
int main(int argc, char* argv[])
{
//   ifstream fin("in1464.txt");
//   ifstream fin("cable.in");
  int N,i;
  cin>>N;
  for (int I=0;I<N;I++)
  {
    cin>>n>>k;
    ds=0;dm=0;
    for (i=1;i<=n;i++)
    {
      cin>>da[i];
      ds+=da[i];
      if (da[i]>dm) dm=da[i];
      a[i]=100*da[i]+1e-8;
    }
    ds/=k;
    if (dm<ds)
      mx=100*dm+1e-8;
    else
      mx=100*ds+1e-8;

    dm/=k;
    mn=100*dm+1e-8;

    if (I) cout<<endl;
    sekin(mn,mx);
  }
  return 0;
}
//---------------------------------------------------------------------------
