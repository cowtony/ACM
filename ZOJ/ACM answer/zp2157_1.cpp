//---------------------------------------------------------------------------

#pragma hdrstop

//---------------------------------------------------------------------------

#pragma argsused
#include<iostream>
using namespace std;
int main(int argc, char* argv[])
{
  while (cin>>p)
  {
    for (i=1;i<=p;i++)
      cin>>rp[i][0]>>rp[i][1];
    for (i=1;i<=p;i++)
    {
      s=0;t=1;
      for (j=1;j<=s;j++)
        if (rp[i][0]==ra[j])
          {t=0;rn[j]++;rr[j][rn[j]]=i;break;}
      if (t)
        {s++;ra[s]=rp[i][0];rn[s]=1;rr[s][1]=i;}
    }
    for (i=1;i<=s;i++)
      for (j=1;j<rn[i];j++)
        for (k=j+1;k<=rn[i];k++)
          if (ra[rr[i][j]][1]>ra[rr[i][k]][1])
            {w=rr[i][k];rr[i][k]=rr[i][j];rr[i][j]=w;}
    for (i=1;i<=s;i+=2)
      lengt+=

  }
  return 0;
}
//---------------------------------------------------------------------------
 