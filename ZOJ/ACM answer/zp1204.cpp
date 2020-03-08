//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

//---------------------------------------------------------------------------

#pragma argsused
#include <iostream.h>
int S,f,sum,n,y,a[50],p[50],P[13000][33],Sum[13000];
int search(int d)
{
  int h,t,k;
  h=1;t=n;
  while (t>=h)
  {
    k=(t+h)/2;
    if (d>a[k])
      h=k+1;
    else
      if (d<a[k])
        t=k-1;
      else
        return 1;
  }
  return 0;
}
void store(int d)
{
  f++;
  int s,i,w[50];
  s=0;
  for (i=y;i<=d;i++)
    if (p[i])
      w[++s]=i;
  for (i=1;i<=s;i++)
    P[f][i]=w[i];
  P[f][0]=s;
  if (s>S) S=s;
  Sum[f]=sum;
}
void print()
{
  if (!f)
    cout<<"Can't find any equations."<<endl;
  else
  for (int i=1;i<=S;i++)
    for (int j=1;j<=f;j++)
      if (P[j][0]==i)
      {
        cout<<a[P[j][1]];
        for (int k=2;k<=P[j][0];k++)
          cout<<'+'<<a[P[j][k]];
        cout<<'='<<Sum[j]<<endl;
      }
}
void solv(int d)
{
  if (d<n)
  for (p[d]=1;p[d]>=0;p[d]--)
    if (p[d])
    {
      sum+=p[d]*a[d];
      if (sum<=a[n])
      {
        if (search(sum))
          store(d);
        if (sum<a[n])
          solv(d+1);
      }
      sum-=p[d]*a[d];
    }
    else
      solv(d+1);
}

int main(int argc, char* argv[])
{
  int i,j,t,N,I;
  cin>>N;
  for (I=0;I<N;I++)
  {
    cin>>n;
    for (i=1;i<=n;i++)
      cin>>a[i];

    for (i=1;i<n;i++)
      for (j=i+1;j<=n;j++)
        if (a[i]>a[j])
        { t=a[i];a[i]=a[j];a[j]=t; }
    f=0;

    for (i=1;i<n-1;i++)
    {
      sum=a[i];
      p[i]=1;
      y=i;
      solv(i+1);
    }

    print();

    cout<<endl;
  }
  return 0;
}
//---------------------------------------------------------------------------
 