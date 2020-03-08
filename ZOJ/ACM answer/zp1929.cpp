//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

//---------------------------------------------------------------------------

#pragma argsused
#include<iostream>
using namespace std;

int main(int argc, char* argv[])
{
  int n,ln,rn,k,m,i;
  char st[1010];
  int a[1010],b[20];
  cin>>n;
  while (n)
  {
    cin>>st;
    ln=strlen(st);
    for (i=0;i<ln;i++)
      a[i]=st[i]-'0';

    cin>>st;
    rn=strlen(st);
    for (i=0;i<rn;i++)
      b[rn-i-1]=st[i]-'0';

    k=1;m=0;
    for (i=0;i<rn;i++)
    {
      m+=k*b[i];
      k*=n;
    }
    for (i=0;i<ln;i++)
    {
      a[i]%=m;
      a[i+1]+=a[i]*n;
    }

    m=a[ln-1];
    k=0;
    while (m)
    {
      b[++k]=m%n;
      m/=n;
    }
    if (k)
      for (i=k;i>0;i--)
        cout<<b[i];
    else
      cout<<0;
    cout<<endl;

    cin>>n;
  }
  return 0;
}
//---------------------------------------------------------------------------
