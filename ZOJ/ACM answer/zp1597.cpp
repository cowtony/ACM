//---------------------------------------------------------------------------

#pragma hdrstop

//---------------------------------------------------------------------------

#pragma argsused
#include <iostream.h>
#include <iomanip.h>
#include <math.h>
double area(double a,double b,double c)
{
  double l=(a+b+c)/2;
  return sqrt(l*(l-a)*(l-b)*(l-c));
}
double thita(double a,double b,double c)
{
  return acos((a*a+b*b-c*c)/(2*a*b));
}
int main(int argc, char* argv[])
{
  const double pi=3.1415927;
  double x1,y1,r1,x2,y2,r2,d,s;
  cout<<setiosflags(ios::fixed)<<setprecision(3);
  while(cin>>x1>>y1>>r1>>x2>>y2>>r2)
  {
    d=sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
    if (r1<r2)
    {
      s=r1;r1=r2;r2=s;
      s=x1;x1=x2;x2=s;
      s=y1;y1=y2;y2=s;
    }
    if (d>=r1+r2)
      s=0;
    else if (d<=r1-r2)
      s=r2*r2*pi;
    else
    {
      s=2*area(r1,r2,d);
      s+=(pi-thita(r1,d,r2))*r1*r1;
      s+=(pi-thita(r2,d,r1))*r2*r2;
      s-=r1*r1*pi+r2*r2*pi;
      s=-s;
    }
    cout<<s<<endl;
  }
  return 0;
}
//---------------------------------------------------------------------------
