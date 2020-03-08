//137692 2003-05-01 18:09:30 Accepted 1581 C++ 00:00.72 376K just for play 
#include<stdio.h>

int main()
{
//	freopen("in.txt","r",stdin);
//	freopen("out.txt","w",stdout);

	double interval=10e-13;
	double q, m, e, b, v, t;
	int count=0;
	while(scanf("%lf%lf%lf%lf%lf%lf",&q,&m,&e,&b,&v,&t)!=EOF)
	{
		
		count++;
		double x,y;
		x=0;y=0;	
		double v_hor;double v_ver;
		double v_hor_org=v,v_ver_org=0;
		double time=0;
		for(;time<t;time+=interval)
		{
			v_hor=v_hor_org;v_ver=v_ver_org;
			x+=v_hor*interval;
			y-=v_ver*interval;
			v_hor_org=v_hor+q*v_ver*b*interval/m;
			v_ver_org=v_ver+(q*e-q*v_hor*b)*interval/m;			
		}
		printf("Case #%d:\n",count);

		printf("%.3e %.3e\n\n",x, y);
	}
	return 0;
}
