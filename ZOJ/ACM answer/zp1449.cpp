//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

//---------------------------------------------------------------------------

#pragma argsused
#include <iostream.h>

int main(int argc, char* argv[])
{
  int n,i,j,k,l,p,mx,sum;
  int fr[22][22][22],ar[22][22],tr[22];
  cin>>n;
  while (n)
  {
    for (j=1;j<=n;j++)
      for (k=1;k<=n;k++)
        fr[0][j][k]=0;

    mx=-128;
    for (i=1;i<=n;i++)
      for (j=1;j<=n;j++)
        for (k=1;k<=n;k++)
        {
          cin>>p;
          if (p>mx) mx=p;
          fr[i][j][k]=fr[i-1][j][k]+p;
        }

    for (i=0;i<n;i++)
      for (j=i+1;j<=n;j++)
      {
        for (k=1;k<=n;k++)
          ar[0][k]=0;
        for (k=1;k<=n;k++)
          for (l=1;l<=n;l++)
            ar[k][l]=ar[k-1][l]+fr[j][k][l]-fr[i][k][l];
        for (k=0;k<n;k++)
          for (l=k+1;l<=n;l++)
          {
            for (p=1;p<=n;p++)
              tr[p]=ar[l][p]-ar[k][p];
            sum=0;
            for (p=1;p<=n;p++)
            {
              sum+=tr[p];
              if (sum<=0)
                sum=0;
              else if (sum>mx)
                mx=sum;
            }
          }
      }
    cout<<mx<<endl;
    cin>>n;
  }
  return 0;
}
//---------------------------------------------------------------------------
