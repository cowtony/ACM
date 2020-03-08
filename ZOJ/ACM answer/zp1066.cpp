//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

//---------------------------------------------------------------------------

#pragma argsused
#include <iostream.h>
int main(int argc, char* argv[])
{
  int y[4]={0,-1,1,0};
  int x[4]={-1,0,0,1};
  int n,cs,i,j,k,t,a[15][15],r[30][30]={0};
  cin>>n;
  cs=0;
  while (n)
  {
    for (i=1;i<=n;i++)
      for (j=1;j<=n;j++)
        cin>>a[i][j];
    for (j=1;j<=n+n+1;j++)
    { r[1][j]=0; r[n+n+1][j]=0; }
    for (i=2;i<=n+n;i++)
      for (j=1;j<=n+n+1;j++)
        r[i][j]=-1;
    for (i=1;i<=n;i++)
    {
      for (j=1;j<=n;j++)
      {
        if (a[i][j]>0)
        {
          r[i+i][j+j+1]=3;
          r[i+i][j+j-1]=2;
          r[i+i][j+j]=0;
        }
        if (a[i][j]<0)
        {
          r[i+i-1][j+j]=1;
          r[i+i+1][j+j]=4;
          r[i+i][j+j]=0;
        }
      }
      for (j=1;j<=n;j++)
        if (!a[i][j])
        {
          r[i+i][j+j]=0;
          t=2;
          for (k=1;k<=4;k++)
            if (t && r[i+i+x[k-1]][j+j+y[k-1]]<0)
            {
              r[i+i+x[k-1]][j+j+y[k-1]]=k;
              t--;
              if (k==2) k++;
            }
        }
    }

    if (cs) cout<<endl;
    cout<<"Case "<<++cs<<':'<<endl<<endl;
    for (j=1;j<=n+n+n+n+3;j++)
      cout<<'*'; cout<<endl;
    for (i=2;i<=n+n;i+=2)
    {
      cout<<"*H";
      for (j=1;j<=n+n;j++)
      {
        if (r[i][j]==2 || r[i][j+1]==3)
          cout<<'-';
        else
          cout<<' ';
        if (r[i][j+1]==0)
          cout<<'O';
        else
          cout<<'H';
      }
      cout<<'*'<<endl;
      if (i<n+n)
      {
        cout<<'*'<<' ';
        for (j=1;j<=n+n;j++)
        {
          cout<<' ';
          if (r[i+1][j+1]==4)
            cout<<'|';
          else
            cout<<' ';
        }
        cout<<'*'<<endl;

        cout<<'*'<<' ';
        for (j=1;j<=n+n;j++)
        {
          cout<<' ';
          if (r[i+1][j+1]==1 || r[i+1][j+1]==4)
            cout<<'H';
          else
            cout<<' ';
        }
        cout<<'*'<<endl;

        cout<<'*'<<' ';
        for (j=1;j<=n+n;j++)
        {
          cout<<' ';
          if (r[i+1][j+1]==1)
            cout<<'|';
          else
            cout<<' ';
        }
        cout<<'*'<<endl;
      }
    }
    for (j=1;j<=n+n+n+n+3;j++)
      cout<<'*'; cout<<endl;

    cin>>n;
  }
  return 0;
}
//---------------------------------------------------------------------------
