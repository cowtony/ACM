//126684 2003-04-17 23:48:07 Wrong Answer 1574 C++ 00:00.97 1560K just for play 
//126848 2003-04-18 10:32:22 Accepted 1574 C++ 00:00.46 1560K just for play 
#include<stdio.h>
#include<math.h>


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
	//freopen("in.txt","r",stdin);
//	freopen("out.txt","w",stdout);
	node_type node[max_n];
	long top=0;
	long i;	long fir,sec;
	long u,v;
	for(i=3;;i++)
	{	
		if(i%2==0)
		{
			long tt=i/2;			
			for(v=floor(sqrt(tt));v>=1;v--)
			{
				if(tt%v!=0)	continue;
				u=tt/v;							
				if((u-v)%2==0)	continue;
				if(gcd(u,v)!=1)	continue;				
				node[top].x=i;
				node[top].y=u*u-v*v;
				if(node[top].y<=node[top].x)	continue;
				node[top].z=u*u+v*v;				
				top++;
				if(top==end_n)	goto while_out;
			}
		}
		else
		{			
			for(fir=floor(sqrt(i));fir>=1;fir--)
			{
				if(i%fir!=0)	continue;
				sec=i/fir;
                if(fir>=sec)   continue;				
				u=(fir+sec)/2;
                v=(sec-fir)/2;
				if((u-v)%2==0)	continue;
				if(gcd(u,v)!=1)	continue;											
				node[top].x=i;
                node[top].y=2*u*v;				
				if(node[top].y<=node[top].x)	continue;				
                node[top].z=u*u+v*v;		
				top++;
				if(top==end_n)	goto while_out;
			}
		}
//		if(top==end_n)	break;
	}
while_out:	
/*
	for(i=0;i<max_n-1;i++)
		printf("%ld  %ld  %ld\n",node[i].x,node[i].y,node[i].z);
*/
	long n;
	while(scanf("%ld",&n)!=EOF)
		printf("%ld %ld %ld\n",node[n-1].x,node[n-1].y,node[n-1].z);
	return 0;
}



