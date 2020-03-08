//---------------------------------------------------------------------------

#pragma hdrstop

//---------------------------------------------------------------------------

#pragma argsused
#include <iostream>
#include <string>
using namespace std;
int main(int argc, char* argv[])
{
  int sl,c,s,t,i;
  string st;
  int ai[100],xl[200];
  cout<<"Problem 4 by team x"<<endl;
  while(cin>>st)
  {
    cout<<endl<<1<<" / "<<st<<" ="<<endl<<"0.";
    sl=st.length();

    s=0;
    for (i=0;i<sl;i++)
    {
      ai[i]=st[i]-'0';
      s+=(ai[i]!=0);
    }
    if (s>1) cout<<'0';
    for (i=1;i<sl-1;i++)
      cout<<'0';
    c=1;
    for (i=1;i<200;i++)
      xl[i]=0;
    xl[0]=1;
    while(1)
    {
      s=0;
      while(1)
      {
        for (i=c;i<c+sl;i++)
          xl[i]-=ai[i-c];
        for (i=c+sl-1;i>=c;i--)
          if (xl[i]<0)
          {
            xl[i]+=10;
            xl[i-1]--;
          }
        if (xl[c-1]<0)
        {
          for (i=c;i<c+sl;i++)
            xl[i]+=ai[i-c];
          for (i=c+sl-1;i>=c;i--)
            if (xl[i]>9)
            {
              xl[i]-=10;
              xl[i-1]++;
            }
          break;
        }
        s++;
      }
      if (s<10)
        cout<<s;
      else
        cout<<1;
      t=1;
      for (i=c-1;i<c+sl;i++)
        if (xl[i]!=0)
          t=0;
      if (t) break;
      c++;
    }
    cout<<endl;
  }
  cout<<"End of problem 4 by team x"<<endl;
  return 0;
}
//---------------------------------------------------------------------------
