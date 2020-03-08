//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

//---------------------------------------------------------------------------

#pragma argsused
#include <iostream>
#include <string>
using namespace std;
int main(int argc, char* argv[])
{
  char str[110],stq[110];
  char ch,fch;
  int i,j,n,r,t,p[110]; ///
  while (cin>>str)
  if (str[0]=='e')
  {
    cin>>str;
    n=strlen(str);
    for (i=0;i<n;i++)
      p[i]=1;
    for (i=0;i<n;i++)
    {
      ch='z'+1;
      for (j=0;j<n;j++)
        if (str[j]<ch && p[j])
        { r=j; ch=str[j]; }
      cout<<str[(r+n-1)%n];
      p[r]=0;
    }
    cout<<endl;
  }
  else
  {
    cin>>str;
    n=strlen(str);
    fch=str[--n];
    str[n]='\0';

    for (i=0;i<n;i++)
      p[i]=1;
    for (i=0;i<n;i++)
    {
      ch='z'+1;
      for (j=0;j<n;j++)
        if (str[j]<ch && p[j])
        { r=j; ch=str[j]; }
      stq[i]=str[r];
      p[r]=0;
    }

    for (i=0;i<n;i++)
      if (stq[i]==fch) break;
    t=i;
    p[0]=t;

    for (i=1;i<n;i++)
    {
      for (j=n-1;j>=0;j--)
        if (str[t]==stq[j])
          break;
      t=j;
      p[i]=t;
      stq[t]=' ';
    }
    for (i=n-1;i>=0;i--)
      cout<<str[p[i]];
    cout<<endl;
  }
  return 0;
}
//---------------------------------------------------------------------------
