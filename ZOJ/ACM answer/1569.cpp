//127097 2003-04-18 13:06:19 Accepted 1569 C++ 00:00.04 400K just for play 
#include<stdio.h>
#include<string.h>

int main()
{
	int left[5001];
	int n,m;
	while(scanf("%d%d",&n,&m)!=EOF)
	{
		if(n==0&&m==0)	break;
		memset(left,0,sizeof(left));
		int i;int tsum=0;
		left[0]=1;int tt;int total=0;
		for(i=0;i<n;i++)
		{
			scanf("%d",&tt);
			tsum+=tt;
			tsum%=m;
			left[tsum]++;
			total+=left[tsum]-1;
		}
		printf("%d\n",total);
	}
	return 0;
}

