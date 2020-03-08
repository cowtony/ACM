//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

//---------------------------------------------------------------------------

#pragma argsused
#include <iostream.h>

int main(int argc, char* argv[])
{
  int a[5010],b[5010],i,j,n,t,s,c,I,N;
  cin>>N;
  for (I=0;I<N;I++)
  {
    cin>>n;
    for (i=1;i<=n;i++)
    {
      cin>>a[i]>>b[i];
      a[i]*=10010;
      a[i]+=b[i];
    }
    for (i=1;i<n;i++)
      for (j=i+1;j<=n;j++)
        if (a[i]>a[j])
        {
          t=a[i];a[i]=a[j];a[j]=t;
          t=b[i];b[i]=b[j];b[j]=t;
        }
    s=n;c=0;
    while (s)
    {
      t=0;
      for (i=1;i<=n;i++)
        if (b[i]>=t)
        { t=b[i];b[i]=-1; s--; }
      c++;
    }
    cout<<c<<endl;
  }
  return 0;
}
//---------------------------------------------------------------------------
