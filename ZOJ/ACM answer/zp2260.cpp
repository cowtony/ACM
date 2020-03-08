//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

//---------------------------------------------------------------------------

#pragma argsused
#include <iostream.h>
#include <math.h>
int main(int argc, char* argv[])
{
  int a,b,m,x[4],y[4],r,i;

  cin>>a>>b>>m;
  while (a+b+m)
  {
    x[0]=(m-1)/a+1;
    while (1)
    {
      if ((a*x[0]-m)%b==0)
        break;
      x[0]++;
    }
    y[0]=(a*x[0]-m)/b;

    y[1]=(m-1)/b+1;
    while (1)
    {
      if ((b*y[1]-m)%a==0)
        break;
      y[1]++;
    }
    x[1]=(b*y[1]-m)/a;

    x[2]=0;
    while (1)
    {
      if ((a*x[2]-m)%b==0)
        break;
      x[2]++;
    }
    y[2]=abs((a*x[2]-m)/b);

    y[3]=0;
    while (1)
    {
      if ((b*y[3]-m)%a==0)
        break;
      y[3]++;
    }
    x[3]=abs((b*y[3]-m)/a);

    r=0;
    for (i=1;i<4;i++)
      if (x[i]+y[i]<x[r]+y[r])
        r=i;
      else
        if (x[i]+y[i]==x[r]+y[r])
          if (x[i]*a+y[i]*b<x[r]*a+y[r]*b)
            r=i;

    cout<<x[r]<<' '<<y[r];

    cout<<endl;
    cin>>a>>b>>m;
  }
  return 0;
}
//---------------------------------------------------------------------------
