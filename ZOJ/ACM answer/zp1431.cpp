#include <iostream>
#include <string>
using namespace std;

int main(int argc, char* argv[])
{
  int i,j,f,s,t,m,n,a[20];
  string st,str[20];

  f=0;
  while (cin>>st)
  {
    if (f)
      cout<<endl;
    else
      f=1;
    s=0;
    while (cin>>st)
    {
      s++;
      if (st=="END") break;
      str[s]=st;
      cin>>m>>n;
      a[s]=n-m;
    }
    for (i=1;i<s;i++)
      for (j=i+1;j<s;j++)
        if (a[i]<a[j])
        { t=a[i];a[i]=a[j];a[j]=t;
          st=str[i];str[i]=str[j];str[j]=st; }

    for (i=1;i<s;i++)
      cout<<str[i]<<endl;
  }
  return 0;
}
//---------------------------------------------------------------------------
