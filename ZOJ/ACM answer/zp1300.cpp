//---------------------------------------------------------------------------

#pragma hdrstop

//---------------------------------------------------------------------------

#pragma argsused
#include <iostream.h>
int main(int argc, char* argv[])
{
  int l,n,I,i,j,x,y;
  char s[1200];
  int a[32][32];
  cin>>n;
  for (I=1;I<=n;I++)
  {
    for (i=0;i<32;i++)
      for (j=0;j<32;j++)
        a[i][j]=0;
    cin>>x>>y;
    cin>>s;
    i=0;
    while (s[i]!='.')
    {
      switch (s[i])
      {
        case 'E':a[x][y-1]=1;x++;break;
        case 'N':a[x][y]=1;  y++;break;
        case 'W':a[x-1][y]=1;x--;break;
        case 'S':a[x-1][y-1]=1;y--;break;
      }
      i++;
    }
    cout<<"Bitmap #"<<I<<endl;
    for (i=31;i>=0;i--)
    {
      for (j=0;j<32;j++)
        if (a[j][i]) cout<<'X'; else cout<<'.';
      cout<<endl;
    }
    cout<<endl;
  }
  return 0;
}
//---------------------------------------------------------------------------
 