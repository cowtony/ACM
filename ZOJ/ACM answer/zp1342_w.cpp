//---------------------------------------------------------------------------

#pragma hdrstop

//---------------------------------------------------------------------------

#pragma argsused
#include <iostream>
#include <string>
using namespace std;

int main(int argc, char* argv[])
{
  string st;
  int r[10],p[10],ll,i,s;
  while (cin>>st)
  {
    memset(r,0,sizeof(int)*10);
    ll=st.length();
    for(i=ll-1;i>=0;i--)
    {
      r[ll-i-1]=st[i]-'a'+1;
      if (i<ll-1 && st[i]>st[i+1] ) break;
    }
    if (l>5 || i!=-1 )
      cout<<0;
    else
    {
      memset(p,0,sizeof(int)*10);
      s=0;
      while (1)
      {
        p[0]++; s++;
        for (i=0;i<4;i++)
          if (p[i]==27)
          { p[i+1]++; p[i]=p[i+1]+1; }
          else break;
        for (i=4;i>=0;i--)
          if (r[i]!=p[i]) break;
        if (i=-1) break;
      }
      cout<<s;
    }
    cout<<endl;
  }
  return 0;
}
//---------------------------------------------------------------------------
 