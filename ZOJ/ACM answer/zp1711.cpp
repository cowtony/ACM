//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

//---------------------------------------------------------------------------

#pragma argsused
#include <iostream.h>
  int sum,m,n,s,p[13],a[13],r[13],nt;
void printit()
{
  int i;
  cout<<r[0];
  for (int i=1;i<nt;i++)
    cout<<'+'<<r[i];
  cout<<endl;
}
void getin(int d)
{
  int i,j;
  if (d<s)
    for (i=p[d];i>=0;i--)
    {
      sum+=a[d]*i;
      nt+=i;
      for (j=nt-i;j<nt;j++)
        r[j]=i;
      if (sum==m)
        printit();
      else
        if (sum<m)
          getin(d+1);
      sum-=a[d]*i;
      nt-=i;
    }
}

int main(int argc, char* argv[])
{
  int i,x;
  cin>>m>>n;
  while (m+n)
  {
    s=0;
    for (i=0;i<n;i++)
    {
      cin>>x;
      p[i]=0;
      if (p[s]==0 || x!=a[s])
      { a[s]=x; p[s++]=1; }
      else
        p[s]++;
    }
    nt=0;
    sum=0;
    getin(0);
  }
  return 0;
}
//---------------------------------------------------------------------------
