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
  int cs,m,n,sp,sf,i,j,k;
  char ch, str[30],sq[30];
  cs=0;
  while (cin>>str)
  {
    if (strcmp(str,"STOP")==0) break;
    if (cs) cout<<endl;
    n=strlen(str);
    sp=0;sf=n-1;
    cin>>m;

    cout<<"Dataset #"<<++cs<<":  The initial order is "
        <<str<<'.'<<endl;
    for (i=0;i<m;i++)
    {
      cin>>ch;
      cout<<"After "<<ch<<" leaves, the order is ";
      for (j=sp;j<=sf;j++)
        if (str[j]==ch) break;
      j-=sp;
      n=sf-sp;
      if (j>n/2)
      {
        for (k=0;k<n-j;k++)
          sq[k]=str[sf-k];
        for (k=j;k<n;k++)
          str[k+sp]=sq[k-j];
        sf--;
      }
      else
      {
        for (k=sp;k<j+sp;k++)
          sq[k-sp]=str[j-k-1+sp+sp];
        for (k=1+sp;k<=j+sp;k++)
          str[k]=sq[k-1-sp];
        sp++;
      }
      for (j=sp;j<=sf;j++)
        cout<<str[j];
      cout<<'.'<<endl;
    }
  }
  return 0;
}
//---------------------------------------------------------------------------
 