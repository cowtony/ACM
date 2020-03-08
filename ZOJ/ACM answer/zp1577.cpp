//---------------------------------------------------------------------------

#pragma hdrstop

//---------------------------------------------------------------------------

#pragma argsused
#include <math.h>
#include <iostream.h>
int main(int argc, char* argv[])
{
  int x,y,s,q,t,i,m,n,p;
  while (cin>>x>>y)
  {
    s=x*y;
    q=sqrt(s);
    t=0;
    for (i=x;i<=q;i++)
      if (s%i==0)
      {
        m=s/i;
        n=i;
        while (n)
        {
          p=m%n; m=n; n=p;
        }
        if (m==x)
          if (i==q && q*q==s)
            t++;
          else
            t+=2;
      }
    cout<<t<<endl;
  }
  return 0;
}
//---------------------------------------------------------------------------
 