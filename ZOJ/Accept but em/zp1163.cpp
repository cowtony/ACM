//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

//---------------------------------------------------------------------------

#pragma argsused
#include <stdio.h>
//#include <iostream.h>
unsigned long long a[510][260]={0};

int main(int argc, char* argv[])
{
  int i,j,k,n;
  a[3][1]=1;
  a[3][0]=1;
  for (i=4;i<=500;i++)
    for (j=1;j<=(i-1)/2;j++)
    {
      a[i][j]=1;
      for (k=1;k<=(i-j*3-1)/2;k++)
        a[i][j]+=a[i-j][j+k];
      a[i][0]+=a[i][j];
    }

  scanf("%d",&n);
  while (n)
  {
    //cout<<a[n][0]<<endl;
    printf("%Ld\n",a[n][0]);
    scanf("%d",&n);
  }
  return 0;
}
//---------------------------------------------------------------------------
