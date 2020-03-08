#include <stdio.h>
#include <string.h>
#include <math.h>

struct point 
{
	double x , y;
};

inline double dist(const point& a , const point& b)
{
	return sqrt((a.x-b.x)*(a.x-b.x) + (a.y-b.y)*(a.y-b.y));
}

int main()
{
//	freopen("in.txt" , "r" , stdin);

	point p1 , p2;	
	char buf[100];
	double tot;
	int hour ,min;

	while(1)
	{
		if(scanf("%lf%lf" , &p1.x , &p1.y) < 0) break;
		gets(buf);
		tot = 0;

		while(1)
		{
			gets(buf);
			if(strcmp(buf , "java") == 0) break;
			sscanf(buf , "%lf%lf%lf%lf" , &p1.x , &p1.y , &p2.x , &p2.y);
			tot += dist(p1 , p2);
		}

		tot = tot / 10000;
		hour = int(tot);
		min = int((tot - hour)*60 + 0.5);
		if(min == 60) hour++ , min = 0;
		printf("%d:" , hour);
		if(min < 10) putchar('0');
		printf("%d\n" , min);		
	}
	
	return 0;
}
