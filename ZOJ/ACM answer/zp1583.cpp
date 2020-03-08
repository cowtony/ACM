//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

//---------------------------------------------------------------------------

#pragma argsused
#include <iostream.h>
#include <stdio.h>

  int a[510][510],r[510][510];
int main(int argc, char* argv[])
{
  int i,j,k,l,n,cs=0;
  cin>>n;
  while (n)
  {
    cout<<"Case "<<++cs<<':'<<endl;
    for (i=0;i<n;i++)
      for (j=0;j<n;j++)
        scanf("%d",&a[i][j]);
    for (i=0;i<n;i++)
    {
      r[i][0]=a[i][0];
      r[i][n-1]=a[i][n-1];
      r[0][i]=a[0][i];
      r[n-1][i]=a[n-1][i];
    }
    for (i=1;i<n-1;i++)
      for (j=1;j<n-1;j++)
      {
        r[i][j]=a[i][j]*4;
        r[i][j]+=a[i-1][j-1]+a[i-1][j+1];
        r[i][j]+=a[i+1][j-1]+a[i+1][j+1];
        r[i][j]+=(a[i][j-1]+a[i-1][j])*2;
        r[i][j]+=(a[i][j+1]+a[i+1][j])*2;
        r[i][j]/=16;
      }
    for (i=0;i<n;i++)
    {
      for (j=0;j<n-1;j++)
        printf("%d ",r[i][j]);
      printf("%d\n",r[i][n-1]);
    }

    cin>>n;
  }
  return 0;
}
//---------------------------------------------------------------------------
 