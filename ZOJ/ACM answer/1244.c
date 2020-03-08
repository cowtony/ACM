#include <stdio.h>
int main()
{
	char a[500][26];
	char c1,c2;
	int n;
	int i,j;
	int l=0,p;
	while(1)
	{
		a[l][0]='a';
		for(i=1;i<26;i++)
		{
			a[l][i]='0';
		}
		scanf("%d%*c",&n);
		if(n==0) break;
		for(i=0;i<n;i++)
		{
			scanf("%c = %c%*c",&c1,&c2);
			if(a[l][c2-97]=='0') a[l][c1-97]='0';
			else a[l][c1-97]=c1;
		}
		l++;
	}
	for(i=0;i<l;i++)
	{
		printf("Program #%d\n",i+1);
		p=0;
		for(j=0;j<26;j++)
		{
			if(a[i][j]!='0') {p=1;printf("%c ",a[i][j]);}
		}
		if(p==0) printf("none");
		printf("\n\n");
	}
	return 0;
}

