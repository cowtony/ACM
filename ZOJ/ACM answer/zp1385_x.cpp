//---------------------------------------------------------------------------

#pragma hdrstop

//---------------------------------------------------------------------------

#pragma argsused
#define cout fout
#include <fstream.h>

int main(int argc, char* argv[])
{
  ofstream fout("out1385x.txt");
  const max=400;
  int a[max+1][max+1];
  int i,j;
  for (i=1;i<=max;i++)
  { a[i][0]=0; a[0][i]=0; }
  a[0][0]=1;
  for (i=1;i<=max;i++)
    for (j=1;j<=max;j++)
      a[j][i]=(i*a[j-1][i]+a[j-1][i-1])%2;
  for (i=0;i<=max;i++)
  {
    for (j=0;j<=max;j++)
      if (i+j<=max)
      if (a[i+j][j])
        cout<<"X";
      else
        cout<<" ";
    cout<<endl;
  }

  return 0;
}
//---------------------------------------------------------------------------
 