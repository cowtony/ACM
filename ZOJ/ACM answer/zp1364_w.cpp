//---------------------------------------------------------------------------

#pragma hdrstop

//---------------------------------------------------------------------------

#pragma argsused
//#define cin fin
#include <fstream.h>
#include <iostream.h>
int main(int argc, char* argv[])
{
  ifstream fin("d:\in1364.txt");
  int n,m,k,i,j,c,t,ax,rr[1010],ra[1010],rb[1010],pa[110],pb[110];
  cin>>n;
  while (n)
  {
    cin>>m>>k;
    for (i=0;i<k;i++)
    {
      //cin>>j;
      cin>>ra[i]>>rb[i];
    }
    for (i=0;i<k;i++)
      rr[i]=1;
    for (i=0;i<n;i++) pa[i]=0;
    for (i=0;i<m;i++) pb[i]=0;
    for (i=0;i<k;i++)
    { pa[ra[i]]++; pb[rb[i]]++; }

    c=0; t=1;
    if (pa[0])
      for (i=0;i<k;i++)
        if (ra[i]==0 && rr[i])
        {  pb[rb[i]]--; rr[i]=0; }
    if (pb[0])
      for (i=0;i<k;i++)
        if (rb[i]==0 && rr[i])
        {  pa[ra[i]]--; rr[i]=0; }
    pa[0]=0; pb[0]=0;
    while (t)
    {
      ax=0;
      for (i=1;i<n;i++)
        if (pa[i]>ax)
        { ax=pa[i]; j=i; t=1; }
      for (i=1;i<m;i++)
        if (pb[i]>ax)
        { ax=pb[i]; j=i; t=2; }
      if (!ax) break;
      if (t==1)
      {
        for (i=0;i<k;i++)
          if (ra[i]==j && rr[i] )
          {  pb[rb[i]]--; rr[i]=0; }
        pa[j]=0;
        c++;
      }
      else if (t==2)
      {
        for (i=0;i<k;i++)
          if (rb[i]==j && rr[i] )
          {  pa[ra[i]]--; rr[i]=0; }
        pb[j]=0;
        c++;
      }
    }

    cout<<c<<endl;

    cin>>n;
  }
  return 0;
}
//---------------------------------------------------------------------------
