#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define maxn 1010

int n , m;
struct word
{
	char s[20];
	int v;
} list[maxn];

void read_dict()
{
	scanf("%d%d" , &n , &m);
	for(int i=0; i<n; i++)
	{
		scanf("%s%d" , list[i].s , &list[i].v);
	}	
}

int cmp(const void* a , const void* b)
{
	return strcmp(((word*)a)->s , ((word*)b)->s);
}

int b_search(char* s)
{
	int p = 0 , r = n - 1 , m , k;
	while(p <= r)
	{
		m = (p + r) >> 1;
		k = strcmp(s , list[m].s);
		if(k == 0) return list[m].v;
		if(k < 0) r = m - 1;
		else p = m + 1;
	}
	return 0;
}

void solve()
{
	qsort((void*)list , n , sizeof(word) , cmp);
	char s[50];
	int ret;
	for(int i=0; i<m; i++)
	{
		ret = 0;
		while(1)
		{
			scanf("%s" , s);
			if(s[0] == '.') break;
			ret += b_search(s);
		}
		printf("%d\n" , ret);
	}
}

int main()
{
	freopen("in.txt" , "r" , stdin);

	read_dict();
	solve();

	return 0;
}