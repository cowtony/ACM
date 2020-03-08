//---------------------------------------------------------------------------

#pragma hdrstop

//---------------------------------------------------------------------------

#pragma argsused
#include <iostream.h>
void getin(int n,int b)
{
  int i;
  if (n>=b)
  if ((n-b)%2)
  {
    for (i=b;i<n;i++)
      cout<<i<<' ';
    cout<<n<<endl;
    getin(n,b+1);
  }
  else
  {
    cout<<b;
    for (i=b+2;i<=n;i++)
      cout<<' '<<i;
    cout<<endl;
    for (i=b+1;i<n;i++)
      cout<<i<<' ';
    cout<<n<<endl;
    for (i=b+1;i<n;i++)
      cout<<i<<' ';
    cout<<n<<endl;
    getin(n,b+3);
  }
}
int main(int argc, char* argv[])
{
  int n;
  cin>>n;
  while (n)
  {
    if ( (n*(n+1)/2)%2 )
      cout<<0<<endl;
    else
    {
      cout<<n<<endl;
      getin(n,1);
    }
    cout<<endl;
    cin>>n;
  }
  return 0;
}
//---------------------------------------------------------------------------
 