//---------------------------------------------------------------------------

#pragma hdrstop

//---------------------------------------------------------------------------

#pragma argsused
#include <iostream.h>
  int a[510][510];
int main(int argc, char* argv[])
{
  int N,I,K,n,m,i,j,k,x,r1,r2,c1,c2,s;
  cin>>N;
  for (I=0;I<N;I++)
  {
    cin>>n>>m;
    for (i=1;i<=n;i++)
      for (j=1;j<=m;j++)
      { cin>>x; a[i][j]=a[i-1][j]+x*x; }

    cin>>K;
    cout<<"Case "<<I+1<<':'<<endl;
    for (k=0;k<K;k++)
    {
      cin>>r1>>c1>>r2>>c2;
      r1--;
      s=0;
      for (i=c1;i<=c2;i++)
        s+=a[r2][i]-a[r1][i];
      cout<<s<<endl;
    }
  }
  return 0;
}
//---------------------------------------------------------------------------
 