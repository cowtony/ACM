//---------------------------------------------------------------------------

#pragma hdrstop

//---------------------------------------------------------------------------

#pragma argsused
#include <iostream.h>
int main(int argc, char* argv[])
{
  int n,x,m,i,j,k,t,z=0;
  int a[33],p[55];
  while (cin>>n)
  {
    cin>>x;
    z++;
    for (i=1;i<21;i++)
      cin>>a[i];
    for (i=1;i<=n;i++)
      p[i]=1;
    m=n;
    k=1;
    while (m>x)
    {
      i=0;j=0;
      while (j<=n)
      {
        j++;
        if (p[j])
        {
          i++;
          if (i==a[k])
          {
            p[j]=0; i=0;
            if (j<=n) m--;
            if (m==x) break;
          }
        }
      }
      if (m!=x)
        k++;
    }
    cout<<"Selection #"<<z<<endl;
    t=0;
    for (i=1;i<=n;i++)
    {
      if (!t && p[i]) t=1; else if (p[i]) cout<<' ';
      if (p[i]) cout<<i;
    }
    cout<<endl<<endl;

  }
  return 0;
}
//---------------------------------------------------------------------------
 