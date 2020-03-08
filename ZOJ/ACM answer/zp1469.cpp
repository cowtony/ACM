//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

//---------------------------------------------------------------------------

#pragma argsused
#include <iostream.h>
#include <iomanip.h>

int x[24],y[24],r[24],s,m;

void doit(int n, int d)
{
  if (d>m) m=d;
  int i;
  if (n%11<10)
  {
    x[s]=n/11;
    y[s]=x[s]*10+n%11;
    for (i=d-1;i>=0;i--)
    {
      x[s]*=10;
      x[s]+=r[i];
      y[s]*=10;
      y[s]+=r[i];
    }
    s++;
  }
  if (n%2==0)
  {
    r[d]=(n%10)/2;
    if (n>9)
      doit(n/10,d+1);

    r[d]+=5;
    if (n>9)
      doit(n/10-1,d+1);
  }
}
int len(int n)
{
  int t=0;
  while (n)
  {
    t++;
    n/=10;
  }
  return t;
}
int main(int argc, char* argv[])
{
  int N,I,n,i,j,t;
  cin>>N;
  for (I=0;I<N;I++)
  {
    if (I) cout<<endl;
    cin>>n;
    s=0;  m=0;
    doit(n,0);

    for (i=0;i<s-1;i++)
      for (j=i+1;j<s;j++)
        if (x[i]<x[j])
        {
          t=x[i];x[i]=x[j];x[j]=t;
          t=y[i];y[i]=y[j];y[j]=t;
        }
    t=0;
    x[s]=-1;
    for (i=0;i<s;i++)
      if (y[i]==x[i] || x[i]==x[i+1])
        t++;
    cout<<s-t<<endl;
    for (i=0;i<s;i++)
      if (y[i]!=x[i] && x[i]!=x[i+1])
        cout<<y[i]<<" + "<<setw(len(y[i])-1)
            <<setfill('0')<<x[i]<<" = "<<n<<endl;
  }
  return 0;
}
//---------------------------------------------------------------------------
