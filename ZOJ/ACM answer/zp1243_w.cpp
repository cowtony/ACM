//---------------------------------------------------------------------------

#pragma hdrstop

//---------------------------------------------------------------------------

#pragma argsused
#define cin fin
#include <fstream>
#include <iostream>
#include <string>
using namespace std;
int main(int argc, char* argv[])
{
  ifstream fin("d:\in1243.txt");
  int n,I,i,k,p,h,l;
  string st;
  cin>>n;
  for (I=1;I<=n;I++)
  {
    cin>>st;
    l=st.length();
    st[l]='!';
    i=0;
    while (st[++i]!=':') {}
    p=i;
    i+=2;
    while (st[++i]!='/' && st[i]!='!') {}
    h=i;
    i=p+3;
    while (st[++i]!=':' && st[i]!='!') {}
    k=i;if (st[i]=='!') k=h;
    cout<<"URL #"<<I<<endl<<"Protocol = ";
    for (i=0;i<p;i++)
      cout<<st[i];
    cout<<endl<<"Host     = ";
    for (i=p+3;i<k;i++)
      cout<<st[i];
    cout<<endl<<"Port     = ";
    if (st[k+1]=='!' || k==h) cout<<"<default>";
    else for (i=k+1;i<h;i++)
      cout<<st[i];
    cout<<endl<<"Path     = ";
    if (st[h]=='!') cout<<"<default>";
    else for (i=h+1;i<l;i++)
      cout<<st[i];
    cout<<endl<<endl;
  }
  return 0;
}
//---------------------------------------------------------------------------
