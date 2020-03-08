#include <stdio.h>
#include <string.h>

char list[20][20];
char s[20];
int p;

bool prefix(int p)
{
	int i;	
	for(i=0; i<=p; i++)
	{
		if(!s[i]) return 0;
		if(s[i] != list[p][i]) return 0;
	}
	return 1;
}

void solve()
{
	int p = -1;
	int i;
	int line = 0;
	while(1)
	{
		line++;
		if(gets(s) == NULL) break;
		if(strcmp(s , "") == 0) break;

		while(p >= 0 && !prefix(p))
		{
			p--;
		}

		p++;
		for(i=0; i<p; i++) putchar(' ');		
		printf("%s\n" , s);
		strcpy(list[p] , s);
	}
}

int main()
{
	//freopen("in.txt" , "r" , stdin);
	//freopen("out.txt" , "w" , stdout);

	int T;
	char buf[10];
	scanf("%d" , &T);
	gets(buf); gets(buf);

	while(T)
	{
		solve();
		T--;
		if(T) putchar('\n');
	}	 
	
	return 0;
}
