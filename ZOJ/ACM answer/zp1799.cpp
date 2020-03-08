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
  int l,ln,i,j,s,a[12],p[12];
  char ch,st[12],sq[12],str[110],stt[110];
  cin>>st;
  while (strcmp(st,"THEEND"))
  {
    cin>>str;
    l=strlen(st);

    strcpy(sq,st);
    for (i=0;i<l-1;i++)
      for (j=i+1;j<l;j++)
        if (st[i]>st[j])
        {
          ch=st[i];
          st[i]=st[j];
          st[j]=ch;
        }

    for (i=0;i<l;i++)
      p[i]=1;
    for (i=0;i<l;i++)
      for (j=0;j<l;j++)
        if (st[i]==sq[j] && p[j])
        {
          a[i]=j;
          p[j]=0;
          break;
        }

    ln=strlen(str);
    for (i=0;i<ln;i++)
      stt[i]=' ';
    s=0;
    for (i=0;i<l;i++)
      for (j=a[i];j<ln;j+=l)
        stt[j]=str[s++];

    stt[ln]='\0';
    cout<<stt<<endl;
    cin>>st;
  }
  return 0;
}
//---------------------------------------------------------------------------
