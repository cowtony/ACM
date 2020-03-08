//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

//---------------------------------------------------------------------------

#pragma argsused
#include <iostream.h>
int main(int argc, char* argv[])
{
  int n,i,j,m,x,y,s,p[11][11];
  char st[11][11];
  cin>>n>>m>>x;
  while (m+n+x)
  {
    for (i=1;i<=n;i++)
      for (j=1;j<=m;j++)
      {
        cin>>st[i][j];
        p[i][j]=-1;
      }
    y=x;
    x=1; s=0;
    p[x][y]=0;
    while (1)
    {
      s++;
      switch (st[x][y])
      {
        case 'E': y++; break;
        case 'W': y--; break;
        case 'N': x--; break;
        case 'S': x++; break;
      }
      if (x<1 || x>n || y<1 || y>m)
      {
        cout<<s<<" step(s) to exit"<<endl;
        break;
      }
      if (p[x][y]>=0)
      {
        cout<<p[x][y]<<" step(s) before a loop of "
            <<s-p[x][y]<<" step(s)"<<endl;
        break;
      }
      p[x][y]=s;
    }
    cin>>n>>m>>x;
  }
  return 0;
}
//---------------------------------------------------------------------------
