#include <stdio.h>
int main()
{
	int i,j,k;
	int n;
	while(scanf("%d",&n)!=EOF)
	{
		for(i=0;i<n;i++)
		{
			for(j=0;j<i;j++)
			{
				printf("0 ");
			}
			printf("%d",i);
			for(k=i+1;k<n;k++)
			{
				printf(" %d",i);
			}
			printf("\n");
		}
		printf("\n");
	}
	return 0;
}
