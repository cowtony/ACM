#include <stdio.h>
#include <math.h>
int main()
{
	int a[210000];
	int i,j,p,t;
	for(i=0;;i++)
	{
		scanf("%d",&a[i]);
		if(a[i]==5280) break;
	}
	p=0;
	for(j=0;j<i-1;j++)
	{
		if(p==0)
		{
			t=a[j];
			printf("Moving from 0 to %d: ",a[j+1]);
			if(a[j+1]==t) {j++;printf("found it!\n");if(i!=j+1) printf("\n");}
			else
			{
				if(fabs(t)>fabs(a[j+1]-t)) printf("warmer.\n");
				else if(fabs(t)<fabs(a[j+1]-t)) printf("colder.\n");
				else printf("same.\n");
				p=1;
			}
		}
		else 
		{
			printf("Moving from %d to %d: ",a[j],a[j+1]);
			if(a[j+1]==t)  {j++;p=0;printf("found it!\n");if(i!=j+1) printf("\n");}
			else
			{
				if(fabs(a[j]-t)>fabs(a[j+1]-t)) printf("warmer.\n");
				else if(fabs(a[j]-t)<fabs(a[j+1]-t)) printf("colder.\n");
				else printf("same.\n");
			}
		}
	}
	return 0;
}