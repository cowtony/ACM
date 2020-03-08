//315727 2003-10-17 19:24:54 Wrong Answer 1648 C++ 00:00.01 440K just for play 
//315745 2003-10-17 19:50:38 Wrong Answer 1648 C++ 00:00.01 440K just for play 
//315755 2003-10-17 20:00:01 Accepted 1648 C++ 00:00.34 444K just for play 
#include<stdio.h>

struct POINT{double x,y;};
struct LINE{POINT from,to;};

const double EPS=1.0e-8;
LINE cir[2001];

double crossmul(POINT mid,POINT one,POINT two)
{
	return ((one.x-mid.x)*(two.y-mid.y)-(one.y-mid.y)*(two.x-mid.x));
}
double max(double fir,double sec)
{
	return ((fir>sec+EPS)?fir:sec);
}
double min(double fir,double sec)
{
	return ((fir>sec+EPS)?sec:fir);
}
bool inter(LINE one,LINE two)
{
	if(max(one.from.x,one.to.x)>min(two.from.x,two.to.x)+EPS&&
		max(one.from.y,one.to.y)>min(two.from.y,two.to.y)+EPS&&
		min(one.from.x,one.to.x)+EPS<max(two.from.x,two.to.x)&&
		min(one.from.y,one.to.y)+EPS<max(two.from.y,two.to.y)&&	
		crossmul(one.from,one.to,two.from)*crossmul(one.from,two.to,one.to)>EPS&&
		crossmul(two.from,two.to,one.to)*crossmul(two.from,one.from,two.to)>EPS)
		return true;
	return false;
}

int main()
{
//	freopen("1648.in","r",stdin);

	int n;
	while(scanf("%d",&n)!=EOF)
	{
		int i,j;
		for(i=0;i<n;i++)	
			scanf("%lf %lf %lf %lf",&cir[i].from.x,&cir[i].from.y,&cir[i].to.x,&cir[i].to.y);
		bool interset=false;
		for(i=0;i<n;i++)
		{
			for(j=i+1;j<n;j++)			
				if(inter(cir[i],cir[j])){interset=true;break;}
			if(interset)	break;
		}
		if(interset)
			printf("burned!\n");
		else	printf("ok!\n");
	}
	return 0;
}

			

		