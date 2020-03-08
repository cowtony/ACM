#include<stdio.h>
#include<math.h>

struct LINE
{
	double x0,x1,y0,y1;
};

int n;
int cnt;
const double EPS=1.0e-8;
const double END_EPS=1.0e-6;
LINE inp[101];
bool search_x(double y0,double from,double to,int tflag);

void cal_x(double x0,double y0,double& from,double& to)
{
	int i;
	from=-100;to=100;
	for(i=0;i<n;i++){
		double t1=-110,t2=110;
		if(fabs(inp[i].y1-inp[i].y0)<EPS){
			if(fabs(inp[i].y0-y0)<EPS){						
				if(inp[i].x0+EPS<inp[i].x1){
					if(inp[i].x0+EPS<x0&&x0+EPS<inp[i].x1){
						t1=100;t2=-100;
					}
					else	if(x0+EPS<inp[i].x0)	t2=inp[i].x0 ;
					else	t1=inp[i].x1;
				}else{
					if(inp[i].x1+EPS<x0&&x0+EPS<inp[i].x0){
						t1=100;t2=-100;
					}
					if(x0+EPS<inp[i].x1)	t2=inp[i].x1;
					else	t1=inp[i].x0 ;
				}
			}
		}else{
			double tx=(y0-inp[i].y0)*(inp[i].x1-inp[i].x0)/(inp[i].y1-inp[i].y0)+inp[i].x0;
			if(x0+EPS<tx){
				if(tx<t2)	t2=tx;
			}else{
				if(tx>t1)	t1=tx;
			}
		}
		if(t1>from)	from=t1;
		if(t2<to)	to=t2;
	}
	
}

void cal_y(double x0,double y0,double& from,double& to)
{
	int i;
	from=-100;to=100;
	for(i=0;i<n;i++){
		double t1=-110,t2=110;
		if(fabs(inp[i].x1-inp[i].x0)<EPS){
			if(fabs(inp[i].x0-x0)<EPS){
				if(inp[i].y0+EPS<inp[i].y1){
					if(inp[i].y0+EPS<y0&&y0+EPS<inp[i].y1){
						t1=100;t2=-100;
					}
					else	if(y0+EPS<inp[i].y0)	t2=inp[i].y0 ;
					else	t1=inp[i].y1;
				}else{
					if(inp[i].y1+EPS<y0&&y0+EPS<inp[i].y0){
						t1=100;t2=-100;
					}
					if(y0+EPS<inp[i].y1)	t2=inp[i].y1;
					else	t1=inp[i].y0 ;
				}
			}
		}else{
			double ty=(x0-inp[i].x0)*(inp[i].y1-inp[i].y0)/(inp[i].x1-inp[i].x0)+inp[i].y0;
			if(y0+EPS<ty){
				if(ty<t2)	t2=ty;
			}else{
				if(ty>t1)	t1=ty;
			}
		}
		if(t1>from)	from=t1;
		if(t2<to)	to=t2;
	}
	
}

bool search_y(double x0,double from,double to,int flag=0)
{

//	printf("y==== %lf  %lf %lf\n",x0,from,to);
	if(to-from<END_EPS)	return false;
	double tfrom,tto;
	
	if(flag==0){
		cal_x(x0,(from+to)/2,tfrom,tto);
		if(tfrom<-80||tto>80)	return true;
		int tflag=0;
		if(fabs((tfrom+tto)/2-x0)<EPS)	tflag=1;
		if(search_x((from+to)/2,tfrom,tto,tflag))	return true;
	}
	if(search_y(x0,from,(from+to)/2),0)	return true;
	if(search_y(x0,(from+to)/2,to),0)	return true;
	return false;
}

bool search_x(double y0,double from,double to,int flag=0)
{

	printf("x==== %lf  %lf %lf\n",y0,from,to);
	if(to-from<END_EPS)	return false;
	double tfrom, tto;
	if(flag==0){
		cal_y((from+to)/2,y0,tfrom,tto);
		if(tfrom<-80||tto>80)	return true;
		int tflag;
		if(fabs((tfrom+tto)/2-y0)<EPS)	tflag=1;
		if(search_y((from+to)/2,tfrom,tto))	return true;
	}
	if(search_x(y0,from,(from+to)/2,0))	return true;
	if(search_x(y0,(from+to)/2,to,0))	return true;
	return false;
}



int main()
{
	freopen("1744.in","r",stdin);
	while(scanf("%d",&n)!=EOF){
		if(n==0)	break;
		int i;cnt=0;
		for(i=0;i<n;i++)	
			scanf("%lf %lf %lf %lf",&inp[i].x0,&inp[i].y0,&inp[i].x1,&inp[i].y1);
		double from,to;
		cal_x(0,0,from,to);
		if(from<-80||to>80){
			printf("yes\n");
			continue;
		}else{
			if(search_x(0,from,to))		printf("yes\n");
			else	printf("no\n");
		}
	}
	return 0;
}

