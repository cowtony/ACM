//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

//---------------------------------------------------------------------------

#pragma argsused
#include <iostream.h>

int main(int argc, char* argv[])
{
  int a[110][110],x[110],y[110],p[110];
  int N,I,n,m,i,j,k,xs,ys,fx,fy;
  cin>>N;
  for (I=0;I<N;I++)
  {
    if (I) cout<<endl;
    cin>>n;
    for (i=1;i<=n;i++)
      for (j=1;j<=n;j++)
        a[i][j]=0;

    for (i=1;i<=n;i++)
    {
      cin>>m;
      p[i]=0;
      while (m)
      {
        a[i][m]=1;
        cin>>m;
        p[i]++;
      }
    }

    fx=1;
    for (i=2;i<=n;i++)
      if (p[i]<p[fx])
        fx=i;
    for (i=1;i<=n;i++)
      if (i!=fx)
        if (a[fx][i]==0) break;

    if (i>n) fy=(fx+1)%n;
    else     fy=i;

    x[0]=fx;
    y[0]=fy;
    xs=1;
    ys=1;
    for (i=1;i<=n;i++)
    if (i!=fx && i!=fy)
    {
      for (j=0;j<xs;j++)
        if (a[i][x[j]]==0 || a[x[j]][i]==0) break;
      for (k=0;k<ys;k++)
        if (a[i][y[k]]==0 || a[y[k]][i]==0) break;

      if (j==xs && k==ys)
        if (xs>ys)
          y[ys++]=i;
        else
          x[xs++]=i;
      else
        if (j==xs)
          x[xs++]=i;
        else
          if (k==ys)
            y[ys++]=i;
          else
            break;
    }
    if (i<=n)
      cout<<"No solution"<<endl;
    else
    {
      cout<<xs;
      for (i=0;i<xs;i++)
        cout<<' '<<x[i];
      cout<<endl;
      cout<<ys;
      for (i=0;i<ys;i++)
        cout<<' '<<y[i];
      cout<<endl;
    }
  }
  return 0;
}
//---------------------------------------------------------------------------
