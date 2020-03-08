//---------------------------------------------------------------------------

#pragma hdrstop

//---------------------------------------------------------------------------

#pragma argsused
#include<iostream>
using namespace std;
int main(int argc, char* argv[])
{
  int ra[90010],c[90010],n,i,j,t,a,s,max1,max2,max3;
  int pa[4][4],p[4][4],w[11],v[11],ii,in,av,k;
  while (cin>>n)
  {
    if (n>90000) av=3;
    else av=1;
    for (k=0;k<av;k++)
    {
      s=0;
      ii=1+n/av*k;
      if (k==av-1) in=n; else in=ii+n/av-1;
      for (i=ii;i<=in;i++)
      {
        t=1;
        cin>>a;
        for (j=1;j<=s;j++)
          if (ra[j]==a) {c[j]++;t=0;break;}
        if (t) {s++;ra[s]=a;c[s]=1;}
      }
      c[0]=0;
      max1=0;
      for (i=1;i<=s;i++)
        if (c[i]>c[max1])
          max1=i;
      pa[k][1]=ra[max1]; p[k][1]=c[max1]; c[max1]=0;
      max1=0;
      for (i=1;i<=s;i++)
        if (c[i]>c[max1])
          max1=i;
      pa[k][2]=ra[max1]; p[k][2]=c[max1]; c[max1]=0;
      max1=0;
      for (i=1;i<=s;i++)
        if (c[i]>c[max1])
          max1=i;
      pa[k][3]=ra[max1]; p[k][3]=c[max1];
    }
    if (av==1)
      cout<<pa[0][1]<<endl;
    else
    {
      s=0;
      for (i=0;i<3;i++)
        for (j=1;j<=3;j++)
        {
          t=1;
          for (k=1;k<=s;k++)
            if (w[k]==pa[i][j])
            { v[k]+=p[i][j]; t=0; break;}
          if (t) {s++;w[s]=pa[i][j];v[s]=p[i][j];}
        }
      max1=0;
      for (i=1;i<=s;i++)
        if (v[i]>v[max1]) max1=i;
      cout<<w[max1]<<endl;
    }
  }
  return 0;
}
//---------------------------------------------------------------------------
