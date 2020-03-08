//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

//---------------------------------------------------------------------------

#pragma argsused
#include <iostream.h>

struct typec
{
  int num,mod,d[500];
};
typec sh[5000];
int m,n,p[5010],di[15];
int calit()
{
  int pf,sf,i,j;
  sh[0].num=0;
  sh[0].mod=0;
  pf=0;sf=1;
  while (pf<sf)
  {
    for (i=0;i<m;i++)
    {
      if (pf==0 && di[i]==0) continue;
      sh[sf].mod=(sh[pf].mod*10+di[i])%n;
      if (p[sh[sf].mod]) continue;
      p[sh[sf].mod]=1;
      sh[sf].num=sh[pf].num;
      for (j=0;j<sh[sf].num;j++)
        sh[sf].d[j]=sh[pf].d[j];
      sh[sf].d[sh[sf].num++]=di[i];
      if (sh[sf].mod==0) return sf;
      sf++;
    }
    pf++;
  }
  return -1;
}

int main(int argc, char* argv[])
{
  int i,j,t,pos;
  while (cin>>n)
  {
    cin>>m;
    for (i=0;i<m;i++)
      cin>>di[i];

    if (n==0) { cout<<0<<endl; continue; }

    for (i=0;i<m-1;i++)
      for (j=i+1;j<m;j++)
        if (di[i]>di[j])
        { t=di[i];di[i]=di[j];di[j]=t; }

    for (i=0;i<n;i++)
      p[i]=0;

    pos=calit();
    if (pos>0)
      for (i=0;i<sh[pos].num;i++)
        cout<<sh[pos].d[i];
    else
      cout<<0;
    cout<<endl;
  }

  return 0;
}
//---------------------------------------------------------------------------
