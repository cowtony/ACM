#include <stdio.h>
#include <math.h>
#define  pi 3.141592654
int main()
{
	double x1,y1,r1,x2,y2,r2;
	double x3,r;
	double s1,s2;
	double dis;
	while(1)
	{
		if(scanf("%lf%lf%lf%lf%lf%lf",&x1,&y1,&r1,&x2,&y2,&r2)==EOF) break;
		dis=sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
		if(r1+r2-dis<10e-6) {printf("%.3f\n",0.000);continue;}
		if(dis-fabs(r1-r2)<10e-6)
		{
			r=r1;
			if(r2<r1) r=r2;
			printf("%.3f\n",pi*r*r);
		}
		else
		{
			x2=x1+dis;
			y2=y1;
			x3=(r1*r1-r2*r2)/(x2-x1)+(x1+x2);
			x3=x3/2.0;
			s1=(x3-x2)/2.0*sqrt(r2*r2-(x3-x2)*(x3-x2))+(r2*r2)/2.0*(asin((2.0*x3-2.0*x2)/sqrt(4.0*x2*x2+4.0*(r2*r2-x2*x2)))-asin((2.0*(x2-r2)-2.0*x2)/sqrt(4.0*x2*x2+4.0*(r2*r2-x2*x2))));
			s1*=2.0;
			s2=r1*r1/2.0*(asin((2.0*(x1+r1)-2.0*x1)/sqrt(4.0*x1*x1+4.0*(r1*r1-x1*x1)))-asin((2.0*x3-2.0*x1)/sqrt(4.0*x1*x1+4.0*(r1*r1-x1*x1))))-(x3-x1)/2.0*sqrt(r1*r1-(x3-x1)*(x3-x1));
			s2*=2.0;
			printf("%.3f\n",s1+s2);
		}
	}
	return 0;
}





