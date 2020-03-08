#include <stdio.h>
#include <math.h>
const double pi=3.1415926535897;

int main(int argc, char* argv[])
{
  double a,b,c,l,r,s,R,S,L,p;
  int cs=0;
  while (scanf("%lf%lf%lf%lf",&a,&b,&c,&l)
      && a+b+c+l!=0)
  {
    L=a+b+c;
    p=L/2;
    S=sqrt(p*(p-a)*(p-b)*(p-c));
    R=2*S/L;
    printf("Case %d: ",++cs);
    if (R*2*pi>=l)
      printf("%.2lf\n",l*l/(4*pi));
    else
    {
      r=(l-L)*R/(2*pi*R-L);
      s=S*(R-r)*(R-r)/(R*R)+r*L*(R-r)/R+r*pi*r;
      printf("%.2lf\n",s);
    }
  }
  return 0;
}
//---------------------------------------------------------------------------
 