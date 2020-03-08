//---------------------------------------------------------------------------

#pragma hdrstop

//---------------------------------------------------------------------------

#pragma argsused
#define cin fin
#include <fstream>
#include <iostream>
#include <string>
using namespace std;
string sr[25];
int mx[100],lmr[100],l[25][100],a[25][100];
int w;
void outputwords(int n)
{
  int i,j,rr,ll;
  cout<<'|';
  for (i=1;i<=w;i++)
  {
    if (i>1)
      cout<<'|';
    cout<<' ';
    ll=(mx[i]-l[n][i])/2;
    rr=mx[i]-l[n][i]-ll;
    if (lmr[i]==-1)
    {
      for (j=a[n][i-1]+2;j<=a[n][i];j++)
        cout<<sr[n][j];
      for (j=0;j<ll+rr;j++)
        cout<<' ';
    }
    else if (lmr[i]==1)
    {
      for (j=0;j<ll+rr;j++)
        cout<<' ';
      for (j=a[n][i-1]+2;j<=a[n][i];j++)
        cout<<sr[n][j];
    }
    else if (lmr[i]==0)
    {
      for (j=0;j<ll;j++)
        cout<<' ';
      for (j=a[n][i-1]+2;j<=a[n][i];j++)
        cout<<sr[n][j];
      for (j=0;j<rr;j++)
        cout<<' ';
    }
    cout<<' ';
  }
  cout<<'|'<<endl;
}
int main(int argc, char* argv[])
{
  ifstream fin("d:\in1702.txt");
  char st[100];
  int i,j,p,k,max,m;

  cin.getline(st,100);
  while (st[0]!='*')
  {
    for (w=0;1;w++)
      if (st[w]=='\0') break;
    for (i=0;i<w;i++)
      if (st[i]=='=')     lmr[i+1]=0;
      else
        if (st[i]=='<')   lmr[i+1]=-1;
        else
          if (st[i]=='>') lmr[i+1]=1;
    cin.getline(st,100);
    p=0;
    while (st[0]!='=' && st[0]!='<' &&
           st[0]!='>' && st[0]!='*')
    {
      k=1;
      a[p][0]=-2;
      for (m=0;1;m++)
        if (st[m]=='\0') break;
      for (i=0;i<m;i++)
        if (st[i]=='&')
          a[p][k++]=i-1;
      a[p][k]=m-1;
      sr[p]=st;
      for (i=1;i<=w;i++)
        l[p][i]=a[p][i]-a[p][i-1]-1;
      cin.getline(st,100);
      p++;
    }
    for (i=1;i<=w;i++)
      mx[i]=0;
    for (i=0;i<p;i++)
      for (j=1;j<=w;j++)
        if (l[i][j]>mx[j])
          mx[j]=l[i][j];
    max=3*w-1;
    for (i=1;i<=w;i++)
      max+=mx[i];

    cout<<'@';
    for (i=1;i<=max;i++)
      cout<<'-';
    cout<<'@'<<endl;

    outputwords(0);
    cout<<'|';
    for (i=1;i<=w;i++)
    {
      if (i>1)
        cout<<'+';
      for (j=1;j<=mx[i]+2;j++)
        cout<<'-';
    }
    cout<<'|'<<endl;
    for (i=1;i<p;i++)
      outputwords(i);

    cout<<'@';
    for (i=1;i<=max;i++)
      cout<<'-';
    cout<<'@'<<endl;
  }
  return 0;
}
//---------------------------------------------------------------------------
