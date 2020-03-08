#include <iostream>
#include <string>
using namespace std;


int main(int argc, char* argv[])
{
  int i,j,k,s,n;
  int w[15][10]={ {1,1,1,0,1,1,1},
                {0,0,1,0,0,1,0},
                {1,0,1,1,1,0,1},
                {1,0,1,1,0,1,1},
                {0,1,1,1,0,1,0},
                {1,1,0,1,0,1,1},
                {1,1,0,1,1,1,1},
                {1,0,1,0,0,1,0},
                {1,1,1,1,1,1,1},
                {1,1,1,1,0,1,1} };
  string st;

  cin>>s>>st;
  n=st.length();
  while (s>0 || !(n==1 && st[0]=='0'))
  {

    cout<<' ';
    for (j=0;j<s;j++)
      if (w[st[0]-'0'][0])   cout<<'-';
      else                   cout<<' ';
    cout<<' ';
    for (i=1;i<n;i++)
    {
      cout<<"  ";
      for (j=0;j<s;j++)
        if (w[st[i]-'0'][0]) cout<<'-';
        else                 cout<<' ';
      cout<<' ';
    }
    cout<<endl;

    for (j=0;j<s;j++)
    {
      if (w[st[0]-'0'][1])   cout<<'|';
      else                   cout<<' ';
      for (k=0;k<s;k++)
        cout<<' ';
      if (w[st[0]-'0'][2])   cout<<'|';
      else                   cout<<' ';

      for (i=1;i<n;i++)
      {
        cout<<' ';
        if (w[st[i]-'0'][1]) cout<<'|';
        else                 cout<<' ';
        for (k=0;k<s;k++)
          cout<<' ';
        if (w[st[i]-'0'][2]) cout<<'|';
        else                 cout<<' ';
      }
      cout<<endl;
    }


    cout<<' ';
    for (j=0;j<s;j++)
      if (w[st[0]-'0'][3])   cout<<'-';
      else                   cout<<' ';
    cout<<' ';
    for (i=1;i<n;i++)
    {
      cout<<"  ";
      for (j=0;j<s;j++)
        if (w[st[i]-'0'][3]) cout<<'-';
        else                 cout<<' ';
      cout<<' ';
    }
    cout<<endl;

    for (j=0;j<s;j++)
    {
      if (w[st[0]-'0'][4])   cout<<'|';
      else                   cout<<' ';
      for (k=0;k<s;k++)
        cout<<' ';
      if (w[st[0]-'0'][5])   cout<<'|';
      else                   cout<<' ';

      for (i=1;i<n;i++)
      {
        cout<<' ';
        if (w[st[i]-'0'][4]) cout<<'|';
        else                 cout<<' ';
        for (k=0;k<s;k++)
          cout<<' ';
        if (w[st[i]-'0'][5]) cout<<'|';
        else                 cout<<' ';
      }
      cout<<endl;
    }


    cout<<' ';
    for (j=0;j<s;j++)
      if (w[st[0]-'0'][6])   cout<<'-';
      else                   cout<<' ';
    cout<<' ';
    for (i=1;i<n;i++)
    {
      cout<<"  ";
      for (j=0;j<s;j++)
        if (w[st[i]-'0'][6]) cout<<'-';
        else                 cout<<' ';
      cout<<' ';
    }
    cout<<endl;
    cout<<endl;

    cin>>s>>st;
    n=st.length();
  }
  return 0;
}
//---------------------------------------------------------------------------
