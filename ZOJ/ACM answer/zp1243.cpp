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
  int N,I,i,r,t,s,l;
  char st[63];

  cin>>N;
  for (I=1;I<=N;I++)
  {
    cout<<"URL #"<<I<<endl;
    cin>>st;
    l=strlen(st);
    for (i=0;i<l;i++)
      if (st[i]==':')
        break;
    cout<<"Protocol = ";
    t=i;
    for (i=0;i<t;i++)
      cout<<st[i];
    cout<<endl;
    for (i=t+3;i<l;i++)
      if (st[i]==':' || st[i]=='/')
        break;
    r=i;

      cout<<"Host     = ";
      for (i=t+3;i<r;i++)
        cout<<st[i];
      cout<<endl;

    if (r==l)
    {
      cout<<"Port     = <default>"<<endl;
      cout<<"Path     = <default>"<<endl;
    }
    else
    if (st[r]=='/')
    {
      cout<<"Port     = <default>"<<endl;
      cout<<"Path     = ";
      for (i=r+1;i<l;i++)
        cout<<st[i];
      cout<<endl;
    }
    else
    if (st[r]==':')
    {
      for (i=r+1;i<l;i++)
        if (st[i]=='/')
          break;
      s=i;

      cout<<"Port     = ";
      for (i=r+1;i<s;i++)
        cout<<st[i];
      cout<<endl;
      cout<<"Path     = ";
      if (s<l)
        for (i=s+1;i<l;i++)
          cout<<st[i];
      else	
        cout<<"<default>";
      cout<<endl;
    }
    cout<<endl;
  }
  return 0;
}
//---------------------------------------------------------------------------

