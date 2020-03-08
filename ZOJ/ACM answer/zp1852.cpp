#include <stdio.h>
#include <math.h>
#define pi 3.1415926536

int main(int argc, char* argv[])
{
  double a,b,s,m,n,t;
  while (scanf("%lf%lf%lf%lf%lf",&a,&b,&s,&m,&n)
          && a+b+s+m+n>0)
  {
    t=atan2(b*n,a*m);
    printf("%.2lf ",t/pi*180);
    t=sqrt(b*b*n*n+a*a*m*m);
    printf("%.2lf\n",t/s);
  }
  return 0;
}
//---------------------------------------------------------------------------
