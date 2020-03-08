//166231 2003-06-06 13:08:41 Wrong Answer 1081 C++ 00:00.00 380K just for play 
//166269 2003-06-06 14:00:03 Accepted 1081 C++ 00:00.00 380K just for play 
#include<stdio.h>
#include<math.h>

double precison=1.0e-8;
struct point{int x,y;};

int on_line(point& fir,point& sec,point& test)
{
	if(test.x==fir.x&&test.y==fir.y)	return 1;
	if(test.x==sec.x&&test.y==sec.y)	return 1;
	if(((test.x<=fir.x&&test.x>=sec.x)||(test.x>=fir.x&&test.x<=sec.x))
		&&((test.y<=fir.y&&test.y>=sec.y)||(test.y>=fir.y&&test.y<=sec.y))
		&&((fir.y-sec.y)*(fir.x-test.x)==(fir.y-test.y)*(fir.x-sec.x))
	)
			return 1;
	return 0;
}


int left_line(point& fir,point& sec,point& test)
{
	if((fir.y<test.y&&sec.y>test.y)||(fir.y>test.y&&sec.y<test.y))
	{
		double tx=(double)fir.x-(fir.x-sec.x)*(fir.y-test.y)*1.0/(fir.y-sec.y);
		if(test.x+precison<tx)	return 1;
	}
	return 0;
}

int main()
{
//	freopen("1081.in","r",stdin);
	int n;int count=0;
	while(scanf("%d",&n)!=EOF)
	{
		if(n==0)	break;
		count++;		
		int p,i,j;
		scanf("%d",&p);
		point input[101],test;
		for(i=0;i<n;i++)	scanf("%d %d",&input[i].x,&input[i].y);
		if(count>1)	printf("\n");
		printf("Problem %d:\n",count);
		for(j=0;j<p;j++)
		{
			scanf("%d %d",&test.x,&test.y);
			
			for(i=0;i<n;i++)			
				if(on_line(input[i],input[(i+1)%n],test)) 	break;
			if(i<n)
			{
					printf("Within\n");
					continue;
			}
			int total=0;
			for(i=0;i<n;i++)
				if(left_line(input[i],input[(i+1)%n],test))	total++;
			for(i=0;i<n;i++)
			{
				if((input[i].y!=input[(i+1)%n].y)&&(input[(i+1)%n].y==test.y&&input[(i+1)%n].x>test.x))
				{
					int t=(i+2);
					while(input[t%n].y==test.y)	t++;
					if((input[t%n].y-test.y)*(input[i].y-test.y)<0)	total++;
				}
			}
		
			if(total%2)			
				printf("Within\n");
			else	printf("Outside\n");
		}
	}
	return 0;
}
		




