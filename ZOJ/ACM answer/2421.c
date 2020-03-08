#include <stdio.h>
bool a[4000000];
int b[500001];
int main()
{
	int i,n,t;
	a[0]=true;
	for(i=1;i<=500000;i++)
	{
		t=b[i-1]-i;
		if(t<=0) 
		{
			t=b[i-1]+i;
		}
		else if(a[t]==true)
		{
			t=b[i-1]+i;
		}
		b[i]=t;a[b[i]]=true;
	}
	while(1)
	{
		scanf("%d",&n);
		if(n==-1) break;
		printf("%d\n",b[n]);
	}
	return 0;
}

