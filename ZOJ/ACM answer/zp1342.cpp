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
  int r[10],p[7][30],a[10],l,j,i,s,h,t;

  for (i=1;i<=26;i++)
  { p[1][i]=1; p[2][i]=i; }
  a[1]=p[2][26];
  a[0]=0;
  for (i=3;i<6;i++)
  {
    s=0;
    for (j=1;j<=28-i;j++)
    { s+=p[i-1][j]; p[i][j]=s; }
    a[i-1]=s;
  }

  while (cin>>st)
  {
    memset(r,0,sizeof(int)*10);
    l=st.length();
    for(i=l-1;i>=0;i--)
    {
      r[l-i]=st[i]-'a'+1;
      if (i<l-1 && st[i]>st[i+1] ) break;
    }
    if (l>5 || i!=-1 )
      cout<<0;
    else
    {
      s=1;
      h=27-l;
      for (i=l;i>0;i--)
      {
        s+=a[i-1];
        t=h-r[i]+r[i+1]+1;
        for (j=h;j>t;j--)
          s+=p[i][j];
        h=t;
      }
      cout<<s;
    }
    cout<<endl;
  }
  return 0;
}
//---------------------------------------------------------------------------
