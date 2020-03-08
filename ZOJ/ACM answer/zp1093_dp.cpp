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
typec box[100];

int pbox[32][4];
int r[100][100],lar[100];
short lp[1000000];

int main(int argc, char* argv[])
{
  int cs,n,t,i,j,k,s,max,ht,lars;
  cin>>n;
  cs=0;
  while(n)
  {
    s=0;lars=0;
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
      if (pbox[i][0]==pbox[i][1]
       || pbox[i][1]==pbox[i][2])
        if (pbox[i][0]==pbox[i][2])
        {
          box[s].ht=pbox[i][0];
          box[s].lg=pbox[i][0];
          box[s++].sh=pbox[i][0];
          lar[lars++]=pbox[i][0];
        }
        else
        {
          box[s].ht=pbox[i][2];
          box[s].lg=pbox[i][1];
          box[s++].sh=pbox[i][0];
          box[s].ht=pbox[i][0];
          box[s].lg=pbox[i][2];
          box[s++].sh=pbox[i][1];
          lar[lars++]=pbox[i][0];
          lar[lars++]=pbox[i][2];
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
        lar[lars++]=pbox[i][0];
        lar[lars++]=pbox[i][1];
        lar[lars++]=pbox[i][2];
      }
    }
    for (i=0;i<lars-1;i++)
      for (j=i+1;j<lars;j++)
        if (lar[i]>lar[j])
        {
          t=lar[i]; lar[i]=lar[j]; lar[j]=t;
        }
    for (i=0;i<lars;i++)
      lp[lar[i]]=i+1;
    for (i=0;i<lars;i++)
      for (j=0;j<lars;j++)
        r[i][j]=0;
    for (i=0;i<s;i++)
      r[lp[box[i].lg]][lp[box[i].sh]]=box[i].ht;

    max=lar[lars-1];

    for (i=lars;i>0;i--)
      for (j=lars;j>0;j--)
        if (r[i][j])
          for (k=0;k<s;k++)
            if (lp[box[k].lg]<i && lp[box[k].sh]<j
              && r[i][j]+box[k].ht>r[lp[box[k].lg]][lp[box[k].sh]])
            {
              r[lp[box[k].lg]][lp[box[k].sh]]=r[i][j]+box[k].ht;
              if (r[lp[box[k].lg]][lp[box[k].sh]]>max)
                max=r[lp[box[k].lg]][lp[box[k].sh]];
            }

    cout<<"Case "<<++cs<<": maximum height = "<<max<<endl;

    cin>>n;
  }
  return 0;
}

//---------------------------------------------------------------------------
