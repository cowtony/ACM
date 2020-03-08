//---------------------------------------------------------------------------

#pragma hdrstop

//---------------------------------------------------------------------------

#pragma argsused
#include <iostream>
using namespace std;
int main(int argc, char* argv[])
{
  int m,n,i,j,a,s,r[2000],t=1;
  cin>>m>>n;
  while (m || n)
  {
    for (i=1;i<=n*m+1;i++)
      r[i]=0;
    for (i=1;i<=n;i++)
    {
      cin>>a;
      r[a]=1;
    }
    s=0;
    for (i=n*m;i>0;i--)
      if (r[i])
      {
        j=i;
        while (r[j])
          j++;
        if (j==n*m+1)
          s++;
        else
          r[j]=1;
      }
    cout<<"Case "<<t<<": "<<s<<endl;

    cin>>m>>n;
    t++;
  }
  return 0;
}
//---------------------------------------------------------------------------
