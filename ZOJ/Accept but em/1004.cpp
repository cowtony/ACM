//761 2003-06-07 14:17:10 Accepted 1004 C++ 00:00:14 380K just for play 
#include<stdio.h>

int main()
{
	int n,m;
	while(scanf("%d %d",&n,&m)!=EOF)
	{
		double res=1;
		int i,j;
		double t=1.0;
		for(i=1;i<=n-m;i++)
		{
		
			double  f=(i%2)?-1:1;
			double temp=1;
			for(j=1;j<=i;j++)
				temp*=1.0/j;
			t+=f*temp;	
		}
		for(i=1;i<=m;i++)
			t/=(double)i;
		printf("%.8lf\n",t);
	}
	return 0;
}
