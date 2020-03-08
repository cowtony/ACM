//337266 2003-11-05 00:12:34 Accepted 1721 C++ 00:00.00 388K just for play 
#include<stdio.h>
#include<math.h>

const double EPS=1.0e-8;
double x[100],y[100];
double dis[100];
struct DOOR
{
	double tx;
	double e[4];
};


int cnt;
DOOR	dw[20];

double distance(int fr,int to)
{
	return sqrt((x[fr]-x[to])*(x[fr]-x[to])+(y[fr]-y[to])*(y[fr]-y[to]));
}

bool can_line(int fr,int to,int wt)
{
	int i;
	int beg;
	if(fr==0)	beg=0;
	else	beg=(fr-1)/4+1;
	for(i=beg;i<wt;i++)
	{
		double dy=y[fr]+(y[to]-y[fr])*(dw[i].tx-x[fr])/(x[to]-x[fr]);
		if(dy+EPS<dw[i].e[0]||(dw[i].e[1]+EPS<dy&&dy+EPS<dw[i].e[2])||
			dw[i].e[3]+EPS<dy)
			return false;
	}
	return true;
}




int main()
{
	int n;
	while(scanf("%d",&n)!=EOF)
	{
		if(n==-1)	break;
		int i,j,t;
		for(i=0;i<n;i++)
			scanf("%lf %lf %lf %lf %lf",&dw[i].tx,&dw[i].e[0],&dw[i].e[1],&dw[i].e[2],&dw[i].e[3]);
		cnt=1;
		x[0]=0;y[0]=5.0;dis[0]=0;
	
		for(i=0;i<n;i++)
		{
			for(j=0;j<4;j++)
			{
				x[cnt]=dw[i].tx;y[cnt++]=dw[i].e[j];
			}
			for(j=0;j<4;j++)
			{
				double min=10000;
				for(t=0;t<cnt-4;t++)
					if(can_line(t,cnt-1-j,i))
					{
						double tt=distance(t,cnt-1-j);
						if(tt+dis[t]+EPS<min)
							min=tt+dis[t];
					}
				dis[cnt-1-j]=min;
			}	
		}
		x[cnt]=10;y[cnt]=5;
		double min=10000;		
		for(t=0;t<cnt;t++)
			if(can_line(t,cnt,n))
			{
					double tt=distance(t,cnt);
					if(tt+dis[t]+EPS<min)
						min=tt+dis[t];
			}
		printf("%.2lf\n",min);
	}
	return 0;
}
			




