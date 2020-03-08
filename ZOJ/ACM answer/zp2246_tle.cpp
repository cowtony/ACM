//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

//---------------------------------------------------------------------------

#pragma argsused
#include <iostream.h>
int sum,mx,n,y,p[25],v[25],a[25][25],w[25][25][25];

void findit(int x,int dp)
{
  if (dp>mx) mx=dp;
  if (mx==n) return;
  for (int i=0;i<n;i++)
    if (p[i] && sum+v[i]+a[x][i]<=420)
    {
      sum+=v[i]+a[x][i];
      if (w[y][i][dp]==0 || sum<=w[y][i][dp])
      {
        w[y][i][dp]=sum;
        p[i]=0;
        findit(i,dp+1);
        if (mx==n) return;
        p[i]=1;
      }
      sum-=v[i]+a[x][i];
    }
}
int main(int argc, char* argv[])
{
  int i,j,k,l,min;
  cin>>n;
  while (n)
  {
    for (i=0;i<n;i++)
      cin>>v[i];
    for (i=0;i<n;i++)
      for (j=0;j<n;j++)
        cin>>a[i][j];

    min=v[0];
    for (i=1;i<n;i++)
      if (min>v[i])
        min=v[i];

    for (i=0;i<n;i++)
      p[i]=1;

    sum=min;
    mx=0;
    if (min<=420)
      for (i=0;i<n;i++)
        if (v[i]==min)
        {
          for (j=0;j<n;j++)
            for (k=0;k<n;k++)
              for (l=0;l<n;l++)
                w[j][k][l]=0;
          y=i;
          p[i]=0;
          findit(i,1);
          p[i]=1;
        }

    cout<<mx<<endl;

    cin>>n;
  }
  return 0;
}
//---------------------------------------------------------------------------
