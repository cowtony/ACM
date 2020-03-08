//---------------------------------------------------------------------------

#pragma hdrstop

//---------------------------------------------------------------------------

#pragma argsused
#include <iostream.h>
#include <iomanip.h>
#include <math.h>
double db(double n)
{
  if (fabs(n)< 1e-5)
    return 0;
  return n;
}
int main(int argc, char* argv[])
{
  int N,I;
  double x1,y1,x2,y2,x3,y3,x,y,k1,k2;
  cin>>N;
  for (I=0;I<N;I++)
  {
    cin>>x1>>y1>>x2>>y2>>x3>>y3;
    if (db(y1-y3)==0)
    { k1=y3;y3=y2;y2=k1;
      k1=x3;x3=x2;x2=k1; }

    if (db(y2==y3))
    { k1=y3;y3=y1;y1=k1;
      k1=x3;x3=x1;x1=k1; }

    k1=db(-(x3-x2)/(y3-y2));
    k2=db(-(x3-x1)/(y3-y1));

    x=db((-y1+y2+k1*x1-k2*x2)/(k1-k2));
    y=db(k1*(x-x1)+y1);

    cout<<setiosflags(ios::fixed)<<setprecision(4)
        <<x<<' '<<y<<endl;

  }
  return 0;
}
//---------------------------------------------------------------------------
 