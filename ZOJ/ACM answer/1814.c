#include <stdio.h>
int main()
{
	int a[2000];
	int i,j,t,p;
	int num;
	while(1)
	{
		scanf("%d",&num);
		if(num==0) break;
		for(i=0;i<num;i++)
		{
			scanf("%d",&a[i]);
		}
		for(i=1;;i++)
		{
			p=0;
			for(j=0;j<num;j++)
			{
				t=a[j]/2;
				a[j]=t+p;
				if(a[j]%2!=0&&j!=0) a[j]++;
				p=t;
			}
			a[0]+=p;
			if(a[0]%2!=0) a[0]++;
			for(j=1;j<num;j++)
			{
				if(a[0]!=a[j]) break;
			}
			if(j==num) break;
		}
		printf("%d %d\n",i,a[0]);
	}
	return 0;
}
