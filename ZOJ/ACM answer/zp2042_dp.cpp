//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

//---------------------------------------------------------------------------

#pragma argsused
//DFS is not suitable
#include <iostream.h>

int s,n,m;
int a[10010];
int p[10010][110];

int main(int argc, char* argv[])
{
  int N,I,i,j;
  cin>>N;
  for (I=0;I<N;I++)
  {
    if (I) cout<<endl;
    cin>>n>>m;
    for (i=1;i<=n;i++)
      for (j=0;j<=m;j++)
        p[i][j]=0;
    for (i=1;i<=n;i++)
    { cin>>a[i]; a[i]%=m; if (a[i]<0) a[i]+=m; }

    p[1][a[1]]=1;
    for (i=2;i<=n;i++)
      for (j=0;j<=m;j++)
        if (p[i-1][j])
        {
          p[i][(a[i]-j+m)%m]=1;
          p[i][(a[i]+j)%m]=1;
        }
    if (p[n][0])
      cout<<"D";
    else
      cout<<"Not d";
    cout<<"ivisible"<<endl;
  }
  return 0;
}
//---------------------------------------------------------------------------
