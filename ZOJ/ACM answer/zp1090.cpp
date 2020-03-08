//---------------------------------------------------------------------------

#pragma hdrstop

//---------------------------------------------------------------------------

#pragma argsused
#include <iostream.h>
#include <iomanip.h>
#include <math.h>
int main(int argc, char* argv[])
{
  const double pi=3.141592653589793;
  double c,d,k1,k2,x1,y1,x2,y2,x3,y3,x,y;
  cout<<setiosflags(ios::fixed)<<setprecision(2);
  while (cin>>x1>>y1>>x2>>y2>>x3>>y3)
  {
    if (y1-y3==0)
    { k1=y3;y3=y2;y2=k1;
      k1=x3;x3=x2;x2=k1; }

    if (y2-y3==0)
    { k1=y3;y3=y1;y1=k1;
      k1=x3;x3=x1;x1=k1; }

    k1=-(x3-x2)/(y3-y2);
    k2=-(x3-x1)/(y3-y1);

    x=(-y2+y1+k1*(x2+x3)-k2*(x1+x3))/(2*(k1-k2));
    y=k1*(x-(x2+x3)/2)+(y2+y3)/2;

    d=sqrt((x1-x)*(x1-x)+(y1-y)*(y1-y));
    c=d*pi*2;
    cout<<c<<endl;
  }
  return 0;
}
//---------------------------------------------------------------------------
 