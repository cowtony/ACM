#include <stdio.h>
#include <string.h>
int main()
{
	long n,m;
	int a,b;
	int i;
	int p=0;
	float count[101][2];
	char s1[9],s2[9];
	while(1)
	{
		scanf("%ld",&n);
		if(n==0) break;
		scanf("%ld",&m);
		if(p==1) printf("\n");
		else p=1;
		for(i=1;i<=n;i++)
		{
			count[i][0]=0;
			count[i][1]=0;
		}
		m=m*n*(n-1)/2;
		for(i=0;i<m;i++)
		{
			scanf("%d %s %d %s",&a,s1,&b,s2);
			if(strcmp(s1,"paper")==0)
			{
				if(strcmp(s2,"rock")==0) {count[a][0]+=1.0;count[b][1]+=1.0;}
				else if(strcmp(s2,"scissors")==0) {count[a][1]+=1.0;count[b][0]+=1.0;}
			}
			else if(strcmp(s1,"scissors")==0)
			{
				if(strcmp(s2,"paper")==0) {count[a][0]+=1.0;count[b][1]+=1.0;}
				else if(strcmp(s2,"rock")==0) {count[a][1]+=1.0;count[b][0]+=1.0;}
			}
			else if(strcmp(s1,"rock")==0)
			{
				if(strcmp(s2,"scissors")==0) {count[a][0]+=1.0;count[b][1]+=1.0;}
				else if(strcmp(s2,"paper")==0) {count[a][1]+=1.0;count[b][0]+=1.0;}
			}
		}
		for(i=1;i<=n;i++)
		{
			if(count[i][0]+count[i][1]<10e-6) printf("-\n");
			else printf("%.3f\n",count[i][0]/(count[i][0]+count[i][1]));
		}
	}
	return 0;
}
