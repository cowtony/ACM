#include <stdio.h>
#include <string.h>

int N;
char city[200][12];
int g[200][200];
int low[200][2];

int st , ed , m;

int find_city(char* str)
{
	for(int i=0; i<N; i++)
		if(strcmp(str , city[i]) == 0) return i;
	strcpy(city[N] , str);
	N++;
	return N - 1;
}

void solve()
{
	memset(low , 0xff , sizeof(low));
	low[st][0] = 0;

	int i , j , k , min , stat; 
	while(1)
	{
		min = 100000000;
		for(i=0; i<N; i++)
			for(j=0; j<2; j++)
				if(low[i][j] >= 0 && low[i][j] < min)
				{
					min = low[i][j];
					k = i;
					stat = j;
				}
		
		if(k == ed)
		{
			printf("%d\n" , min);
			return;
		}

		low[k][stat] = -2;
		
		for(i=0; i<N; i++)
			if(g[k][i] >= 0)
			{
				if(low[i][stat] == -1 || min + g[k][i] < low[i][stat])
					low[i][stat] = min + g[k][i];
				if(stat == 0)
				{
					if(low[i][1] == -1 || min < low[i][1])
						low[i][1] = min;
				}
			}		
	}
}

int main()
{
//	freopen("in.txt" , "r" , stdin);

	char buf[12];
	int a , b , cost;

	while(scanf("%s" , buf) > 0)
	{
		N = 0;
		st = find_city(buf);
		scanf("%s" , buf); ed = find_city(buf);
		scanf("%d" , &m);

		memset(g , 0xff , sizeof(g));

		while(m--)
		{
			scanf("%s" , buf); a = find_city(buf);
			scanf("%s" , buf); b = find_city(buf);
			scanf("%d" , &cost);

			if(g[a][b] < 0 || cost < g[a][b]) g[a][b] = g[b][a] = cost;
		}

		solve();
	}
	
	return 0;
}
