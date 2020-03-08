
//126454 2003-04-17 22:00:51 Accepted 1575 C++ 00:00.15 384K just for play 
#include<stdio.h>

struct point{double x;double y;};

double cos60=0.5;
double sin60=0.86602540378443;


void print(point& tt)
{
	printf("%.2lf %.2lf\n",tt.x,tt.y);
}

void draw(point& p1,point& p2,int n)
{

	if(n<=0)
	{	
		print(p1);
		return;
	}
	point p3,p4,p5;
	double a,b;
	p3.x=p1.x+(p2.x-p1.x)/3;
	p3.y=p1.y+(p2.y-p1.y)/3;
	p5.x=p1.x+2*(p2.x-p1.x)/3;
	p5.y=p1.y+2*(p2.y-p1.y)/3;
	a=p5.x-p3.x;
	b=p5.y-p3.y;
	p4.x=p3.x+a*cos60-b*sin60;
	p4.y=p3.y+a*sin60+b*cos60;
	
	draw(p1,p3,n-1);
	draw(p3,p4,n-1);
	draw(p4,p5,n-1);
	draw(p5,p2,n-1);
}



int main()
{
//	freopen("in.txt","r",stdin);
	point p1,p2;int n;
	while(scanf("%d",&n)!=EOF)
	{
		scanf("%lf%lf%lf%lf",&p1.x,&p1.y,&p2.x,&p2.y);
		draw(p1,p2,n);
		print(p2);
		printf("\n");
	}
	return 0;
}
		
