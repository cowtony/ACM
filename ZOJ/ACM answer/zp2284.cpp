//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

//---------------------------------------------------------------------------

#pragma argsused
#include <iostream.h>
int main(int argc, char* argv[])
{
  int i,j,k,m,n;
  long long rt[22][200]={0};

  rt[1][1]=1;
  rt[2][1]=1;
  rt[2][0]=1;
  for (i=2;i<20;i++)
    for (j=0;rt[i][j];j++)
      for (k=0;k<i+1;k++)
        rt[i+1][j+k]+=rt[i][j];

  cin>>m>>n;
  while (n+m)
  {
    cout<<rt[m][n]<<endl;
    cin>>m>>n;
  }
  return 0;
}
//---------------------------------------------------------------------------
