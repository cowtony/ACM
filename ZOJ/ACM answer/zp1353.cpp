//---------------------------------------------------------------------------

#pragma hdrstop

//---------------------------------------------------------------------------

#pragma argsused

#include <iostream.h>
#include <iomanip.h>

double gm[500][500];

inline double mg(int n,int m)
{
  if (m>n)
  {
    if (gm[n][n]==0)
      gm[n][n]=mg(n,n);
    return gm[n][n];
  }
  else
    if (m<=1 || n<=1)
      if (m<0 || n<0)
        return 0;
      else
        return 1;
    else
    {
      int s=0;
      for (int i=1;i<=m;i++)
      {
        if (n-i>=0)
        {
          if (gm[n-i][i]==0)
            gm[n-i][i]=mg(n-i,i);
          s+=gm[n-i][i];
        }
      }
      return s;
    }
}
int main(int argc, char* argv[])
{
  int n,i,j;
  double sum=0;
  cin>>n;
  for (i=2;i<=500;i++)
    for (j=2;j<=500;j++)
      gm[i][j]=0;
  for (i=1;i<=500;i++)
  {
    gm[i][1]=1;
    gm[1][i]=1;
    gm[0][i]=1;
    gm[i][0]=1;
  }
  cout<<setiosflags(ios::fixed)<<setprecision(0);
  while (n)
  {
    sum=0;
    for (i=n;i>0;i-=2)
    {
      if (gm[(n-i)/2][i]==0)
        gm[(n-i)/2][i]=mg((n-i)/2,i);
      sum+=gm[(n-i)/2][i];
    }
    if (!(n%2))
    {
      if (gm[n/2][n/2]==0)
        gm[n/2][n/2]=mg(n/2,n/2);
      sum+=gm[n/2][n/2];
    }
    cout<<n<<' '<<sum<<endl;
    cin>>n;
  }
  return 0;
}
//---------------------------------------------------------------------------

