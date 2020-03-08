//---------------------------------------------------------------------------

#pragma hdrstop

//---------------------------------------------------------------------------

#pragma argsused
//#define cin fin
//#include <fstream.h>
#include <iostream.h>
#include <math.h>

const double pi=3.1415927;
int ax[1010],ay[1010],p[1010];

int accu(double s)
{
  int k;
  k=int(s);
  if (s-k>=2*(k+1-s)) k++;
  return k;
}
void mit(int h,int m,int r)
{
  if ((ay[m]-ay[h])*(ax[r]-ax[h])-
     (ax[m]-ax[h])*(ay[r]-ay[h])<=0)
    p[m]=0;
}
double lng(int h,int r)
{
  return sqrt((ax[h]-ax[r])*(ax[h]-ax[r])+(ay[h]-ay[r])*(ay[h]-ay[r]));
}
int main(int argc, char* argv[])
{
  //ifstream fin("in1465.txt");
  int N,I,n,l,i,j,h,r;
  double sum;
  cin>>N;
  for (I=0;I<N;I++)
  {
    if (I) cout<<endl;
    cin>>n>>l;
    for (i=1;i<=n;i++)
    { cin>>ax[i]>>ay[i]; p[i]=1; }
    ax[0]=ax[n];      ay[0]=ay[n];      p[0]=1;
    ax[n+1]=ax[1];    ay[n+1]=ay[1];    p[n+1]=1;

    for (i=1;i<=n;i++)
      if (p[i])
      {
        h=i-1;
        while (!p[h])
        { h--; if (h==0) h=n; }
        r=i+1;
        while (!p[r])
        { r--; if (r==n+1) r=1; }
        mit (h,i,r);
      }
    sum=l*pi*2;
    h=n;
    while (!p[h]) h--;
    r=1;
    while (r<=n)
    {
      while (!p[r]) r++;
      sum+=lng(h,r);
      h=r;
      r++;
    }
    cout<<accu(sum)<<endl;
  }
  return 0;
}
//---------------------------------------------------------------------------
