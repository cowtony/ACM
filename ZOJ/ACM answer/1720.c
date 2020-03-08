#include <stdio.h>
#include <math.h>
int main()
{
	int a[9];
	int i,j,p;
	while(1)
	{
		p=0;
		if(scanf("%d",&a[0])==EOF) break;
		for(i=1;i<9;i++)
		{
			scanf("%d",&a[i]);
		}
		for(i=0;i<9;i++)
		{
			if(a[i]!=0) {p=1;break;}
		}
		if(p==0) {printf("0\n");continue;}
		for(j=i;j<9;j++)
		{
			if(a[j]==0) continue;
			if(j!=i) printf(" ");
			if(a[j]<fabs(a[j])) printf("-");
			else if(j!=i) printf("+");
			if(j!=i) printf(" ");
			if(a[j]!=-1&&a[j]!=1)
			{
				printf("%.f",fabs(a[j]));
				if(j<7)
				{
					printf("x^%d",8-j);
				}
				else if(j==7)
					printf("x");
			}
			else
			{
				if(j<7)
				{
					printf("x^%d",8-j);
				}
				else if(j==7)
					printf("x");
				if(j==8) printf("%.f",fabs(a[j]));
			}
		}
		printf("\n");
	}
	return 0;
}
