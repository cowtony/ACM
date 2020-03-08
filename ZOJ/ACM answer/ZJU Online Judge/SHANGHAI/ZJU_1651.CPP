#include <stdio.h>
#include <string.h>

int n;

struct part{
	int st , ed , p;
} list[16];

int f[1<<16];
char prev[1<<16];

void init()
{
	for(int i=0; i<n; i++)
	{
		scanf("%d%d" , &list[i].p , &list[i].ed);
		list[i].st = list[i].ed - list[i].p;
	}
}

inline int max(int a , int b)
{
	return a > b ? a : b;
}

void search(int time , int stat , int cost)
{		
	for(char i=0; i<n; i++)
		if((stat ^ (1<<i)) && (f[ stat | (1<<i) ] < 0 || f[ stat | (1<<i) ] > cost + max(0 , time - list[i].st)))
		{
			f[ stat | (1<<i) ] = cost + max(0 , time - list[i].st); prev[ stat | (1<<i) ] = i;
			search(time + list[i].p , stat | (1<<i) , cost + max(0 , time - list[i].st));
		}
}

int cnt;
char route[20];

void path(int stat)
{
	if(stat)
	{
		path(stat ^ (1<<prev[stat]));
		route[cnt++] = prev[stat] + 1;
	}
}

void solve()
{
	memset(f , 0xff , sizeof(f));
	memset(prev,  0xff , sizeof(prev));

	search(0 , 0 , 0);
	printf("%d\n" , f[(1<<n)-1]);
	cnt = 0;
	path((1<<n)-1);

	for(int i=0; i<n; i++)
	{
		if(i) putchar(' ');
		printf("%d" , route[i]);
	}
	putchar('\n');
}

int main()
{
//	freopen("in.txt" , "r" , stdin);

	while(scanf("%d" , &n) > 0)
	{
		init();
		solve();
	}
	
	return 0;
}
