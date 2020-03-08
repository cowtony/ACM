#include<stdio.h>
#include<math.h>

struct node_type{long x,y, z;};

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


	//freopen("in.txt","r",stdin);
//	freopen("out.txt","w",stdout);
	node_type node[100001];
	long top=0;
	long i;		
	for(i=3;;i++)
	{
		
	
		if(i%2==0)
		{
			long tt=i/2;
			long u,v;
			for(v=1;v<=sqrt(tt);v++)
			{
				if(tt%v!=0)	continue;
				u=tt/v;
				if(u<=v)	continue;
				//if(u<=v)	continue;
				if((u-v)%2==0)	continue;
				if(gcd(u,v)!=1)	continue;
				long tx,ty,tz;				
				tx=i;
				ty=u*u-v*v;
				if(ty<=tx)	continue;
				tz=u*u+v*v;
				
				node[top].x=tx;node[top].y=ty;node[top].z=tz;
		//		printf("%ld  %ld  %ld\n",tx,ty,tz);
				top++;
				if(top==100000)	break;
			}
		}
		else
		{
			long fir,sec;
			for(fir=1;fir<=sqrt(i);fir++)
			{
				if(i%fir!=0)	continue;
				sec=i/fir;
				if(sec<=fir)	continue;
				long u,v;
				u=(fir+sec)/2;v=(sec-fir)/2;
				if((u-v)%2==0)	continue;
				if(gcd(u,v)!=1)	continue;
				long tx,ty,tz;
				
				tx=i;
				ty=2*u*v;
				if(ty<=tx)	continue;
				tz=u*u+v*v;
				//if(ty<=tx||ty>=tz)	continue;
				node[top].x=tx;node[top].y=ty;node[top].z=tz;
		//		printf("%ld  %ld  %ld\n",tx,ty,tz);
				top++;
				if(top==100000)	break;
			}
		}
		if(top==100000)	break;
	}
	for(i=0;i<top;i++)
		printf("%ld  %ld  %ld\n",node[i].x,node[i].y,node[i].z);
	return 0;
}


