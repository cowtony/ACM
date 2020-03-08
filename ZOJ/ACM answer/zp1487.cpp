//---------------------------------------------------------------------------

#pragma hdrstop

//---------------------------------------------------------------------------

#pragma argsused
#include <iostream.h>
int main(int argc, char* argv[])
{
  int a[2010],p[2010],i,m,n,j,s,k,r;
  while (cin>>n>>m)
  {
    for (i=0;i<n;i++)
      p[i]=1;
    j=-1;
    for (i=1;i<=n;i++)
    {
      r=m%(n-i+1);
      s=0;
      while (s<=r)
      {
        j++;
        if (j==n) j=0;
        s+=p[j];
      }
      a[j]=i;p[j]=0;
    }
    cout<<a[0];
    for (i=1;i<n;i++)
      cout<<' '<<a[i];
    cout<<endl;
  }

  return 0;
}
//---------------------------------------------------------------------------
 