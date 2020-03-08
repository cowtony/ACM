//---------------------------------------------------------------------------

#pragma hdrstop

//---------------------------------------------------------------------------

#pragma argsused
#include <iostream.h>
#include <iomanip.h>
int main(int argc, char* argv[])
{
  long int p[20010];
  int a,b,c,i,j,k,t,h,r;
  while (cin>>p[1]>>p[2]>>p[3]>>k)
  {
    for (i=4;i<20010;i++)
      p[i]=0;
    for (i=1;i<3;i++)
      for (j=i+1;j<4;j++)
        if (p[i]>p[j])
        { t=p[i];p[i]=p[j];p[j]=t;}
    a=p[1];
    b=p[2];
    c=p[3];
    h=0; t=3;
    while (h<k)
    {
      h++;
      if (h>t)
        break;
      r=t;
      while (p[r]>p[h]*a) r--;
      if (p[r]<p[h]*a)
      {
        for (i=t;i>r;i--)
          p[i+1]=p[i];
        p[r+1]=p[h]*a;
        t++;
      }
      r=t;
      while (p[r]>p[h]*b) r--;
      if (p[r]<p[h]*b)
      {
        for (i=t;i>r;i--)
          p[i+1]=p[i];
        p[r+1]=p[h]*b;
        t++;
      }
      r=t;
      while (p[r]>p[h]*c) r--;
      if (p[r]<p[h]*c)
      {
        for (i=t;i>r;i--)
          p[i+1]=p[i];
        p[r+1]=p[h]*c;
        t++;
      }
    }
    cout<<p[k]<<endl;
  }
  return 0;
}
//---------------------------------------------------------------------------
