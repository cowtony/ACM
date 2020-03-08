#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int n , m , mp;

struct dat
{
	char name[35];
	int p;
} list[50010];

struct stn
{
	int a , st , ed;
} p[2510];

int mark[32800] , value[5010] , f[5010], cnt;

int cmp(const void* a , const void* b)
{
	return strcmp( ((dat *)a)->name , ((dat *)b)->name );
}

int find_name(char* s)
{
	int p , r , k , ret;

	p = 0; r = n - 1;
	while(p <= r)
	{
		k = (p + r) >> 1;
		ret = strcmp(list[k].name , s);
		if(ret == 0) return k;
		if(ret < 0) p = k + 1;
		else r = k - 1;
	}
////////////////IMPOSSIBLE
	while(1)
	{
	}
}

void read_name(char* s)
{
	char ch;
	int l = 0;	

	ch = getchar();
	while(ch != '[') ch = getchar();

	while(1)
	{
		ch = getchar(); if(ch == ']') break;
		s[l++] = ch;
	}
	s[l] = 0;
}

void init()
{
	memset(mark , 0 , sizeof(mark));
	char buf[35];
	int i;

	for(i=0; i<m; i++)
	{
		read_name(buf);
		p[i].a = list[find_name(buf)].p;
		scanf("%d %d" , &p[i].st , &p[i].ed);
		mark[p[i].st] = mark[p[i].ed] = 1;
	}

	cnt = 0;
	for(i=0; i<=32768; i++)	
	{
		if(!mark[i]) continue;
		mark[i] = cnt;
		value[cnt++] = i;
	}
}

void solve()
{
	memset(f , 0 , sizeof(f));

	int i , j;
	for(i=0; i<m; i++)
	{
		for(j=mark[p[i].st]; j<=mark[p[i].ed]; j++)
		{
			f[j] += p[i].a;
		}
	}

	int max = 0;

	for(i=0; i<cnt; i++)
	{
		if(f[i] > mp)
		{
			printf("The power will be out at time %d because the power is %d Watts and overloaded.\n" , value[i] , f[i]);
			return;
		}
		max = max > f[i] ? max : f[i];
	}

	printf("The maximum power needed is %d Watts.\n" , max);
}

int main(){
//	freopen("in.txt" , "r" , stdin);

	scanf("%d" , &n);
	int i;

	for(i=0; i<n; i++)
	{
		read_name(list[i].name);
		scanf("%d" , &list[i].p);
	}

	qsort((void *)list , n , sizeof(dat) , cmp);

	while(scanf("%d%d" , &m , &mp) > 0)
	{
		init();
		solve();
	}
	
	return 0;
}
