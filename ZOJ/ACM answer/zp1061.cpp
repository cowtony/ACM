//---------------------------------------------------------------------------

#pragma hdrstop

//---------------------------------------------------------------------------

#pragma argsused
#include <iostream.h>
#include <string.h>
int main(int argc, char* argv[])
{
  int I,N,f,p,m;
  string s,stp;
  string st[110];
  cin>>N;
  st[0]="http://www.acm.org/";
  stp="Ignored";
  for(I=1;I<=N;I++)
  {
    if (I-1) cout<<endl;
    f=1;p=0;m=0;
    while (f)
    {
      cin>>s;
      switch (s[0])
      {
        case 'B': if (p) cout<<st[--p]<<endl;
                  else cout<<stp<<endl;   break;
        case 'F':if (m-p) cout<<st[++p]<<endl;
                 else cout<<stp<<endl;  break;
        case 'V': cin>>st[++p];
                  cout<<st[p]<<endl; m=p;break;
        case 'Q':f=0;break;
      }
    }
  }
  return 0;
}
//---------------------------------------------------------------------------
