#include <stdio.h>
#include <string.h>

int p , t;
int g[110][5];

int calc()
{
	int cnt = 0;
	int i , j;
	for(i=0; i<p; i++)
	{
		for(j=0; j<i; j++)
		{
			if(g[i][0] == g[j][0] &&
			   g[i][1] == g[j][1] &&
			   g[i][2] == g[j][2] &&
			   g[i][3] == g[j][3]) break;
		}
		if(j >= i) cnt++;
	}
	return cnt;
}

int main()
{
	//freopen("in.txt" , "r" , stdin);

	char buf[100];
	int a , b;

	while(scanf("%d %d\n" , &p , &t) > 0)
	{
		memset(g , 0 , sizeof(g));
		while(1)
		{
			if(gets(buf) <= 0) break;
			if(strlen(buf) == 0) break;
			sscanf(buf , "%d%d" , &a , &b);
			a-- , b--;
			g[a][b/25] |= (1<<(b % 25));
		}

		printf("%d\n" , calc());
	}
	
	return 0;
}
