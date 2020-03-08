//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

//---------------------------------------------------------------------------

#pragma argsused
#include <iostream.h>

int main(int argc, char* argv[])
{
  int n,m,mn,t,s,i,j,q,rn,k;
  int r[52][52],p[52],x[2000],y[2000],v[2000];
  cin>>n;
  while (n)
  {
    cin>>rn;

    for (i=1;i<=n;i++)
      for (j=1;j<=n;j++)
        r[i][j]=0;
    for (k=0;k<rn;k++)
    {
      cin>>i>>j>>q;
      if (r[i][j]==0 || r[i][j]>q)
      { r[i][j]=q; r[j][i]=q; }
    }
    for (i=1;i<=n;i++)
      p[i]=1;
    s=0;
    for (i=1;i<n;i++)
      for (j=i+1;j<=n;j++)
        if (r[i][j])
        {
          s++;
          x[s]=i;
          y[s]=j;
          v[s]=r[i][j];
        }
    for (i=1;i<s;i++)
      for (j=i+1;j<=s;j++)
        if (v[i]>v[j])
        {
          t=x[i];x[i]=x[j];x[j]=t;
          t=y[i];y[i]=y[j];y[j]=t;
          t=v[i];v[i]=v[j];v[j]=t;
        }
    mn=v[1];
    p[x[1]]=0;
    p[y[1]]=0;
    for (i=2;i<n;i++)
    {
      t=1;
      while (t<=s)
      {
        if (p[x[t]]+p[y[t]]==1)
        {
          mn+=v[t];
          p[x[t]]=0;
          p[y[t]]=0;
          break;
        }
        t++;
      }
    }

    cout<<mn<<endl;

    cin>>n;
  }
  return 0;
}
//---------------------------------------------------------------------------
 