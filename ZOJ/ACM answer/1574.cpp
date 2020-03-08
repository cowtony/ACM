//126684 2003-04-17 23:48:07 Wrong Answer 1574 C++ 00:00.97 1560K just for play 
#include<stdio.h>
#include<math.h>
#include<time.h>

struct node_type{long x,y, z;};
const long max_n=100001;
const long end_n=max_n-1;

long gcd(long fir,long sec)
{

	if(fir<sec)	{long temp=fir;fir=sec;sec=fir;}
	while(1)
	{
		long tt=fir%sec;
		if(tt==0)	return sec;
		fir=sec;sec=tt;
	}
}

int main()
{
	node_type node[max_n];
	long top=0;
	long i;	long fir,sec;
	long u,v;long tx,ty,tz;				
	time cal_time;
	cal_time.reset();
	for(i=3;;i++)
	{	
		if(i%2==0)
		{
			long tt=i/2;
			
			for(v=1;v<sqrt(tt);v++)
			{
				if(tt%v!=0)	continue;
				u=tt/v;							
				if((u-v)%2==0)	continue;
				if(gcd(u,v)!=1)	continue;				
				tx=i;
				ty=u*u-v*v;
				if(ty<=tx)	continue;
				tz=u*u+v*v;
				
				node[top].x=tx;node[top].y=ty;node[top].z=tz;		
				top++;
				if(top==end_n)	break;
			}
		}
		else
		{
			
			for(fir=1;fir<sqrt(i);fir++)
			{
				if(i%fir!=0)	continue;
				sec=i/fir;				
				u=(fir+sec)/2;v=(sec-fir)/2;
				if((u-v)%2==0)	continue;
				if(gcd(u,v)!=1)	continue;							
				tx=i;
				ty=2*u*v;
				if(ty<=tx)	continue;
				tz=u*u+v*v;		
				node[top].x=tx;node[top].y=ty;node[top].z=tz;		
				top++;
				if(top==end_n)	break;
			}
		}
		if(top==end_n)	break;
	}
	printf("%d\n",cal_time.clock());
/*
	for(i=0;i<max_n-1;i++)
		printf("%ld  %ld  %ld\n",node[i].x,node[i].y,node[i].z);
*/
	long n;
	while(scanf("%ld",&n)!=EOF)
		printf("%ld %ld %ld\n",node[n-1].x,node[n-1].y,node[n-1].z);
	return 0;
}


