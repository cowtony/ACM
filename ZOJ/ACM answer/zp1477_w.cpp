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
  char str[110],stq[110],stt[110];
  char ch,fch;
  int i,j,n,t; ///
  while (cin>>str)
  if (str[0]=='e')
  {
    cin>>str;
    n=strlen(str);
    stq[0]=str[n-1];
    for (i=1;i<n;i++)
      stq[i]=str[i-1];
    for (i=0;i<n-1;i++)
      for (j=i+1;j<n;j++)
        if (str[i]>str[j])
        { ch=stq[i]; stq[i]=stq[j]; stq[j]=ch;
          ch=str[i]; str[i]=str[j]; str[j]=ch; }

    cout<<stq<<endl;
  }
  else
  {
    cin>>str;
    n=strlen(str);
    fch=str[--n];
    str[n]='\0';
    for (i=0;i<n;i++)
      stq[i]=str[i];
    for (i=0;i<n-1;i++)
      for (j=i+1;j<n;j++)
        if (stq[i]>stq[j])
        { ch=stq[i]; stq[i]=stq[j]; stq[j]=ch; }

    for (i=0;i<n;i++)
      if (stq[i]==fch) break;
    stt[n-1]=str[i];
    t=i;

    i=n-2;
    for (j=n-1;i>=0;j--)
      if (str[t]==stq[j])
      {
        stt[i]=str[j];
        stq[j]=' ';
        t=j;
        i--;
        j=n;
      }
    cout<<stt<<endl;
  }
  return 0;
}
//---------------------------------------------------------------------------
