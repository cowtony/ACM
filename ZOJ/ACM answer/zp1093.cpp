//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

//---------------------------------------------------------------------------

#pragma argsused
#include <iostream>
#include <string>
using namespace std;

struct typec
{
  int ht,lg,sh;
};
typec box[100],h[100000],p[10000000];

int pbox[32][4];

int main(int argc, char* argv[])
{
  int cs,n,t,i,j,k,s,max,sf,pf,ht;
  cin>>n;
  cs=0;
  max=10000000;
  while(n)
  {
    memset(p,0,sizeof(int)*3*max);
    s=0;max=0;
    for (i=0;i<n;i++)
    {
      cin>>pbox[i][0]>>pbox[i][1]>>pbox[i][2];
      for (k=0;k<2;k++)
        for (j=k+1;j<3;j++)
          if (pbox[i][k]>pbox[i][j])
          {
            t=pbox[i][j];
            pbox[i][j]=pbox[i][k];
            pbox[i][k]=t;
          }
      if (pbox[i][2]>max)
        max=pbox[i][2];
      if (pbox[i][0]==pbox[i][1]
       || pbox[i][1]==pbox[i][2])
        if (pbox[i][0]==pbox[i][2])
        {
          box[s].ht=pbox[i][0];
          box[s].lg=pbox[i][0];
          box[s++].sh=pbox[i][0];
        }
        else
        {
          box[s].ht=pbox[i][2];
          box[s].lg=pbox[i][1];
          box[s++].sh=pbox[i][0];
          box[s].ht=pbox[i][0];
          box[s].lg=pbox[i][2];
          box[s++].sh=pbox[i][1];
        }
      else
      {
        box[s].ht=pbox[i][2];
        box[s].lg=pbox[i][1];
        box[s++].sh=pbox[i][0];
        box[s].ht=pbox[i][0];
        box[s].lg=pbox[i][2];
        box[s++].sh=pbox[i][1];
        box[s].ht=pbox[i][1];
        box[s].lg=pbox[i][2];
        box[s++].sh=pbox[i][0];
      }
    }
    h[0].lg=max+1;
    h[0].sh=max+1;
    pf=0; sf=1;
    max=0;
    while (pf<sf)
    {
      for (i=0;i<s;i++)
        if (box[i].lg<h[pf].lg && box[i].sh<h[pf].sh)
        {
          ht=h[pf].ht+box[i].ht;
          h[sf].ht=ht;
          if (p[ht].ht)
          {
            if (p[ht].lg<box[i].lg
             && p[ht].sh<box[i].sh)
            {
              p[ht].lg=box[i].lg;
              p[ht].sh=box[i].lg;
              h[p[ht].ht].lg=box[i].lg;
              h[p[ht].ht].sh=box[i].sh;
              continue;
            }
            else
            if (p[ht].lg>=box[i].lg
             && p[ht].sh>=box[i].sh)
              continue;
          }
          else
          {
            p[ht].ht=sf;
            p[ht].lg=box[i].lg;
            p[ht].sh=box[i].sh;
          }
          h[sf].lg=box[i].lg;
          h[sf].sh=box[i].sh;
          if (h[sf].ht>max)
            max=h[sf].ht;
          sf++;
        }
      pf++;
    }

    cout<<"Case "<<++cs<<": maximum height = "<<max<<endl;

    cin>>n;
  }
  return 0;
}
//---------------------------------------------------------------------------
