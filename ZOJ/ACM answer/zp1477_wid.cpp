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
  char str[110];
  int len,i,j,t,id[110],p[110],r[110];
  char ch;
  while (cin>>str)
  if (str[0]=='e')
  {
    cin>>str;
    len=strlen(str);
    for (i=0;i<len;i++)
      id[i]=i;
    for (i=0;i<len;i++)
      for (j=i+1;j<len;j++)
        if (str[id[i]]>str[id[j]])
        {
          t=id[i];
          id[i]=id[j];
          id[j]=t;
        }
    for (i=0;i<len;++i)
      cout<<str[(id[i]+len-1)%len];
    cout<<endl;
  }
  else
  {
    cin>>str;
    len=strlen(str);
    ch=str[len-1];
    str[--len]='\0';
    for (i=0;i<len;++i)
      id[i]=i;
    for (i=0;i<len;++i)
      for (j=i+1;j<len;++j)
        if (str[id[i]]>=str[id[j]])
        {
          t=id[i];
          id[i]=id[j];
          id[j]=t;
        }
    for (i=0;i<len;i++)
      if ((str[id[i]]==ch)) break;
    r[0]=i;

    for (j=0;j<len;j++)
      p[j]=1;

    ch=str[i];
    p[i]=0;
    for (j=1;j<len;j++)
    {
      for (i=len-1;i>=0;i--)
        if ((str[id[i]]==ch) && p[i]) break;
      r[j]=i;
      ch=str[i];
      p[i]=0;
    }
    for (i=len-1;i>=0;i--)
      cout<<str[r[i]];
    cout<<endl;
  }

  return 0;
}
//---------------------------------------------------------------------------
