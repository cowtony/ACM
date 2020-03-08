//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

//---------------------------------------------------------------------------

#pragma argsused
#include <iostream.h>

int main(int argc, char* argv[])
{
  int i,n,k,j,r,s,d,p[1010]={1};

  while (cin>>n)
  {
    r=0;
    for (i=1;i<=9;i++)
    {
      for (j=1;j<n;j++)
        p[j]=0;
      k=0;s=0;
      while (1)
      {
        s++;
        k*=10;
        k+=i;
        k%=n;
        if (p[k]) break;
        p[k]=1;
      }
      if (k==0)
      {
        r=1;
        break;
      }
    }
    if (r)
      cout<<i<<' '<<s<<endl;
    else
      cout<<-1<<endl;
  }
  return 0;
}
//---------------------------------------------------------------------------
