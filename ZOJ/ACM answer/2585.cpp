#include <iostream>
#include <cmath>

int main()
{
	int a[26];
	int b[26];
	int i;
	char s[50];
	int cas,casnum;
	scanf("%d%*c",&cas);
	casnum=cas;
	while(cas--)
	{
		gets(s);
		memset(a,0,sizeof(a));
		for(i=0;i<strlen(s);i++)
		{
			a[s[i]-97]++;
		}
		gets(s);
		memset(b,0,sizeof(b));
		for(i=0;i<strlen(s);i++)
		{
			b[s[i]-97]++;
		}
		int result=0;
		for(i=0;i<26;i++)
		{
			result+=fabs(a[i]-b[i]);
		}
		printf("Case #%d:  %d\n",casnum-cas,result);
	}
	return 0;
}