#include <stdio.h>
int main()
{
	int a[5000];
	int i,j;
	long num,count;
	int n;
	while(1)
	{
		if(scanf("%d",&n)==EOF) break;
		for(i=0;i<n;i++)
		{
			scanf("%d",&a[i]);
		}
		count=0;
		for(i=0;i<n-1;i++)
		{
			for(j=i+1;j<n;j++)
			{
				if(a[i]>a[j]) count++;
			}
		}
		num=count;
		for(i=0;i<n;i++)
		{
			num+=(n-2*a[i]-1);
			if(num<count) count=num;
		}
		printf("%ld\n",count);
	}
	return 0;
}

