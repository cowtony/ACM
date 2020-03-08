//88342 2003-03-14 12:25:32 Time Limit Exceeded 1538 C++ 00:01.00 672K Century Ghost 
//88367 2003-03-14 12:53:36 Wrong Answer 1538 C++ 00:00.38 672K Century Ghost 
//88792 2003-03-14 22:39:41 Accepted 1538 C++ 00:00.11 620K Century Ghost 
#include<stdio.h>

long num[61100];
long n;

		
int main()
{
	long i;
	
	while(scanf("%ld",&n)!=EOF)
	{
		for(i=0;i<n;i++)	scanf("%ld",&num[i]);
		long pt=0;
		for(i=1;i<=n;i++)
		{	if(num[pt]==n)	break;
			pt=(pt+num[pt])%n;	
		}
		printf("%ld\n",num[pt]);	
	}
	return 0;
}