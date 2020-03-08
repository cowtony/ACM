#include <iostream.h>

int a[110];

int cal(int k)
{
  int r,x=a[k];
  r=k+1;
  while (a[r]==0) r++;
  x*=a[r];
  r=k-1;
  while (a[r]==0) r--;
  x*=a[r];
  return x;
}
int main(int argc, char* argv[])
{
  int i,n,m,s,j,k,x,y;
  while (cin>>n)
  {
    for (i=0;i<n;i++)
      cin>>a[i];
    n--;
    s=0;
    for (i=1;i<n;i++)
    {
      m=0;
      for (j=1;j<n;j++)
        if (a[j]>m)
        {
          m=a[j]; k=j;
          x=cal(k);
        }
        else
          if (a[j]==m)
          {
            y=cal(j);
            if (y<x) { k=j;  x=y; }
          }

      a[k]=0;
      s+=x;
    }
    cout<<s<<endl;
  }
  return 0;
}
//---------------------------------------------------------------------------
 