//473965 2004-02-17 20:14:06 Time Limit Exceeded 1986 C++ 00:01.00 716K just for play 
//473966 2004-02-17 20:15:05 Accepted 1986 C++ 00:00.25 696K just for play 
#include<stdio.h>
#include<string.h>
 
int min[40001];

int  bin_search(int cur,int from,int to)
{
	if(from==to&&min[from]<cur)	return from;
	int mid=(from+to+1)/2;
	if(min[mid]==-1)	return bin_search(cur,from,mid-1);
	if(cur>min[mid])	return bin_search(cur,mid,to);
	else	return bin_search(cur,from,mid-1);
}

int main()
{
//	freopen("1986.in","r",stdin);
	int n;
	scanf("%d",&n);
	while(n--)
	{
		int p,i;
		scanf("%d",&p);
		int num[40001];
		for(i=1;i<=p;i++)
			scanf("%d",&num[i]);
		memset(min,0xff,sizeof(min));
		min[0]=0;

		for(i=1;i<=p;i++)
		{
			int pt=bin_search(num[i],0,i-1);
			if(min[pt+1]==-1||min[pt+1]>num[i])
			{
				min[pt+1]=num[i];
				
			}
		}
		for(i=1;i<=p;i++)
			if(min[i]==-1)	break;
		printf("%d\n",i-1);
	}
	return 0;
}
	