#include <stdio.h>
#include <string.h>

#define maxn 10010

int n , st , ed;
struct music
{
	char title[11] , author[11];
} list[maxn];

int f[maxn][2];
struct{
	short v;
	char stat;
} Q[maxn * 2 + 10];

void init()
{
	scanf("%d%d" , &st , &ed);
	st-- , ed--;
	memset(list , 0 , sizeof(list));
	for(int i=0; i<n; i++)
	{
		scanf("%s %s" , list[i].title , list[i].author);
	}
}

int c[256];
int p[maxn] , q[maxn];

void sort()
{
	int i , j;

	for(i=0; i<n; i++)
		p[i] = i;

	for(j=9; j>=0; j--)
	{
		memset(c , 0 , sizeof(c));
		for(i=0; i<n; i++)
			c[list[i].author[j]]++;
		for(i=1; i<256; i++)
			c[i] += c[i-1];

		for(i=n-1; i>=0; i--)
		{
			q[--c[list[p[i]].author[j]]] = p[i];
		}
		memcpy(p , q , sizeof(p));
	}

	for(i=0; i<n; i++)
		q[p[i]] = i;
}

int head , tail;

bool push(int v , int stat , int len)
{
	++tail;
	Q[tail].v = v; Q[tail].stat = stat;
	f[v][stat] = len;

	if(v == ed){
		printf("%d\n" , len);
		return 1;
	}
	return 0;
}

inline int prev(int a)
{
	return a == 0 ? n - 1 : a - 1;
}

inline int next(int a)
{
	return a == n - 1 ? 0 : a + 1;
}

void solve()
{
	memset(f , 0xff , sizeof(f));
	f[st][0] = 0;
	
	head = tail = 0;
	Q[0].v = st; Q[0].stat = 0;

	if(st == ed){
		puts("0");
		return;
	}

	int v , stat , len;

	while(head <= tail)
	{
		v = Q[head].v; stat = Q[head].stat; len = f[v][stat]; head++;

		if(f[v][1-stat] < 0)
		{
			if(push(v , 1 - stat , len + 1)) return;
		}

		if(stat == 0)
		{
			if(f[prev(v)][stat] < 0)
			{
				if(push(prev(v) , stat , len + 1)) return;
			}
			if(f[next(v)][stat] < 0)
			{
				if(push(next(v) , stat , len + 1)) return;
			}
		}
		else{
			if(f[p[prev(q[v])]][stat] < 0)
			{
				if(push(p[prev(q[v])] , stat , len + 1)) return;
			}
			if(f[p[next(q[v])]][stat] < 0)
			{
				if(push(p[next(q[v])] , stat , len + 1)) return;
			}
		}
	}
}

int main()
{
//	freopen("in.txt" , "r" , stdin);

	while(scanf("%d" , &n) > 0)
	{
		init();
		sort();
		solve();
	}
	return 0;
}
