//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

//---------------------------------------------------------------------------

#pragma argsused
#include <iostream.h>
int main(int argc, char* argv[])
{
  char snn[6];
  int a[1100],r[6],w[12];
  int ln,i,j,m,n;
  while (cin>>snn)
  {
    ln=strlen(snn);
    for (i=1;i<=ln;i++)
      r[i]=snn[ln-i]-'0';
    for (i=1;i<=ln;i++)
      a[i]=r[i];
    n=ln;

    cin>>m;
    for (i=0;i<10;i++)
      w[i]=0;

    for (i=1;i<=m;i++)
    { cin>>j; w[j]=1; }

    while (1)
    {
      for (i=1;i<=n;i++)
        a[i]+=r[i];
      a[ln+1]=0;
      for (i=1;i<=ln;i++)
        if (a[i]>9)
        {
          a[i+1]++;
          a[i]-=10;
          if (i==ln) ln++;
        }
      for (i=1;i<=ln;i++)
        if (!w[a[i]]) break;
      if (i>ln) break;
    }

    for (i=ln;i>0;i--)
      cout<<a[i];

    cout<<endl;
  }
  return 0;
}
//---------------------------------------------------------------------------
 