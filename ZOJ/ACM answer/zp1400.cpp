//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

//---------------------------------------------------------------------------

#pragma argsused
#include <iostream>
#include <iomanip>
#include <string>
#include <math.h>
using namespace std;

int main(int argc, char* argv[])
{
  string str,st[15][35];
  int intar[15][35][15],len[15];
  int n,cs,i,j,k,l,t,h,m,I;
  const int M=4000;
  double d;
  cin>>n;
  cs=0;
  while (n)
  {
    cs++;
    intar[cs][0][0]=n;
    for (i=1;i<=n;i++)
    {
      cin>>st[cs][i];
      l=st[cs][i].length();
      if (l>len[0]) len[0]=l;
      d=0;
      intar[cs][i][9]=0;
      intar[cs][i][10]=0;
      for (j=1;j<=7;j++)
      {
        cin>>intar[cs][i][j];
        if (intar[cs][i][j])
        {
          l=log10(intar[cs][i][j])+1;
          if (l>len[j]) len[j]=l;
          intar[cs][i][10]++;
          intar[cs][i][9]+=intar[cs][i][j];
          d+=log(intar[cs][i][j]);
        }
      }
      intar[cs][i][11]=i;
      if (intar[cs][i][9])
      {
        d/=intar[cs][i][10];
        d=exp(d)+.5;
        intar[cs][i][8]=d;
        l=log10(intar[cs][i][8])+1;
        if (l>len[8]) len[8]=l;

        l=log10(intar[cs][i][9])+1;
        if (l>len[9]) len[9]=l;

        intar[cs][i][0]=M*M*intar[cs][i][10]-M*intar[cs][i][9]-intar[cs][i][8];
      }
      else
        intar[cs][i][0]=0;
    }
    for (i=1;i<n;i++)
      for (j=i+1;j<=n;j++)
        if (intar[cs][i][0]<intar[cs][j][0])
        {
          str=st[cs][i];
          st[cs][i]=st[cs][j];
          st[cs][j]=str;
          for (k=0;k<=10;k++)
          {
            t=intar[cs][i][k];
            intar[cs][i][k]=intar[cs][j][k];
            intar[cs][j][k]=t;
          }
        }
    h=1;m=1;
    intar[cs][n+1][0]=-1;
    for (I=2;I<=n+1;I++)
      if (intar[cs][I][0]==intar[cs][I-1][0])
        m++;
      else
        if (m==h)
        { m=I; h=I; }
        else
        {
          for (i=h;i<=m;i++)
            intar[cs][i][11]=h;
          for (i=h;i<m;i++)
            for (j=i+1;j<=m;j++)
              if (st[cs][i]>st[cs][j])
              {
                str=st[cs][i];
                st[cs][i]=st[cs][j];
                st[cs][j]=str;
                for (k=0;k<=10;k++)
                {
                  t=intar[cs][i][k];
                  intar[cs][i][k]=intar[cs][j][k];
                  intar[cs][j][k]=t;
                }
              }
          h=m+1;
          m=h;
        }
    cin>>n;
  }
  for (I=1;I<=cs;I++)
  {
    cout<<"CONTEST "<<I<<endl;
    for (i=1;i<=intar[I][0][0];i++)
    {
      if (intar[I][i][11]<10)
        cout<<'0'<<intar[I][i][11];
      else
        cout<<intar[I][i][11];
      cout<<' ';
      cout<<st[I][i];
      for (j=0;j<=len[0]-st[I][i].length();j++)
        cout<<' ';
      cout<<intar[I][i][10];
      cout<<setw(len[9]+1)<<intar[I][i][9];
      cout<<setw(len[8]+1)<<intar[I][i][8];
      for (j=1;j<=7;j++)
        cout<<setw(len[j]+1)<<intar[I][i][j];
      cout<<endl;
    }
  }
  return 0;
}
//---------------------------------------------------------------------------
