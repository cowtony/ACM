#include <stdio.h>
int main()
{
	int a[201][201];
	int i,j,k,l=1;
	int x1,y1,x2,y2;
	int minx,miny,maxx,maxy,color,t,sum;
	int n,c;
	while(1)
	{
		sum=0;
		scanf("%d%d",&n,&c);
		if(n==0) break;
		for(i=0;i<200;i++)
		{
			for(j=0;j<200;j++)
				a[i][j]=0;
		}
		for(k=0;k<n;k++)
		{
			scanf("%d%d%d%d%d",&color,&x1,&y1,&x2,&y2);
			minx=x1=x1+100;miny=y1=y1+100;
			maxx=x2=x2+100;maxy=y2=y2+100;
			if(x1>x2) {t=minx;minx=maxx;maxx=t;}
			if(y1>y2) {t=miny;miny=maxy;maxy=t;}
			if(color==c)
			{
				for(i=minx;i<maxx;i++)
				{
					for(j=miny;j<maxy;j++)
					{
						a[i][j]=1;
					}
				}
			}
			else
			{
				for(i=minx;i<maxx;i++)
				{
					for(j=miny;j<maxy;j++)
					{
						a[i][j]=0;
					}
				}
			}
		}
		for(i=0;i<200;i++)
		{
			for(j=0;j<200;j++)
				if(a[i][j]==1) sum++;
		}
		printf("The area of color %d in dataset %d is: %d\n",c,l++,sum);
	}
	return 0;
}

